/*
 * RArray.h
 *
 *  Created on: Feb 1, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_INSTARRAY_H_
#define SRC_TYPESYS_INSTARRAY_H_

#include "InstVar.h"

class InstArray : public InstVar {
public:
	InstArray();
	virtual ~InstArray();
	long getArraySize();
	void setArraySize(long arraySize);

private:
	long array_size;

};

#endif /* SRC_TYPESYS_INSTARRAY_H_ */
