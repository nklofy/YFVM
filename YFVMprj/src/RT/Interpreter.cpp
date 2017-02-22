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
		case "div_d":
			doDivd();
			break;
		case "inc_1":
			doInc1();
			break;
		case "dec_1":
			doDec1();
			break;

			//////////////////////
		case "if":
			doIf();
			break;
		case "while":
			doWhile();
			break;
		case "goto":
			doGoto();
			break;
		case "retExp":
			doRetExp();
			break;
		case "ret":
			doRet();
			break;
		case "defFunction":
			doDefFunc();
			break;
		case "end":
			doEnd();
			break;
		case "getFunc":
			doGetFunc();
			break;
		case "pushTypeArg":
			doPushTypeArg();
			break;
		case "pushFuncArg":
			doPushFuncArg();
			break;
		case "invoke":
			doInvoke();
			break;

			/////////////////////////////
		case "defClass":
			doDefClass();
			break;
		case "defInterface":
			doDefIntf();
			break;
		case "extends":
			doExtd();
			break;
		case "impliments":
			doImpl();
			break;
		case "Fields":
			doFields();
			break;
		case "defField":
			doDefFld();
			break;
		case "Methods":
			doMethods();
			break;
		case "defMethod":
			doDefMthd();
			break;
		case "defGnrcPar":
			doDefGnrcPar();
			break;
		case "defFuncPar":
			doDefFuncPar();
			break;
		case "newArr":
			doNewArr();
			break;
		case "newObj":
			doNewObj();
			break;
		case "defLambdaExp":
			doDefLmbdExp();
			break;
		case "getFuncObj":
			doGetFuncObj();
			break;
		case "getMethod":
			doGetMthd();
			break;
		case "getArray":
			doGetArr();
			break;
		case "getField":
			doGetFld();
			break;
		case "getClass":
			doGetClass();
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
		if(r2.valuek==vk_ptr){
			long addr2=r2.value.ptr_value;
			InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			p->value.value.int_value=mv;
		}else{
			r2.value.int_value=mv;
		}
	}else if(opd1=="double"&&r3.valuek!=vk_double){	//mov double a b
		double mv=(double)r3.value.int_value;
		if(r2.valuek==vk_ptr){
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
		if(r2.valuek==vk_ptr){
			long addr2=r2.value.ptr_value;
			InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			p->value.value.ptr_value=addr;
		}else{
			r2.value.ptr_value=addr;
		}
	}else{	//ptr assign to ptr
		if(r2.valuek==vk_ptr){
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
	if(v2.valuek==vk_ptr&&v3.valuek==vk_ptr){
		long p2=v2.value.ptr_value;
		long p3=v3.value.ptr_value;
		DatValue& v4=mem->fetchObj(p2);
		DatValue& v5=mem->fetchObj(p3);
		return cmp2Value(v4,v5);
	}else if(v2.valuek==vk_ptr){
		long p2=v2.value.ptr_value;
		DatValue& v4=mem->fetchObj(p2);
		return cmp2Value(v4,v3);
	}else if(v3.valuek==vk_ptr){
		long p3=v3.value.ptr_value;
		DatValue& v5=mem->fetchObj(p3);
		return cmp2Value(v2,v5);
	}else{
		return cmp2Value(v2,v3);
	}
}

int Interpreter::cmp2Value(DatValue& v2, DatValue& v3) {//0 EQ, 1 larger, -1 less

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
		//leave to operator overload
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

void Interpreter::addVarStack(ValueK k,RRValue& v,string& name){
	long tos=mem->pushStack(k,v);
	this->esp++;
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
	RRValue v;
	if(b==1){
		v.int_value=1;
		addVarStack(vk_int,v,opd1);
	}else{
		v.int_value=0;
		addVarStack(vk_int,v,opd1);
	}
}

void Interpreter::doLT() {
	string& opd1=code->getOpd1();
	int b=doCmp();
	RRValue v;
	if(b==-1){
		v.int_value=1;
		addVarStack(vk_int,v,opd1);
	}else{
		v.int_value=0;
		addVarStack(vk_int,v,opd1);
	}
}

void Interpreter::doGE() {
	string& opd1=code->getOpd1();
	int b=doCmp();
	RRValue v;
	if(b==-1){
		v.int_value=0;
		addVarStack(vk_int,v,opd1);
	}else{
		v.int_value=1;
		addVarStack(vk_int,v,opd1);
	}
}

void Interpreter::doLE() {
	string& opd1=code->getOpd1();
	int b=doCmp();
	RRValue v;
	if(b==1){
		v.int_value=0;
		addVarStack(vk_int,v,opd1);
	}else{
		v.int_value=1;
		addVarStack(vk_int,v,opd1);
	}
}

void Interpreter::doEQ() {
	string& opd1=code->getOpd1();
	int b=doCmp();
	RRValue v;
	if(b==0){
		v.int_value=1;
		addVarStack(vk_int,v,opd1);
	}else{
		v.int_value=0;
		addVarStack(vk_int,v,opd1);
	}
}

void Interpreter::doNE() {

	string& opd1=code->getOpd1();
	int b=doCmp();
	RRValue v;
	if(b==0){
		v.int_value=0;
		addVarStack(vk_int,v,opd1);
	}else{
		v.int_value=1;
		addVarStack(vk_int,v,opd1);
	}
}

void Interpreter::doAND() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	long i1=0,i2=0,i3=0;
	if(v2.valuek==vk_ptr&&v3.valuek==vk_ptr){
		long p2=v2.value.ptr_value;
		long p3=v3.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
	}else if(v2.valuek==vk_ptr){
		long p2=v2.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=v3.value.int_value;
	}else if(v3.valuek==vk_ptr){
		long p3=v3.value.ptr_value;
		long i3=((InstBasic*)(mem->fetchObj(p3)))->value.value.int_value;
		i2=v2.value.int_value;
	}else{
		long i2=v2.value.int_value;
		long i3=v2.value.int_value;
	}
	if(i2==1&&i3==1) i1=1;
	RRValue v;
	v.int_value=i1;
	this->addVarStack(vk_int,v,opd1);
}

void Interpreter::doOR() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	long i1=0,i2=0,i3=0;
	if(v2.valuek==vk_ptr&&v3.valuek==vk_ptr){
		long p2=v2.value.ptr_value;
		long p3=v3.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
	}else if(v2.valuek==vk_ptr){
		long p2=v2.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=v3.value.int_value;
	}else if(v3.valuek==vk_ptr){
		long p3=v3.value.ptr_value;
		long i3=((InstBasic*)(mem->fetchObj(p3)))->value.value.int_value;
		i2=v2.value.int_value;
	}else{
		long i2=v2.value.int_value;
		long i3=v2.value.int_value;
	}
	if(i2==1||i3==1) i1=1;
	RRValue v;
	v.int_value=i1;
	this->addVarStack(vk_int,v,opd1);
}
void Interpreter::doNT() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	long a2=getSbAddr(opd2);
	DatValue& v2=mem->fetchStack(a2);
	long i1=0,i2=0;
	if(v2.valuek==vk_ptr){
		long p2=v2.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
	}else{
		long i2=v2.value.int_value;
	}
	if(i2==1) i1=1;
	RRValue v;
	v.int_value=i1;
	this->addVarStack(vk_int,v,opd1);
}

