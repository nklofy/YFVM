/*
 * TArray.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABTYPEARRAY_H_
#define SRC_TYPESYS_ABTYPEARRAY_H_

#include "AbstType.h"

class AbTypeArray : public AbstType {
public:
	AbTypeArray();
	virtual ~AbTypeArray();
	TypeK getTypeK(){return tarray;}
};

#endif /* SRC_TYPESYS_ABTYPEARRAY_H_ */
