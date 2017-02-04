/*
 * RVar.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_RVAR_H_
#define SRC_TYPESYS_RVAR_H_

//base of all record, def header and metadate.
class RVar {
public:
	RVar();
	virtual ~RVar();
	long getMark() const;
	void setMark(long mark);
	long getType() const;
	void setType(long type);

private:
	long mark;//header of obj
	long type;//point to index of obj's type in static pool
};
union RValue{
	long int_value;
	double double_value;
};
#endif /* SRC_TYPESYS_RVAR_H_ */
