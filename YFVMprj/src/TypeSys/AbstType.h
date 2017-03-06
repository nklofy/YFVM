/*
 * TType.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABSTTYPE_H_
#define SRC_TYPESYS_ABSTTYPE_H_
#include <list>
#include <map>
#include <string>
using namespace std;
//#include "TypeSys.h"

enum TypeK{tbasic, tclass, tfunc, tgnrc, tarray, ttype, tdummy};

class AbstType {
public:
	static long RWidth;
	static long VWidth;
	AbstType();
	virtual ~AbstType();
	virtual TypeK getTypeK(){return ttype;}
	virtual long getSize();
};

#endif /* SRC_TYPESYS_ABSTTYPE_H_ */
