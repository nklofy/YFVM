/*
 * RVar.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_INSTVAR_H_
#define SRC_TYPESYS_INSTVAR_H_

//base of all record, def header and metadate.
class InstVar {
public:
	InstVar();
	virtual ~InstVar();
	long getMark() const;
	void setMark(long mark);
	long getType() const;
	void setType(long type);

private:
	long mark;//header of obj
	long type;//point to index of obj's type in static pool
};

#endif /* SRC_TYPESYS_INSTVAR_H_ */
