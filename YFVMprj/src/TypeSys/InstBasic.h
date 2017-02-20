/*
 * RObjInst.h
 *
 *  Created on: Feb 4, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_INSTBASIC_H_
#define SRC_TYPESYS_INSTBASIC_H_

#include "DatValue.h"
#include "InstVar.h"
//basic type object, int double ...
class InstBasic: public InstVar {
public:
	InstBasic();
	virtual ~InstBasic();

	DatValue value;
};

#endif /* SRC_TYPESYS_INSTBASIC_H_ */
