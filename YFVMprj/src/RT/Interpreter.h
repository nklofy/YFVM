/*
 * Interpreter.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_INTERPRETER_H_
#define SRC_INTERPRETER_H_
#include <vector>

#include "TypeSys/TypeSys.h"

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
	IRCode* code;
	StaticZone* stcz;
	MemManager* mem;
	IOManager* io;
	enum{scp_glb,scp_func,scp_mthd} name_scope;
	map<string,long> global_vars;
	map<string,long>* local_vars;
	TFunc* crt_func;
	TClass* crt_cls;

	void doMov();
	void doLoadi();
	void doLoadd();
	void doLoads();
	void doLoadc();
	void doLoadb();
	void doGT();
	void doLT();
	void doGE();
	void doLE();
	void doNE();
	void doEQ();
	void doNT();
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
	void doIf();
	void doWhile();
	void doGoto();
	void doRetExp();
	void doRet();
	void doDefFunc();
	void doEnd();
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
	void doDefGnrcPar();
	void doDefFuncPar();
	void doNewArr();
	void doNewObj();
	void doDefLmbdExp();
	void doGetFuncObj();
	void doGetMthd();
	void doGetArr();
	void doGetFld();
	void doGetClass();
};

#endif /* SRC_INTERPRETER_H_ */
