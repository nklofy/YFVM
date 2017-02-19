/*
 * TFunc.h
 *
 *  Created on: Jan 24, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABSTFUNC_H_
#define SRC_TYPESYS_ABSTFUNC_H_
#include <list>
#include <string>
#include <set>
#include <map>
using namespace std;
#include "TypeSys.h"
#include "IR/IR.h"

class AbstFunc : public AbstType {
public:
	AbstFunc();
	virtual ~AbstFunc();
	TypeK getTypeK(){return tfunc;}
	string getName();
	void setName(string);
	const AbstGnrc*& getGnrcPars() const;
	void setGnrcPars(const AbstGnrc*& gnrcPars);
	RcdFunc*& getFunc() const;
	void setFunc(RcdFunc*& func);
	bool isIsMthd() const;
	void setIsMthd(bool isMthod);

	//const RcdFunc*& getFunc() const;
	//void setFunc(const RcdFunc*& func);

private:
	string name;
	bool isMthd;
	bool isOverload;
	AbstFunc* next;
	AbstFunc* head;
	RcdFunc* r_func;
	AbstGnrc* gnrc_pars;list<string> parnames;
	list<string> partypes;
	map<string,long> sym_inner;//define while loading
	map<string,long> sym_outer;//decide while executing
};

#endif /* SRC_TYPESYS_ABSTFUNC_H_ */
