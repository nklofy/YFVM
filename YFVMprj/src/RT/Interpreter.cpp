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
		case "AND":
			doAND();
			break;
		case "OR":
			doOR();
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
		addr2=this->global_vars[opd2];
		addr3=this->global_vars[opd3];
	}else{
		//get addr2 from opd2
		if(this->local_vars->find(opd2)){
			addr2=(*(this->local_vars))[opd2]+this->ebp;
		}else if(this->global_vars.find(opd2)){
			addr2=this->global_vars[opd2];
		}else{
			cerr<<"not find symbol name "<<opd2<<endl;
		}
		//get addr3 from opd3
		if(this->local_vars->find(opd3)){
			addr3=(*(this->local_vars))[opd3]+this->ebp;
		}else if(this->global_vars.find(opd3)){
			addr3=this->global_vars[opd3];
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
	}else if(opd1=="string"&&r3.valuek!=vk_ptr){
		string tgs;
		if(r3.valuek==vk_int){
			tgs=to_string(r3.value.int_value);
		}else if(r3.valuek==vk_double){
			tgs=to_string(r3.value.double_value);
		}
		//new string obj
		//set r2's ptr
		long addr=mem->allocStr(tgs.size());
		mem->cpyStr(addr,tgs);
		if(r2.isLeft){
			long addr2=r2.value.ptr_value;
			InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			p->value.value.ptr_value=addr;
		}else{
			r2.value.ptr_value=addr;
		}
	}else{	//ptr assign to ptr
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
	string& opd2=code->getOpd2();
	string& opd1=code->getOpd1();
	long addr=mem->allocStr(opd2.size());
	mem->cpyStr(addr,opd2);
	RRValue v;
	v.ptr_value=addr;
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

int Interpreter::doCmp(){
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	if(v2.isLeft&&v3.isLeft){
		long p2=v2.value.ptr_value;
		long p3=v3.value.ptr_value;
		return cmp2Addr(p2,p3);
	}else if(v2.isLeft){
		long p2=v2.value.ptr_value;
		return cmp2Addr(p2,a3);
	}else if(v3.isLeft){
		long p3=v3.value.ptr_value;
		return cmp2Addr(a2,p3);
	}else{
		return cmp2Addr(a2,a3);
	}

}

int Interpreter::cmp2Addr(long a2, long a3) {//0 EQ, 1 larger, -1 less
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);

	if(v2.valuek==vk_int&&v3.valuek==vk_int){
		int r2=v2.value.int_value,r3=v3.value.int_value;
		if(r2<r3) return -1;
		else if(r2==r3) return 0;
		else return 1;
	}else if(v2.valuek==vk_int&&v3.valuek==vk_double){
		int r2=v2.value.int_value;
		double r3=v3.value.double_value;
		if(r2<r3) return -1;
		else if(r2==r3) return 0;
		else return 1;
	}else if(v2.valuek==vk_double&&v3.valuek==vk_int){
		double r2=v2.value.double_value;
		int r3=v3.value.int_value;
		if(r2<r3) return -1;
		else if(r2==r3) return 0;
		else return 1;
	}else if(v2.valuek==vk_double&&v3.valuek==vk_double){
		double r2=v2.value.double_value;
		double r3=v3.value.double_value;
		if(r2<r3) return -1;
		else if(r2==r3) return 0;
		else return 1;
	}else{
		//leaving for operator overload
	}
	return 0;
}

long Interpreter::getSbAddr(string& name) {
	int addr=-1;
	if(ebp==0){
		addr=this->global_vars[name];
		return addr;
	}
	if(this->local_vars->find(name)){
		addr=(*(this->local_vars))[name]+this->ebp;
	}else if(this->global_vars.find(name)){
		addr=this->global_vars[name];
	}else{
		cerr<<"not find symbol name "<<name<<endl;
	}

}

void Interpreter::addVarStack(ValueK& k,RRValue& v,string& name){
	long tos=mem->pushStack(k,v);
	if(ebp==0){
		(this->global_vars)[name]=tos;
	}else{
		long tpi=mem->fetchStack(ebp);  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->typelist)[tpi]);
		if(!f->sym_inner.find(name)){
			f->sym_inner[name]=tos-ebp;
		}
	}
}

void Interpreter::doGT() {
	string& opd1=code->getOpd1();
	int b=doCmp();
	if(b==1){
		/*
	RRValue v;
	v.int_value=vi;
	*/
	}
}

void Interpreter::doLT() {

}

void Interpreter::doGE() {

}

void Interpreter::doLE() {

}

void Interpreter::doEQ() {

}

void Interpreter::doNE() {
}

void Interpreter::doAND() {
}

void Interpreter::doOR() {
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

void Interpreter::doGetClass() {
}
