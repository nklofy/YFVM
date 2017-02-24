/*
 * RValue.h
 *
 *  Created on: Feb 7, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_DATVALUE_H_
#define SRC_TYPESYS_DATVALUE_H_

enum ValueK{vk_int, vk_double, vk_ptr};
union RRValue{
	long int_value;
	double double_value;
	long ptr_value;
};
struct DatValue {
//public:
	//DatValue();
	//virtual ~DatValue();
	ValueK valuek;
	//bool isLeft=false;
	RRValue value;

};
#endif /* SRC_TYPESYS_DATVALUE_H_ */
