/*
 * Interpreter.cpp
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

int Interpreter::doInterpret(StaticPool* pool, MemManager* mem, IOManager* io) {
	this->pool=pool;
	this->mem=mem;
	this->io=io;
	while(true){
		this->code=(pool->getCodes())[pc];
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
	string& opd3=code->getOpd3();
	string& opd2=code->getOpd2();
	string& opd1=code->getOpd1();
	//some check
	long addr3=mem->fine(opd3);
	long addr2=mem->find(opd2);
	TType* type=pool->typelist[pool->type_tbl[opd1]];
	//todo
	mem->writeValue(type, add2, mem.readValue());

}

void Interpreter::doLoadi() {
	long addr1=mem->newReg();
	TType* type=pool->typelist[pool->type_tbl["int"]];
	long v=code->getOpd2();

	mem->writeValue(type,addr1,v);
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
