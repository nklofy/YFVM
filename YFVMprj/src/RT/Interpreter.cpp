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
	this->codes=stcz->getScript();
	while(true){
		this->code=((*this->codes)[pc++]);
		switch(this->stcz->getOptNum()[this->code->getOpt()]){//in future, use ptr array to deal with distribution
		//case "mov":
		case 0:
			doMov();
			break;
		//case "load_i":
		case 1:
			doLoadi();
			break;
		//case "load_d":
		case 2:
			doLoadd();
			break;
		//case "load_b":
		case 3:
			doLoadb();
			break;
		//case "load_s":
		case 4:
			doLoads();
			break;
		//case "load_c":
		case 5:
			doLoadc();
			break;


			////////////////////////////////////
		//case "if":
		case 6:
			doIf();
			break;
		//		case "while":
		case 7:
			doWhile();
			break;
		//case "goto":
		case 8:
			doGoto();
			break;
		//case "GT":
		case 9:
			doGT();
			break;
		//case "LT":
		case 10:
			doLT();
			break;
		//case "GE":
		case 11:
			doGE();
			break;
		//case "LE":
		case 12:
			doLE();
			break;
		//case "NE":
		case 13:
			doNE();
			break;
		//case "EQ":
		case 14:
			doEQ();
			break;
		//case "AND":
		case 15:
			doAND();
			break;
		//case "OR":
		case 16:
			doOR();
			break;
		//case "NOT":
		case 17:
			doNT();
			break;
		//case "sub_i":
		case 18:
			doSubi();
			break;
		//case "sub_d":
		case 19:
			doSubd();
			break;
		//case "add_i":
		case 20:
			doAddi();
			break;
		//case "add_d":
		case 21:
			doAddd();
			break;
		//case "mul_i":
		case 22:
			doMuli();
			break;
		//case "mul_d":
		case 23:
			doMuld();
			break;
		//case "div_i":
		case 24:
			doDivi();
			break;
		//case "div_d":
		case 25:
			doDivd();
			break;
		//case "inc_1":
		case 26:
			doInc1();
			break;
		//case "dec_1":
		case 27:
			doDec1();
			break;

			//////////////////////


		//case "retExp":
		case 28:
			doRetExp();
			break;
		//case "ret":
		case 29:
			doRet();
			break;
		//case "defFunction":
		case 30:
			doDefFunc();
			break;
		//case "end":
		case 31:
			doEnd();
			break;
		//case "getFunc":
		case 32:
			doGetFunc();
			break;
		//case "pushTypeArg":
		case 33:
			doPushTypeArg();
			break;
		//case "pushFuncArg":
		case 34:
			doPushFuncArg();
			break;
		//case "invoke":
		case 35:
			doInvoke();
			break;

			/////////////////////////////
		//case "defClass":
		case 36:
			doDefClass();
			break;
		//case "defInterface":
		case 37:
			doDefIntf();
			break;
		//case "extends":
		case 38:
			doExtd();
			break;
		//case "impliments":
		case 39:
			doImpl();
			break;
		//case "Fields":
		case 40:
			doFields();
			break;
		//case "defField":
		case 41:
			doDefFld();
			break;
		//case "Methods":
		case 42:
			doMethods();
			break;
		//case "defMethod":
		case 43:
			doDefMthd();
			break;
		//case "defGnrcPar":
		case 44:
			doDefGnrcPar();
			break;
		//case "defFuncPar":
		case 45:
			doDefFuncPar();
			break;
		//case "newArr":
		case 46:
			doNewArr();
			break;
		//case "newObj":
		case 47:
			doNewObj();
			break;
		//case "defLambdaExp":
		case 48:
			doDefLmbdExp();
			break;
		//case "getFuncObj":
		case 49:
			doGetFuncObj();
			break;
		//case "getMethod":
		case 50:
			doGetMthd();
			break;
		//case "getArray":
		case 51:
			doGetArr();
			break;
		//case "getField":
		case 52:
			doGetFld();
			break;
		//case "getClass":
		case 53:
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
	//AbstType* type1=(stcz->getTypeLst())[stcz->getTypeTbl()[opd1]];
	long addr2;
	long addr3;
	if(ebp==0){
		addr2=global_vars[opd2];
		addr3=global_vars[opd3];
	}else{
		//get addr2 from opd2
		if(local_vars->find(opd2)!=local_vars->end()){
			addr2=(*(((this->local_vars))))[opd2]+this->ebp;
		}else if(global_vars.find(opd2)!=global_vars.end()){
			addr2=global_vars[opd2];
		}else{
			cerr<<"not find symbol name "<<opd2<<endl;
			return;
		}
		//get addr3 from opd3
		if((this->local_vars)->find(opd3)!=local_vars->end()){
			addr3=(*((this->local_vars)))[opd3]+this->ebp;
		}else if(this->global_vars.find(opd3)!=global_vars.end()){
			addr3=this->global_vars[opd3];
		}else{
			cerr<<"not find symbol name "<<opd3<<endl;return;
		}
	}
	DatValue& r2=mem->fetchStack(addr2);
	DatValue& r3=mem->fetchStack(addr3);
	//deal with type auto conversion and l/r value
	if(r3.valuek==vk_double&&opd1!="double"){	//mov int a b
		long mv=(long)r3.value.double_value;
		if(r2.valuek==vk_ptr){
		//	long addr2=r2.value.ptr_value;
		//	InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
		//	p->value.value.int_value=mv;
		}else{
			r2.value.int_value=mv;
		}
	}else if(opd1=="double"&&r3.valuek!=vk_double){	//mov double a b
		double mv=(double)r3.value.int_value;
		if(r2.valuek==vk_ptr){
		//	long addr2=r2.value.ptr_value;
		//	InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
		//	p->value.value.double_value=mv;
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
			//long addr2=r2.value.ptr_value;
			//InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			//p->value.value.ptr_value=addr;
		}else{
			r2.value.ptr_value=addr;
		}
	}else{	//ptr assign to ptr
		if(r2.valuek==vk_ptr){
			//long addr2=r2.value.ptr_value;
			//InstBasic* p=(InstBasic*)mem->fetchObj(addr2);
			//p->value.value=r3.value;
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
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		//long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		///AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		//if(this->local_vars->find(opd1)==local_vars->end()){
			(*local_vars)[opd1]=tos-ebp;
		//}
	}
}

void Interpreter::doLoadd() {
	string& opd1=code->getOpd1();
	double vd=stod(code->getOpd2());
	RRValue v;
	v.double_value=vd;
	long tos=mem->pushStack(vk_double,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		//long tpi=mem->fetchStack(ebp).value.int_value;
		//AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		//if((this->local_vars)->find(opd1)==local_vars->end()){
			(*this->local_vars)[opd1]=tos-ebp;
		//}
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
	this->esp++;

	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		//long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		//AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		//if(local_vars->find(opd1)==local_vars->end()){
			(*local_vars)[opd1]=tos-ebp;
		//}
	}
}

void Interpreter::doLoadc() {
	string& opd1=code->getOpd1();
	long vi=(code->getOpd2()).at(0);
	RRValue v;
	v.int_value=vi;
	long tos=mem->pushStack(vk_int,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		//long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		//AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		//if(local_vars->find(opd1)==local_vars->end()){
			(*local_vars)[opd1]=tos-ebp;
		//}
	}
}

void Interpreter::doLoadb() {
	string& opd1=code->getOpd1();
	long vi=code->getOpd2()=="true"?1:0;
	RRValue v;
	v.int_value=vi;
	long tos=mem->pushStack(vk_int,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=tos;
	}else{
		//long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		//AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		//if(local_vars->find(opd1)==local_vars->end()){
			(*local_vars)[opd1]=tos-ebp;
		//}
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
		//long p2=v2.value.ptr_value;
		//long p3=v3.value.ptr_value;
		//DatValue& v4=mem->fetchObj(p2);
		//DatValue& v5=mem->fetchObj(p3);
		//return cmp2Value(v4,v5);
	}else if(v2.valuek==vk_ptr){
		//long p2=v2.value.ptr_value;
		//DatValue& v4=mem->fetchObj(p2);
		//return cmp2Value(v4,v3);
	}else if(v3.valuek==vk_ptr){
		//long p3=v3.value.ptr_value;
		//DatValue& v5=mem->fetchObj(p3);
		//return cmp2Value(v2,v5);
	}else{
		return cmp2Value(v2,v3);
	}
	return 0;
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
	if(local_vars->find(name)!=local_vars->end()){
		addr=(*((this->local_vars)))[name]+this->ebp;
	}else if(this->global_vars.find(name)!=global_vars.end()){
		addr=this->global_vars[name];
	}else{
		cerr<<"not find symbol name "<<name<<endl;
	}
	return addr;
}

void Interpreter::addVarStack(ValueK k,RRValue& v,string& name){
	long tos=mem->pushStack(k,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[name]=tos;
	}else{
		//long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		//AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		if(((this->local_vars))->find(name)==local_vars->end()){
			(*local_vars)[name]=tos-ebp;
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
	/*	long p2=v2.value.ptr_value;
		long p3=v3.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;*/
	}else if(v2.valuek==vk_ptr){
	/*	long p2=v2.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=v3.value.int_value;*/
	}else if(v3.valuek==vk_ptr){
	/*	long p3=v3.value.ptr_value;
		long i3=((InstBasic*)(mem->fetchObj(p3)))->value.value.int_value;
		i2=v2.value.int_value;*/
	}else{
		i2=v2.value.int_value;
		i3=v2.value.int_value;
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
	/*	long p2=v2.value.ptr_value;
		long p3=v3.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;*/
	}else if(v2.valuek==vk_ptr){
	/*	long p2=v2.value.ptr_value;
		i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
		i3=v3.value.int_value;*/
	}else if(v3.valuek==vk_ptr){
	/*	long p3=v3.value.ptr_value;
		long i3=((InstBasic*)(mem->fetchObj(p3)))->value.value.int_value;
		i2=v2.value.int_value;*/
	}else{
		i2=v2.value.int_value;
		i3=v2.value.int_value;
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
	//	long p2=v2.value.ptr_value;
	//	i2=((InstBasic*)(mem->fetchObj(p2)))->value.value.int_value;
	}else{
		i2=v2.value.int_value;
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
	if(i3==0) {cerr<<"error divide by 0: "<<opd2<<" / "<<opd3<<endl;return;}
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
	if(i3==0) {cerr<<"error divide by 0: "<<opd2<<" / "<<opd3<<endl;return;}
	RRValue v;
	v.int_value=i2/i3;
	this->addVarStack(vk_double,v,opd1);
}

void Interpreter::doInc1() {
	string& opd1=code->getOpd1();
	long a1=getSbAddr(opd1);
	DatValue& v1=mem->fetchStack(a1);
	//double i1=getDVDatV(v1);
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
	//double i1=getDVDatV(v1);
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
		//p=this->getPtrValue(v.value.ptr_value);
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
		//p=this->getPtrValue(v.value.ptr_value);
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
	DatValue& oldv=mem->fetchStack(this->getSbAddr(opd2));
	ValueK k=oldv.valuek;
	RRValue v=oldv.value;
	this->esp=this->ebp-3;
	this->pc=mem->fetchStack(ebp-1).value.int_value;//return address
	this->ebp=mem->fetchStack(ebp-2).value.int_value;
	this->mem->setStackTop(esp);
	this->mem->pushStack(k,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd2]=this->esp;
		this->codes=this->stcz->getScript();
	}else{
		long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		this->codes=f->getBody();
	}
}

void Interpreter::doRet() {
	//return last frame
	this->esp=this->ebp-3;
	this->pc=mem->fetchStack(ebp-1).value.int_value;//return address
	this->ebp=mem->fetchStack(ebp-2).value.int_value;
	this->mem->setStackTop(esp);
	RRValue v;
	v.int_value=0;
	this->mem->pushStack(vk_int,v);
	this->esp++;
	if(ebp==0){
		//(this->global_vars)[opd2]=this->esp;
		this->codes=this->stcz->getScript();
	}else{
		long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		this->codes=f->getBody();
	}
}

void Interpreter::doDefFunc() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	AbstFunc *tf=new AbstFunc;
	tf->setName(opd1);
	tf->setSig(opd2);
	long i=(stcz->getFuncList()).size();
	(stcz->getFuncList()).push_back(tf);
	(stcz->getFuncTbl())[opd1]=i;
	loadFunc(tf);
}

void Interpreter::loadFunc(AbstFunc* f){
	f->setEntry(stcz->getScript()->size());
	//bool gono=true;
	while(true){
		this->code=(*(stcz->getScript()))[pc++];
		if(this->code->getOpt()=="end"){
			//gono=false;
			break;
		}else{
			f->setBody(new vector<IRCode*>);
			auto c=new IRCode(*(this->code));
			f->getBody()->push_back(c);
			//break;
		}
	}
}

void Interpreter::doEnd() {
}

void Interpreter::doDefGnrcPar() {
}

void Interpreter::doDefFuncPar() {
	string& opd1=this->code->getOpd1();
	(*local_vars)[opd1]=esp++;
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
		while(f->hasNext&&f->getSig()!=opd2){
			f=f->getNext();
		}
		//report err when not found

	}else{

	}
	//push stack, new frame
	RRValue r1;
	r1.int_value=this->ebp;
	mem->pushStack(vk_int,r1);
	this->esp++;
	r1.int_value=this->pc;
	mem->pushStack(vk_int,r1);
	this->esp++;
	this->pc=f->getEntry();
}

void Interpreter::doPushTypeArg() {

}

void Interpreter::doPushFuncArg() {
	string& opd1=this->code->getOpd1();
	DatValue& v=mem->fetchStack(this->getSbAddr(opd1));
	this->mem->pushStack(v.valuek,v.value);
	//addVarStack(v.valuek,v.value,opd1);
}

void Interpreter::doInvoke() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	DatValue& v=mem->peekStack();

	if(ebp==0){
		(this->global_vars)[opd2]=this->esp;
		this->codes=this->stcz->getScript();
	}else{
		long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		AbstFunc *f=dynamic_cast<AbstFunc*>((this->stcz->getTypeLst())[tpi]);
		this->codes=f->getBody();
		if(local_vars->find(opd2)==local_vars->end()){
			(*local_vars)[opd2]=this->esp-ebp;
		}
	}
	this->esp=this->ebp+1;
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
