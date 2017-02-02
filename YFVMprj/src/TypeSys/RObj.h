/*
 * RObj.h
 *
 *  Created on: Feb 1, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ROBJ_H_
#define SRC_TYPESYS_ROBJ_H_

#include "RVar.h"

class RObj: public RVar {
public:
	RObj();
	virtual ~RObj();
	const RValue& getValue() const;
	void setValue(const RValue& value);

private:
	RValue value;//long if int/bool/char type, double if double type, ptr if obj or array

};



#endif /* SRC_TYPESYS_ROBJ_H_ */
