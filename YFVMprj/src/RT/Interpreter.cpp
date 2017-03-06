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
	RRValue v;
	v.int_value=0;
	this->mem->pushStack(vk_int,v);
	//this->esp++;
	while(isNotEnd){
		//doPrintStack();
		this->code=((*this->codes)[pc++]);
		string& opt=this->code->getOpt();
		switch(this->stcz->getOptNum()[opt]){//in future, use ptr array to deal with distribution
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
		//minus_i
		case 28:
			doMinusi();
			break;
		case 29:
			doMinusd();
			break;
			//////////////////////


		//case "retExp":
		case 30:
			doRetExp();
			break;
		//case "ret":
		case 31:
			doRet();
			break;
		//case "defFunction":
		case 32:
			doDefFunc();
			break;
		//case "end":
		case 33:
			doEnd();
			break;
		//case "getFunc":
		case 34:
			doGetFunc();
			break;
		//case "pushTypeArg":
		case 35:
			doPushTypeArg();
			break;
		//case "pushFuncArg":
		case 36:
			doPushFuncArg();
			break;
		//case "invoke":
		case 37:
			doInvoke();
			break;

			/////////////////////////////
		//case "defClass":
		case 38:
			doDefClass();
			break;
		//case "defInterface":
		case 39:
			doDefIntf();
			break;
		//case "extends":
		case 40:
			doExtd();
			break;
		//case "impliments":
		case 41:
			doImpl();
			break;
		//case "Fields":
		case 42:
			doFields();
			break;
		//case "defField":
		case 43:
			doDefFld();
			break;
		//case "Methods":
		case 44:
			doMethods();
			break;
		//case "defMethod":
		case 45:
			doDefMthd();
			break;
		//case "defGnrcPar":
		case 46:
			doDefGnrcPar();
			break;
		//case "defFuncPar":
		case 47:
			doDefFuncPar();
			break;
		//case "newArr":
		case 48:
			doNewArr();
			break;
		//case "newObj":
		case 49:
			doNewObj();
			break;
		//case "defLambdaExp":
		case 50:
			doDefLmbdExp();
			break;
		//case "getFuncObj":
		case 51:
			doGetFuncObj();
			break;
		//case "getMethod":
		case 52:
			doGetMthd();
			break;
		//case "getArray":
		case 53:
			doGetArr();
			break;
		//case "getField":
		case 54:
			doGetFld();
			break;
		//case "getClass":
		case 55:
			doGetClass();
			break;
		//end
		case 56:
			doVMPrint();
			break;

		default:
			cerr<<"unknown opt: "<<this->code->getOpt()<<" "<<this->code->getOpd1()
				<<" "<<this->code->getOpd2()<<" "<<this->code->getOpd3()<<endl;
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
	long addr2=getSbAddr(opd2);
	long addr3=getSbAddr(opd3);
	if(addr2==-1){	//not find name in symbol-table
		movNew(opd1,opd2);
		addr2=esp;
	}else if(addr2>esp){	//find name, but not in stack
		RRValue v;
		if(opd1=="double"){
			mem->pushStack(vk_double,v);
		}else if(opd1=="int"||opd1=="bool"||opd1=="char"){
			mem->pushStack(vk_int,v);
		}else if(opd1=="string"){
			mem->pushStack(vk_ptr,v);
		}else{
			mem->pushStack(vk_ptr,v);
		}
		addr2=++esp;
	}
	DatValue& r3=mem->fetchStack(addr3);
	DatValue& r2=mem->fetchStack(addr2);
	if(r2.valuek==vk_ptr){
		//r2=
	}
	if(r3.valuek==vk_ptr){
		//r3=
	}
	//deal with type auto conversion and l/r value
	if(r3.valuek==vk_double&&opd1=="int"){
		//mov int a b
		long mv=(long)r3.value.double_value;
		r2.value.int_value=mv;
	}else if(r3.valuek==vk_int&&opd1=="double"){
		double mv=r3.value.int_value;
		r2.value.double_value=mv;
	}
	else if(opd1=="string"){

	}else{
		r2.value=r3.value;
	}
}

void Interpreter::movNew(string& opd1, string& opd2){	//mov to a addr never used
	RRValue v;
	if(opd1=="double"){
		addVarStack(vk_double,v,opd2);
	}else if(opd1=="int"||opd1=="bool"||opd1=="char"){
		addVarStack(vk_int,v,opd2);
	}else if(opd1=="string"){
		addVarStack(vk_ptr,v,opd2);
	}else{
		addVarStack(vk_ptr,v,opd2);
	}
}

void Interpreter::addVarStack(ValueK k,RRValue& v,string& name){
	mem->pushStack(k,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[name]=esp;
	}else{
		(*local_vars)[name]=esp-ebp;
	}
}

void Interpreter::writeVarStack(ValueK k,RRValue& v,string& name){
	long addr;
	if(ebp==0){
		addr=global_vars[name];
	}else{
		addr=ebp+(*local_vars)[name];
	}
	DatValue& nv=mem->fetchStack(addr);
	nv.valuek=k;
	nv.value=v;
}

void Interpreter::doLoadi() {
	string& opd1=code->getOpd1();
	long addr=getSbAddr(opd1);
	if(addr!=-1&&addr<esp){
		return;
	}
	long vi=stol(code->getOpd2());
	RRValue v;
	v.int_value=vi;
	mem->pushStack(vk_int,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=esp;
	}else{
		(*local_vars)[opd1]=esp-ebp;
	}
}

void Interpreter::doLoadd() {
	string& opd1=code->getOpd1();
	long addr=getSbAddr(opd1);
	if(addr!=-1&&addr<esp){
		return;
	}
	double vd=stod(code->getOpd2());
	RRValue v;
	v.double_value=vd;
	mem->pushStack(vk_double,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=esp;
	}else{
		(*this->local_vars)[opd1]=esp-ebp;
	}
}

void Interpreter::doLoads() {
/*	string& opd1=code->getOpd1();
	long addr1=getSbAddr(opd1);
	if(addr1!=-1&&addr1<esp){
		return;
	}
	string& opd2=code->getOpd2();
	long addr=mem->allocStr(opd2.size());
	mem->cpyStr(addr,opd2);
	RRValue v;
	v.ptr_value=addr;
	mem->pushStack(vk_ptr,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=esp;
	}else{
		(*local_vars)[opd1]=esp-ebp;
	}*/

}

void Interpreter::doLoadc() {
	string& opd1=code->getOpd1();
	long addr=getSbAddr(opd1);
	if(addr!=-1&&addr<esp){
		return;
	}
	long vi=(code->getOpd2()).at(0);
	RRValue v;
	v.int_value=vi;
	mem->pushStack(vk_int,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=esp;
	}else{
		(*local_vars)[opd1]=esp-ebp;
	}
}

void Interpreter::doLoadb() {
	string& opd1=code->getOpd1();
	long addr=getSbAddr(opd1);
	if(addr!=-1&&addr<esp){
		return;
	}
	long vi=code->getOpd2()=="true"?1:0;
	RRValue v;
	v.int_value=vi;
	mem->pushStack(vk_int,v);
	this->esp++;
	if(ebp==0){
		(this->global_vars)[opd1]=esp;
	}else{
		(*local_vars)[opd1]=esp-ebp;
	}
}

int Interpreter::doCmp(){
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	long a2=getSbAddr(opd2);
	long a3=getSbAddr(opd3);
	DatValue& v2=mem->fetchStack(a2);
	DatValue& v3=mem->fetchStack(a3);
	if(v2.valuek==vk_ptr){

	}
	if(v3.valuek==vk_ptr){

	}
	return cmp2Value(v2,v3);
}

int Interpreter::cmp2Value(DatValue& v2, DatValue& v3) {//0 EQ, 1 larger, -1 less

	if(v2.valuek==vk_int&&v3.valuek==vk_int){
		long r2=v2.value.int_value,r3=v3.value.int_value;
		if(r2<r3) return -1;
		else if(r2==r3) return 0;
		else return 1;
	}else if(v2.valuek==vk_int&&v3.valuek==vk_double){
		long r2=v2.value.int_value;
		double r3=v3.value.double_value;
		if(r2<r3) return -1;
		else if(r2==r3) return 0;
		else return 1;
	}else if(v2.valuek==vk_double&&v3.valuek==vk_int){
		double r2=v2.value.double_value;
		long r3=v3.value.int_value;
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
	long addr=-1;	//-1 means not find symbol
	if(ebp==0){
		if(global_vars.find(name)==global_vars.end()){
			return -1;
		}else{
			addr=this->global_vars[name];
			return addr;
		}
	}
	if(local_vars->find(name)!=local_vars->end()){
		addr=(*((this->local_vars)))[name]+this->ebp;
	}else if(this->global_vars.find(name)!=global_vars.end()){
		addr=this->global_vars[name];
	}else{
		//cerr<<"not find symbol name "<<name<<endl;
	}
	return addr;
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

void Interpreter::doMinusi() {
	string& opd1=code->getOpd1();

}

void Interpreter::doMinusd() {
	string& opd1=code->getOpd1();

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
	}else
		this->pc=a2;
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
	long a=this->getSbAddr(opd2);
	DatValue& oldv=mem->fetchStack(a);
	ValueK k=oldv.valuek;
	RRValue v=oldv.value;
	this->esp=this->ebp-3;
	this->pc=mem->fetchStack(ebp-1).value.int_value;//return address
	this->ebp=mem->fetchStack(ebp-2).value.int_value;
	this->mem->setStackTop(esp+1);
	this->mem->pushStack(k,v);
	this->esp++;
	if(ebp==0){
		//(this->global_vars)[opd2]=this->esp;
		this->codes=this->stcz->getScript();
		this->local_vars=NULL;
	}else{
		long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		AbTypeFunc *f=this->stcz->getFuncLst()[tpi];
		this->codes=f->getBody();
		//this->local_vars=&(f->getSymInner());
		//(*this->local_vars)[opd2]=this->esp;
	}
	//doPrintStack();
}

void Interpreter::doRet() {
	//return last frame
	this->esp=this->ebp-3;
	this->pc=mem->fetchStack(ebp-1).value.int_value;//return address
	this->ebp=mem->fetchStack(ebp-2).value.int_value;
	this->mem->setStackTop(esp+1);
	RRValue v;
	v.int_value=0;
	this->mem->pushStack(vk_int,v);
	this->esp++;
	if(ebp==0){
		//(this->global_vars)[opd2]=this->esp;
		this->codes=this->stcz->getScript();
		this->local_vars=NULL;
	}else{
		long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
		AbTypeFunc *f=this->stcz->getFuncLst()[tpi];
		this->codes=f->getBody();
		this->local_vars=&(f->getSymInner());
		//(this->local_vars)[opd2]=this->esp;
	}
}

void Interpreter::doDefFunc() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	AbTypeFunc *tf=new AbTypeFunc;
	tf->setName(opd1);
	tf->setSig(opd2);
	long i=(stcz->getFuncList()).size();
	(stcz->getFuncList()).push_back(tf);
	(stcz->getFuncTbl())[opd1]=i;
	loadFunc(tf);
}

void Interpreter::loadFunc(AbTypeFunc* f){
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
	if(ebp==0){
		isNotEnd=false;
		cout<<"finish interpreting"<<endl;
	}
}

void Interpreter::doDefGnrcPar() {
}

void Interpreter::doDefFuncPar() {
	string& opd2=this->code->getOpd2();
	this->esp++;
	(*local_vars)[opd2]=esp-ebp;
	//mem->setStackTop(mem->getStackTop()+1);
}


void Interpreter::doGetFunc() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	string& opd3=code->getOpd3();
	auto ftb=stcz->getFuncTbl();
	auto flt=stcz->getFuncList();
	long i=ftb[opd1];
	AbTypeFunc* f=flt[i];
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
	mem->pushStack(vk_int,r1);//stack layout: ...ebp, pc, ebp(ptr to function), args...
	this->esp++;
	RRValue r2;
	r2.int_value=this->pc;
	mem->pushStack(vk_int,r2);
	this->esp++;
	RRValue r3;
	r3.int_value=f->getIndex();
	mem->pushStack(vk_int,r3);
	this->esp++;
	this->next_ebp=esp;
	//this->pc=1;
	//this->codes=f->getBody();
}

