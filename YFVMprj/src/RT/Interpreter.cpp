/*
 * Interpreter.cpp`
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#include "Interpreter.h"

Interpreter::Interpreter() {
	// TODO Auto-generated constructor stub

}

Interpreter::~Interpreter() {
	// TODO Auto-generated destructor stub
}

int Interpreter::doInterpret(StaticZone* stcz, MemManager* mem, IOManager* io) {
	this->stcz=stcz;
	this->mem=mem;
	this->io=io;
	while(true){
		this->code=(stcz->getCodes())[pc];
		switch(this->code->getOpt()){//in future, use ptr array to deal with distribution
		case "mov":
			doMov();
			break;
		case "load_i":
			doLoadi();
			break;
		case "load_d":
			doLoadd();
			break;
		case "load_s":
			doLoads();
			break;
		case "load_c":
			doLoadc();
			break;
		case "load_b":
			doLoadb();
			break;


			////////////////////////////////////
		case "GT":
			doGT();
			break;
		case "LT":
			doLT();
			break;
		case "GE":
			doGE();

			break;
		case "LE":
			doLE();
			break;
		case "NE":
			doNE();
			break;
		case "EQ":
			doEQ();
			break;
		case "NOT":
			doNT();
			break;
		case "sub_i":
			doSubi();
			break;
		case "sub_d":
			doSubd();
			break;
		case "add_i":
			doAddi();
			break;
		case "add_d":
			doAddd();
			break;
		case "mul_i":
			doMuli();
			break;
		case "mul_d":
			doMuld();
			break;
		case "div_i":
			doDivi();

		break;
		case "div_d":doDivd();


			break;
		case "inc_1":doInc1();


			break;
		case "dec_1":doDec1();


			break;

			//////////////////////
		case "if":doIf();


			break;
		case "while":doWhile();


			break;
		case "goto":doGoto();


			break;
		case "retExp":doRetExp();


			break;
		case "ret":doRet();


			break;
		case "defFunction":doDefFunc();


			break;
		case "end":doEnd();


			break;
		case "getFunc":doGetFunc();


			break;
		case "pushTypeArg":doPushTypeArg();


			break;
		case "pushFuncArg":doPushFuncArg();


			break;
		case "invoke":doInvoke();


			break;

			/////////////////////////////
		case "defClass":doDefClass();


			break;
		case "defInterface":doDefIntf();


			break;
		case "extends":doExtd();


			break;
		case "impliments":doImpl();


			break;
		case "Fields":doFields();


			break;
		case "defField":doDefFld();


			break;
		case "Methods":doMethods();


			break;
		case "defMethod":doDefMthd();


			break;
		case "defGnrcPar":doDefGnrcPar();


			break;
		case "defFuncPar":doDefFuncPar();


			break;
		case "newArr":doNewArr();


			break;
		case "newObj":doNewObj();


			break;
		case "defLambdaExp":doDefLmbdExp();


			break;
		case "getFuncObj":doGetFuncObj();


			break;
		case "getMethod":doGetMthd();


			break;
		case "getArray":doGetArr();


			break;
		case "getField":doGetFld();


			break;
		case "getClass":doGetClass();

			break;

		default:
			break;
		}
	}
	return 0;
}

void Interpreter::doMov() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	TType* type1=stcz->typelist[stcz->type_tbl[opd1]];
	long addr2;
	long addr3;
	if(ebp==0){
		addr2=this->global_vars.find(opd2);
		addr3=this->global_vars.find(opd3);
	}else{
		//get addr2 from opd2
		if(this->local_vars->find(opd2)){
			addr2=this->local_vars->find(opd2)+this->ebp;
		}else if(this->global_vars.find(opd2)){
			addr2=this->global_vars.find(opd2);
		}else{
			cerr<<"not find symbol name "<<opd2<<endl;
		}
		//get addr3 from opd3
		if(this->local_vars->find(opd3)){
			addr3=this->local_vars->find(opd3)+this->ebp;
		}else if(this->global_vars.find(opd3)){
			addr3=this->global_vars.find(opd3);
		}else{
			cerr<<"not find symbol name "<<opd3<<endl;
		}
	}
	RValue& r2=mem->fetchStack(addr2);
	RValue& r3=mem->fetchStack(addr3);
	//deal with left value
	if(r2.isLeft){

	}else{

	}
	//deal with type auto conversion

/*
	if(this->local_vars->find(opd3)){
		addr3=this->local_vars->find(opd3)+this->ebp;
	}else if(){

	}else if(this->global_vars.find(opd3)){
	}
		addr3=this->global_vars.find(opd3);
	}else{
		//reserve for find symbol in class
	}
	RValue& r2=mem->fetchStack(addr2);
	RValue& r3=mem->fetchStack(addr3);
	if(opd1=="int"){

	}else if(opd1=="double"){

	}else if(opd1=="char"){

	}else if(opd1=="string"){

	}else if(opd1=="bool"){

	}else{

	}*/
}

