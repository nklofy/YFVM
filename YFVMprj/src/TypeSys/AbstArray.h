/*
 * TArray.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABSTARRAY_H_
#define SRC_TYPESYS_ABSTARRAY_H_

#include "AbstType.h"

class AbstArray : public AbstType {
public:
	AbstArray();
	virtual ~AbstArray();
	TypeK getTypeK(){return tarray;}
};

#endif /* SRC_TYPESYS_ABSTARRAY_H_ */
