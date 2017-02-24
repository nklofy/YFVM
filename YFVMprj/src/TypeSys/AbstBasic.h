/*
 * TBasic.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABSTBASIC_H_
#define SRC_TYPESYS_ABSTBASIC_H_

#include "AbstType.h"

enum TBasicK{
	tint,
	tdouble,
	tbool,
	tchar,
	tstring
};
class AbstBasic : public AbstType {
public:
	AbstBasic();
	AbstBasic(TBasicK);
	virtual ~AbstBasic();
	TypeK getTypeK(){return tbasic;}
	TBasicK getTBasicK();
	int setTBasicK(TBasicK);
private:

};

#endif /* SRC_TYPESYS_ABSTBASIC_H_ */
