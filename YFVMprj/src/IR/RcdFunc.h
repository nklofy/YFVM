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
#include "IRCode.h"

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
	list<IRCode*>& getBody();
	void setBody(const list<IRCode*>& body);

private:
	string name;
	string signature;
	string scope;
	bool dummy;
	list<IRCode*> body;

};

#endif /* SRC_RCDFUNC_H_ */
