/*
 * RObj.h
 *
 *  Created on: Feb 1, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ROBJ_H_
#define SRC_TYPESYS_ROBJ_H_

#include "RVar.h"

//object in heap
class RObj: public RVar {
public:
	RObj();
	virtual ~RObj();

private:


};



#endif /* SRC_TYPESYS_ROBJ_H_ */
