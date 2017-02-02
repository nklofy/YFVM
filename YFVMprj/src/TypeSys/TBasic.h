/*
 * TBasic.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_TBASIC_H_
#define SRC_TYPESYS_TBASIC_H_

#include "TType.h"

class TBasic : public TType {
public:
	TBasic();
	virtual ~TBasic();
	TypeK getTypeK(){return tbasic;}
	TBasicK getTBasicK();
	int setTBasicK(TBasicK);
private:

};
enum{
	tint,
	tdouble,
	tbool,
	tchar,
	tstring
}TBasicK;

#endif /* SRC_TYPESYS_TBASIC_H_ */
