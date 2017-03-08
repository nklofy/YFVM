/*
 * TFunc.h
 *
 *  Created on: Jan 24, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABTYPEFUNC_H_
#define SRC_TYPESYS_ABTYPEFUNC_H_
#include <list>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

#include "AbstType.h"
#include "../Loader/IR.h"

class AbTypeFunc : public AbstType {
public:
	AbTypeFunc();
	virtual ~AbTypeFunc();
	TypeK getTypeK(){return tfunc;}
	string& getName();
	void setName(string);

	const string& getSig();

	void setSig(const string& sig);

	vector<IRCode*>* getBody();
	void setBody(vector<IRCode*>*);
	bool isMthd=false;
	bool isOverload=false;
	void addNext(AbTypeFunc*);
	AbTypeFunc* getNext();

	long getEntry();
	void setEntry(long);
	list<string>& getParNames();
	list<string>& getParTypes();
	long getIndex();
	void setIndex(long index);
	unordered_map<string, long>& getSymInner();
	void setSymInner(unordered_map<string, long>& symInner);

	bool hasNext=false;


private:
	long entry;
	string name;
	string sig;
	long index;
	AbTypeFunc* next;
	AbTypeFunc* head;
	vector<IRCode*>* body;
	//RcdFunc* r_func;
	//AbstGnrc* gnrc_pars;
	list<string> parnames;
	list<string> partypes;
	unordered_map<string,long> sym_inner;//define while loading
	unordered_map<string,long> sym_outer;//decide while executing
};

#endif /* SRC_TYPESYS_ABTYPEFUNC_H_ */
