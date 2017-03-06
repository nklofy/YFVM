/*
 * Interpreter.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_INTERPRETER_H_
#define SRC_INTERPRETER_H_
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <iostream>
#include "../TypeSys/TypeSys.h"
#include "StaticZone.h"
#include "MemManager.h"
#include "IOManager.h"

using namespace std;

class Interpreter {
public:
	Interpreter();
	virtual ~Interpreter();
	int doInterpret(StaticZone*, MemManager*,IOManager*);
private:
	long esp=0;//stack
	long ebp=0;//frame
	long pc=0;//program counter
	long next_ebp;
	bool isNotEnd=true;
	vector<IRCode*>* codes;
	IRCode* code;
	StaticZone* stcz;
	MemManager* mem;
	IOManager* io;
	enum{scp_glb,scp_func,scp_mthd} name_scope;
	unordered_map<string,long> global_vars;
	unordered_map<string,long>* local_vars;//point to function's local vars
	AbTypeFunc* crt_func;//point to function type each time pushing a frame in stack
	AbTypeClass* crt_cls;//point to class method belonging if crt function is method

	void doMov();
	void doLoadi();
	void doLoadd();
	void doLoads();
	void doLoadc();
	void doLoadb();
	int doCmp();
	void movNew(string&, string&);
	void writeVarStack(ValueK, RRValue&, string&);
	void addVarStack(ValueK, RRValue&, string&);
	int cmp2Value(DatValue&,DatValue&);
	long getSbAddr(string&);
	void doGT();
	void doLT();
	void doGE();
	void doLE();
	void doNE();
	void doEQ();
	void doAND();
	void doOR();
	void doNT();
	inline DatValue& getPtrValue(long);
	long getIVDatV(DatValue&);
	double getDVDatV(DatValue&);
	void doSubi();
	void doSubd();
	void doAddi();
	void doAddd();
	void doMuli();
	void doMuld();
	void doDivi();
	void doDivd();
	void doInc1();
	void doDec1();
	void doMinusi();
	void doMinusd();
	void doIf();
	void doWhile();
	void doGoto();
	void doRetExp();
	void doRet();
	void doDefFunc();
	void loadFunc(AbTypeFunc*);
	void doEnd();
	void doDefGnrcPar();
	void doDefFuncPar();
	void doGetFunc();
	void doPushTypeArg();
	void doPushFuncArg();
	void doInvoke();
	void doDefClass();
	void doDefIntf();
	void doExtd();
	void doImpl();
	void doFields();
	void doDefFld();
	void doMethods();
	void doDefMthd();
	void doNewArr();
	void doNewObj();
	void doDefLmbdExp();
	void doGetFuncObj();
	void doGetMthd();
	void doGetArr();
	void doGetFld();
	void doGetClass();
	void doVMPrint();
	void doPrintStack();
};

#endif /* SRC_INTERPRETER_H_ */
