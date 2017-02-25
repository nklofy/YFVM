/*
 * RcdFunc.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_RCDFUNC_H_
#define SRC_RCDFUNC_H_
#include <string>
#include <list>
#include <vector>

#include "../Loader/IRCode.h"

using namespace std;

class RcdFunc {
public:
	RcdFunc();
	virtual ~RcdFunc();
	const string& getName() const;
	void setName(const string& name);
	const string& getSig() const;
	void setSig(const string& signature);
	const string& getScope() const;
	void setScope(const string& scope);
	vector<IRCode*>& getBody();
	void setBody(const vector<IRCode*>& body);
	int getRows() const;
	void setRows(int rows);
	list<IRCode*>& getPars();
private:
	string name;
	string signature;
	string scope;
	bool dummy;
	vector<IRCode*> body;	//code to run
	list<IRCode*> gtpars;	//generic type pars
	list<IRCode*> pars;	//pars
	int rows;

};

#endif /* SRC_RCDFUNC_H_ */
