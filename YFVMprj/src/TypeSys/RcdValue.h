/*
 * RValue.h
 *
 *  Created on: Feb 7, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_RCDVALUE_H_
#define SRC_TYPESYS_RCDVALUE_H_

class RcdValue {
public:
	RcdValue();
	virtual ~RcdValue();
	ValueK valuek;
	bool isLeft=false;
	RRValue value;

};
enum ValueK{vk_int, vk_double, vk_ptr};
union RRValue{
	long int_value;
	double double_value;
	long ptr_value;
};
#endif /* SRC_TYPESYS_RCDVALUE_H_ */
