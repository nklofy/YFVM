/*
 * RObjInst.h
 *
 *  Created on: Feb 4, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_RBASIC_H_
#define SRC_TYPESYS_RBASIC_H_

#include "RVar.h"

//basic type object, int double ...
class RBasic: public RVar {
public:
	RBasic();
	virtual ~RBasic();
	const RValue& getValue() const;
	void setValue(const RValue& value);

private:
	RValue value;
};

#endif /* SRC_TYPESYS_RBASIC_H_ */
