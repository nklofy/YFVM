/*
 * RRef.h
 *
 *  Created on: Feb 2, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_PTROBJ_H_
#define SRC_TYPESYS_PTROBJ_H_

#include "TType.h"

class PtrObj {
public:
	PtrObj();
	virtual ~PtrObj();
private:
	long ref_type;
	long obj_ptr;
};

#endif /* SRC_TYPESYS_PTROBJ_H_ */
