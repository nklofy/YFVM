/*
 * RArray.h
 *
 *  Created on: Feb 1, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_INSTARRAY_H_
#define SRC_TYPESYS_INSTARRAY_H_

#include "InstVar.h"

class InstArray : public InstVar {	//memory layout: arraytype, coretype, instarray of dims, instarray of data
public:
	InstArray();
	virtual ~InstArray();
	long getArraySize();
	void setArraySize(long arraySize);

private:
	long core_type;
	long dims_n;
	long total_count;
};

#endif /* SRC_TYPESYS_INSTARRAY_H_ */
