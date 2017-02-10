/*
 * TFunc.h
 *
 *  Created on: Jan 24, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_TFUNC_H_
#define SRC_TYPESYS_TFUNC_H_
#include <list>
#include <string>
#include <set>
#include <map>
using namespace std;
#include "TypeSys.h"
#include "IR/IR.h"

class TFunc : public TType {
public:
	TFunc();
	virtual ~TFunc();
	TypeK getTypeK(){return tfunc;}
	string getName();
	void setName(string);
	const TGnrc*& getGnrcPars() const;
	void setGnrcPars(const TGnrc*& gnrcPars);
	RcdFunc*& getFunc() const;
	void setFunc(RcdFunc*& func);

	//const RcdFunc*& getFunc() const;
	//void setFunc(const RcdFunc*& func);

private:
	name;
	RcdFunc* r_func;
	TGnrc* gnrc_pars;list<string> parnames;
	list<string> partypes;
	map<string,AddrFrmt> sym_inner;//define while loading
	map<string,AddrFrmt> sym_outer;//decide while executing
};

#endif /* SRC_TYPESYS_TFUNC_H_ */
