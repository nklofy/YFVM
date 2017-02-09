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
#include "TypeSys.h"

class TType {
public:
	TType();
	virtual ~TType();
	virtual TypeK getTypeK(){return ttype;}
	int getSize();
	int setSize();
	bool isIsDummy() const;
	void setIsDummy(bool isDummy);
	bool isIsGnrc() const;
	void setIsGnrc(bool isGnrc);

private:
	int size;//size of instance of this type
	bool isGnrc;
	bool isDummy;
};
enum TypeK{tbasic, tclass, tfunc, tgnrc, tarray, ttype, tdummy};


#endif /* SRC_TYPESYS_TTYPE_H_ */