DatValue& Interpreter::getPtrValue(long addr){
	return ((InstBasic*)(mem->fetchObj(addr)))->value;
}

long Interpreter::getIVDatV(DatValue& v){
	switch(v.valuek){
	case vk_int:
		return v.value.int_value;
		break;
	case vk_double:
		return v.value.double_value;
		break;
	case vk_ptr:
		return getIVDatV(getPtrValue(v.value.ptr_value));
		break;
	default:
		break;
	}
	return 0;
}

double Interpreter::getDVDatV(DatValue& v){
	switch(v.valuek){
	case vk_int:
		return v.value.int_value;
		break;
	case vk_double:
		return v.value.double_value;
		break;
	case vk_ptr:
		return getDVDatV(getPtrValue(v.value.ptr_value));
		break;
	default:
		break;
	}
	return 0;

}

void Interpreter::doSubi() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	long i2=getIVDatV(v2);
	long i3=getIVDatV(v3);
	RRValue v;
	v.int_value=i2-i3;
	this->addVarStack(vk_int,v,opd1);
}

void Interpreter::doSubd() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	double i2=getDVDatV(v2);
	double i3=getDVDatV(v3);
	RRValue v;
	v.int_value=i2-i3;
	this->addVarStack(vk_double,v,opd1);

}

