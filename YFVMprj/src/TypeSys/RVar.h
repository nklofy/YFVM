/*
 * RVar.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_RVAR_H_
#define SRC_TYPESYS_RVAR_H_

class RVar {
public:
	RVar();
	virtual ~RVar();
private:
	long mark;
	long type;
};
union RValue{
	long int_value;
	double double_value;
	long ref_ptr;
};
#endif /* SRC_TYPESYS_RVAR_H_ */
