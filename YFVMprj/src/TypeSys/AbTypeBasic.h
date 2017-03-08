/*
 * TBasic.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABTYPEBASIC_H_
#define SRC_TYPESYS_ABTYPEBASIC_H_

#include "AbstType.h"
#include "InstBasic.h"

enum TBasicK{
	tint,
	tdouble,
	tbool,
	tchar,
	tstring
};
class AbTypeBasic : public AbstType {
public:
	AbTypeBasic();
	AbTypeBasic(TBasicK);
	virtual ~AbTypeBasic();
	TypeK getTypeK(){return tbasic;}
	TBasicK getTBasicK();
	long getSize(){return sizeof(InstBasic);}
	DatValue& getValue();
	void setValue(DatValue&);

private:
	DatValue value;
};

#endif /* SRC_TYPESYS_ABTYPEBASIC_H_ */
