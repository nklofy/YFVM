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
	AbstType* type1=stcz->typelist[stcz->type_tbl[opd1]];
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
	DatValue& r2=mem->fetchStack(addr2);
	DatValue& r3=mem->fetchStack(addr3);
	//deal with type auto conversion and l/r value
	if(r3.valuek==vk_double&&opd1!="double"){	//mov int a b
		long mv=(long)r3.value.double_value;
		if(r2.isLeft){
			long addr2=r2.value.ptr_value;
			InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			p->value.value.int_value=mv;
		}else{
			r2.value.int_value=mv;
		}
	}else if(opd1=="double"&&r3.valuek!=vk_double){	//mov double a b
		double mv=(double)r3.value.int_value;
		if(r2.isLeft){
			long addr2=r2.value.ptr_value;
			InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			p->value.value.double_value=mv;
		}else{
			r2.value.double_value=mv;
		}
	}else if(opd1=="string"){
		if(r3.valuek==vk_int){
			string tgs=to_string(r3.value.int_value);
			if(r2.isLeft){

			}else{
				if(stcz->getCnstPlMap().find(tgs)){

				}else{

				}
			}
		}else if(r3.valuek==vk_double){
			string tgs=to_string(r3.value.double_value);
			if(r2.isLeft){

			}else{

			}
		}
	}else{
		if(r2.isLeft){
			long addr2=r2.value.ptr_value;
			InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			p->value.value=r3.value;
		}else{
			r2.value=r3.value;
		}
	}
}

void Interpreter::doLoadi() {
	string& opd1=code->getOpd1();
	long vi=stol(code->getOpd2());
	RRValue v;
	v.int_value=vi;
	long tos=mem->pushStack(vk_int,v);

	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		long tpi=mem->fetchStack(ebp);  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(opd1)){
			f->sym_inner[opd1]=tos-ebp;
		}
	}
}

void Interpreter::doLoadd() {
	string& opd1=code->getOpd1();
	double vd=stod(code->getOpd2());
	RRValue v;
	v.double_value=vd;
	long tos=mem->pushStack(vk_double,v);
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		long tpi=mem->fetchStack(ebp);
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(opd1)){
			f->sym_inner[opd1]=tos-ebp;
		}
	}
}

void Interpreter::doLoads() {
	string& opd1=code->getOpd1();
	AbstClass* t=dynamic_cast<AbstClass*>(stcz->getTypelist()[stcz->getTypeTbl()["string"]]);


	string& opd1=code->getOpd1();
	string& tgs=opd1.substr(1,opd1.length()-1);
	long vi;
	auto cmp=&(stcz->getCnstPlMap());
	auto cls=&(stcz->getCnstplList());
	if(cmp->find(tgs)){
		vi=(*cmp)[tgs];
	}else{
		cls->push_back(tgs);
		vi=cls->size()-1;
		cmp[tgs]=vi;
	}
	RRValue v;
	v.ptr_value=vi;
	long tos=mem->pushStack(vk_ptr,v);
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		long tpi=mem->fetchStack(ebp);  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(opd1)){
			f->sym_inner[opd1]=tos-ebp;
		}
	}

}

void Interpreter::doLoadc() {
	string& opd1=code->getOpd1();
	long vi=(code->getOpd2()).at(0);
	RRValue v;
	v.int_value=vi;
	long tos=mem->pushStack(vk_int,v);
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		long tpi=mem->fetchStack(ebp);  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(opd1)){
			f->sym_inner[opd1]=tos-ebp;
		}
	}
}

void Interpreter::doLoadb() {
	string& opd1=code->getOpd1();
	long vi=code->getOpd2()=="true"?1:0;
	RRValue v;
	v.int_value=vi;
	long tos=mem->pushStack(vk_int,v);
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		long tpi=mem->fetchStack(ebp);  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(opd1)){
			f->sym_inner[opd1]=tos-ebp;
		}
	}
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