void Interpreter::doLoadi() {
	TType* type=stcz->typelist[stcz->type_tbl["int"]];
	string& opd1=code->getOpd1();
	long vi=stol(code->getOpd2());
	RRValue v;
	v.int_value=vi;
	long tos=mem->pushStack(v_int,v);
	long tpi=mem->fetchStack(ebp);
	if(this->name_scope==scp_glb){
		(this->global_vars)[opd1]=tos;
	}else if(this->name_scope==scp_func){
		TFunc *f=dynamic_cast<TFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(opd1)){
			f->sym_inner[opd1]=tos-ebp;
		}
	}else if(this->name_scope==scp_mthd){
		TFunc *f=dynamic_cast<TFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(opd1)){
			f->sym_inner[opd1]=tos-ebp;
		}
	}
}

void Interpreter::doLoadd() {
}

void Interpreter::doLoads() {
}

void Interpreter::doLoadc() {
}

void Interpreter::doLoadb() {
}

void Interpreter::doGT() {
}

void Interpreter::doLT() {
}

void Interpreter::doLE() {
}

void Interpreter::doEQ() {
}

void Interpreter::doNT() {
}

void Interpreter::doSubi() {
}

void Interpreter::doSubd() {
}

void Interpreter::doAddi() {
}

void Interpreter::doAddd() {
}

void Interpreter::doMuli() {
}

void Interpreter::doMuld() {
}

void Interpreter::doDivi() {
}

void Interpreter::doDivd() {
}

void Interpreter::doInc1() {
}

void Interpreter::doDec1() {
}

void Interpreter::doIf() {
}

void Interpreter::doWhile() {
}

void Interpreter::doGoto() {
}

void Interpreter::doRetExp() {
}

void Interpreter::doRet() {
}

void Interpreter::doDefFunc() {
}

void Interpreter::doEnd() {
}

void Interpreter::doGetFunc() {
}

void Interpreter::doPushTypeArg() {
}

void Interpreter::doPushFuncArg() {
}

void Interpreter::doInvoke() {
}

void Interpreter::doDefClass() {
}

void Interpreter::doDefIntf() {
}

void Interpreter::doExtd() {
}

void Interpreter::doImpl() {
}

void Interpreter::doFields() {
}

void Interpreter::doDefFld() {
}

void Interpreter::doMethods() {
}

void Interpreter::doDefMthd() {
}

void Interpreter::doDefGnrcPar() {
}

void Interpreter::doDefFuncPar() {
}

void Interpreter::doNewArr() {
}

void Interpreter::doNewObj() {
}

void Interpreter::doDefLmbdExp() {
}

void Interpreter::doGetFuncObj() {
}

void Interpreter::doGetMthd() {
}

void Interpreter::doGetArr() {
}

void Interpreter::doGetFld() {
}

void Interpreter::doGE() {
}

void Interpreter::doGE() {
}

void Interpreter::doNE() {
}

void Interpreter::doGetClass() {
}