void Interpreter::doPushTypeArg() {

}

void Interpreter::doPushFuncArg() {
	string& opd1=this->code->getOpd1();
	DatValue& v=mem->fetchStack(this->getSbAddr(opd1));
	this->mem->pushStack(v.valuek,v.value);
	this->esp++;
	//doPrintStack();
}

void Interpreter::doInvoke() {
	string& opd1=code->getOpd1();
	string& opd2=code->getOpd2();
	this->ebp=next_ebp;
	DatValue& v=mem->fetchStack(this->ebp-1);
	v.value.int_value=this->pc;
	this->pc=1;
	if(mem->fetchStack(ebp-2).value.int_value==0){
		(this->global_vars)[opd2]=this->ebp-2;
	}else{
		long last_ebp=mem->fetchStack(ebp-2).value.int_value;
		long fi=(mem->fetchStack(last_ebp)).value.int_value;
		AbTypeFunc *f=this->stcz->getFuncLst()[fi];
		if(f->getSymInner().find(opd2)==f->getSymInner().end()){
			f->getSymInner()[opd2]=this->ebp-2-last_ebp;
		}
	}
	long tpi=mem->fetchStack(ebp).value.int_value;  //link for symbol table
	AbTypeFunc *f=this->stcz->getFuncLst()[tpi];
	this->codes=f->getBody();
	this->local_vars=&(f->getSymInner());
	//if(local_vars->find(opd2)==local_vars->end()){
	//	(*local_vars)[opd2]=this->esp-ebp;
	//}

	this->esp=this->ebp;
	//mem->setStackTop(esp+1);
	//doPrintStack();

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

void Interpreter::doVMPrint(){
	string& opd1=this->code->getOpd1();
	//cout<<opd1<<endl;
	DatValue& v=mem->fetchStack((this->getSbAddr(opd1)));
	if(v.valuek==vk_int){
		cout<<"VM print: "<<opd1<<" = "<<v.value.int_value<<endl;
	}else if(v.valuek==vk_double){
		cout<<"VM print: "<<opd1<<" = "<<v.value.double_value<<endl;
	}else{
		cout<<"VM print: "<<opd1<<" = "<<v.value.ptr_value<<endl;
	}
}

void Interpreter::doPrintStack() {
	long t=mem->getStackTop();
	for(long i=0;i<t;i++){
		cout<<mem->fetchStack(i).value.int_value<<" ";
	}
	cout<<endl;
	cout<<"pc "<<pc<<" esp "<<esp<<" ebp "<<ebp<<endl;
}
//void Interpreter::doEnd() {
//
//}
