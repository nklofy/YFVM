/*
 * RValue.h
 *
 *  Created on: Feb 7, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_RVALUE_H_
#define SRC_TYPESYS_RVALUE_H_

class RValue {
public:
	RValue();
	virtual ~RValue();
private:
	enum{v_int, v_double, v_prt} value_K;
	RRValue value;
};
union RRValue{
	long int_value;
	double double_value;
	AddrFrmt ptr_addr;
};
#endif /* SRC_TYPESYS_RVALUE_H_ */