void Interpreter::doAddi() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	long i2=getIVDatV(v2);
	long i3=getIVDatV(v3);
	RRValue v;
	v.int_value=i2+i3;
	this->addVarStack(vk_int,v,opd1);
}

void Interpreter::doAddd() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	double i2=getDVDatV(v2);
	double i3=getDVDatV(v3);
	RRValue v;
	v.int_value=i2+i3;
	this->addVarStack(vk_double,v,opd1);
}

void Interpreter::doMuli() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	long i2=getIVDatV(v2);
	long i3=getIVDatV(v3);
	RRValue v;
	v.int_value=i2*i3;
	this->addVarStack(vk_int,v,opd1);

}

void Interpreter::doMuld() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	double i2=getDVDatV(v2);
	double i3=getDVDatV(v3);
	RRValue v;
	v.int_value=i2*i3;
	this->addVarStack(vk_double,v,opd1);
}

void Interpreter::doDivi() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	long i2=getIVDatV(v2);
	long i3=getIVDatV(v3);
	if(i3==0) cerr<<"error divide by 0: "<<opd2<<" / "<<opd3<<endl;
	RRValue v;
	v.int_value=i2/i3;
	this->addVarStack(vk_int,v,opd1);

}

void Interpreter::doDivd() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	double i2=getDVDatV(v2);
	double i3=getDVDatV(v3);
	if(i3==0) cerr<<"error divide by 0: "<<opd2<<" / "<<opd3<<endl;
	RRValue v;
	v.int_value=i2/i3;
	this->addVarStack(vk_double,v,opd1);
}

void Interpreter::doInc1() {
	string& opd1=code->getOpd1();
	long a1=getSbAddr(opd1);
	DatValue& v1=mem->fetchStack(a1);
	double i1=getDVDatV(v1);
	DatValue& v=mem->fetchStack(a1);
	if(v.valuek==vk_ptr){
		DatValue& v2=this->getPtrValue(v.value.ptr_value);
		++v2.value.int_value;
	}else{
		++v.value.int_value;
	}
}

void Interpreter::doDec1() {
	string& opd1=code->getOpd1();
	long a1=getSbAddr(opd1);
	DatValue& v1=mem->fetchStack(a1);
	double i1=getDVDatV(v1);
	DatValue& v=mem->fetchStack(a1);
	if(v.valuek==vk_ptr){
		DatValue& v2=this->getPtrValue(v.value.ptr_value);
		--v2.value.int_value;
	}else{
		--v.value.int_value;
	}
}

void Interpreter::doIf() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=stol(opd2);
	long a3=stol(opd3);
	long p;
	DatValue& v=mem->fetchStack(getSbAddr(opd1));
	if(v.valuek==vk_ptr){
		p=this->getPtrValue(v.value.ptr_value);
	}else{
		p=v.value.int_value;
	}
	if(p==0){
		this->pc=a3;
	}else if(p==1){
		this->pc=a2;
	}
}

void Interpreter::doWhile() {	//actually, the same as if stmt. but keeping while info
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=stol(opd2);
	long a3=stol(opd3);
	long p;
	DatValue& v=mem->fetchStack(getSbAddr(opd1));
	if(v.valuek==vk_ptr){
		p=this->getPtrValue(v.value.ptr_value);
	}else{
		p=v.value.int_value;
	}
	if(p==0){
		this->pc=a3;
	}else if(p==1){
		this->pc=a2;
	}
}

void Interpreter::doGoto() {
	string& opd1=code->getOpd1();
	long a1=stol(opd1);
	long p;
	this->pc=a1;
}

void Interpreter::doRetExp() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	DatValue& oldv=mem->fetchStack(stol(opd2));
	ValueK k=oldv.valuek;
	RRValue v=oldv.value;
	doRet();
	this->addVarStack(k,v,opd2);
}

void Interpreter::doRet() {
	//return last frame
	this->esp=this->ebp-3;
	this->pc=mem->fetchStack(ebp-1).value.int_value;//return address
	this->ebp=mem->fetchStack(ebp-2).value.int_value;
	this->mem->setTopStack(esp);
}

void Interpreter::doDefFunc() {
	//lambda expression
}

void Interpreter::doEnd() {

}

void Interpreter::doGetFunc() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	auto ftb=stcz->getFuncTbl();
	auto flt=stcz->getFuncList();
	long i=ftb[opd1];
	AbstFunc* f=flt[i];
	if(f->isOverload){
		//
	}else{
		//
	}
	//new frame

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
