/*
 * TArray.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_TARRAY_H_
#define SRC_TYPESYS_TARRAY_H_

#include "TType.h"

class TArray : public TType {
public:
	TArray();
	virtual ~TArray();
	TypeK getTypeK(){return tarray;}
};

#endif /* SRC_TYPESYS_TARRAY_H_ */
