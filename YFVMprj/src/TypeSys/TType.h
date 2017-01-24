/*
 * TType.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_TTYPE_H_
#define SRC_TYPESYS_TTYPE_H_
#include <list>
#include <map>
#include <string>
using namespace std;

class TType {
public:
	TType();
	virtual ~TType();
private:
	bool isDummy;
	bool isGnrc;
	list<string> G_pars;
	map<string, TType> G_args;

};

#endif /* SRC_TYPESYS_TTYPE_H_ */