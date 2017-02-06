/*
 * RArray.h
 *
 *  Created on: Feb 1, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_RARRAY_H_
#define SRC_TYPESYS_RARRAY_H_
#include "RVar.h"
class RArray : public RVar{
public:
	RArray();
	virtual ~RArray();
	int getArraySize() const;
	void setArraySize(int arraySize);

private:
	int array_size;

};

#endif /* SRC_TYPESYS_RARRAY_H_ */
