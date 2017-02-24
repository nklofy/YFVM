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
#include <vector>
using namespace std;
#include "AbstType.h"
#include "../IR/IR.h"

class AbstFunc : public AbstType {
public:
	AbstFunc();
	virtual ~AbstFunc();
	TypeK getTypeK(){return tfunc;}
	string getName();
	void setName(string);

	const string& getSig();

	void setSig(const string& sig);

	vector<IRCode*>* getBody();
	void setBody(vector<IRCode*>*);
	bool isMthd=false;
	bool isOverload=false;
	void addNext(AbstFunc*);
	AbstFunc* getNext();

	long getEntry();
	void setEntry(long);
	list<string>& getParNames();
	list<string>& getParTypes();

	bool hasNext=false;


private:
	long entry;
	string name;
	string sig;
	AbstFunc* next;
	AbstFunc* head;
	vector<IRCode*>* body;
	//RcdFunc* r_func;
	//AbstGnrc* gnrc_pars;
	list<string> parnames;
	list<string> partypes;
	map<string,long> sym_inner;//define while loading
	map<string,long> sym_outer;//decide while executing
};

#endif /* SRC_TYPESYS_ABSTFUNC_H_ */
