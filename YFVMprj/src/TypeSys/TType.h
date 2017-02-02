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
	virtual TypeK getTypeK(){return ttype;}
	int getSize();
	int setSize();
private:
	int size;//size of instance of this type

};
enum TypeK{tbasic, tclass, tfunc, tgnrc, tarray, ttype, tdummy};


#endif /* SRC_TYPESYS_TTYPE_H_ */
