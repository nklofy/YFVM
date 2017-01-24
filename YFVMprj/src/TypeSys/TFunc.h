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
class TFunc {
public:
	TFunc();
	virtual ~TFunc();
	string getName();
	void setName(string);
	list<string> parnames;
	list<string> partypes;
private:
	name;
};

#endif /* SRC_TYPESYS_TFUNC_H_ */
