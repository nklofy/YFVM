/*
 * TClass.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_TCLASS_H_
#define SRC_TYPESYS_TCLASS_H_

#include "TType.h"

class TClass : public TType {
public:
	TClass();
	virtual ~TClass();
	TypeK getTypeK(){return tclass;}
};

#endif /* SRC_TYPESYS_TCLASS_H_ */
