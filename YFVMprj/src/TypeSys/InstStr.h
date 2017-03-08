/*
 * InstStr.h
 *
 *  Created on: Mar 2, 2017
 *      Author: luy57690
 */

#ifndef SRC_TYPESYS_INSTSTR_H_
#define SRC_TYPESYS_INSTSTR_H_

#include "InstVar.h"

class InstStr: public InstVar {
public:
	InstStr();
	virtual ~InstStr();
private:
	long length;
};

#endif /* SRC_TYPESYS_INSTSTR_H_ */
