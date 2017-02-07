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
using namespace std;
#include "TType.h"
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
	const RcdFunc*& getFunc() const;
	void setFunc(const RcdFunc*& func);

	list<string> parnames;
	list<string> partypes;

private:
	name;
	RcdFunc* r_func;//苟且一下吧。本来想转化格式，全部放入list<long[4]>里面，不用string，但是先就这样了
	TGnrc* gnrc_pars;
};

#endif /* SRC_TYPESYS_TFUNC_H_ */
