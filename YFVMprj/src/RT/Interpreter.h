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
	map<string,long>* local_vars;//point to function's local vars
	AbstFunc* crt_func;//point to function type each time pushing a frame in stack
	AbstClass* crt_cls;//point to class method belonging if crt function is method

	void doMov();
	void doLoadi();
	void doLoadd();
	void doLoads();
	void doLoadc();
	void doLoadb();
	int doCmp();
	int cmp2Value(DatValue&,DatValue&);
	long getSbAddr(string&);
	void addVarStack(ValueK, RRValue&, string&);
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
	void doIf();
	void doWhile();
	void doGoto();
	void doRetExp();
	void doRet();
	void doDefFunc();
	void loadFunc(AbstFunc*);
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
};

#endif /* SRC_INTERPRETER_H_ */
