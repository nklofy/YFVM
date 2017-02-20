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
#include "TypeSys.h"

class AbstType {
public:
	AbstType();
	virtual ~AbstType();
	virtual TypeK getTypeK(){return ttype;}
	long getSize();
	long setSize();
	bool isIsDummy() const;
	void setIsDummy(bool isDummy);
	bool isIsGnrc() const;
	void setIsGnrc(bool isGnrc);

private:
	long size;//size of instance of this type
	bool isGnrc;
	bool isDummy;
};
enum TypeK{tbasic, tclass, tfunc, tgnrc, tarray, ttype, tdummy};


#endif /* SRC_TYPESYS_ABSTTYPE_H_ */
