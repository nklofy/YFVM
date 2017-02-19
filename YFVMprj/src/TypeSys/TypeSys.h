/*
 * TypeSys.h
 *
 *  Created on: Jan 12, 2017
 *      Author: luy57690
 */

#ifndef SRC_TYPESYS_TYPESYS_H_
#define SRC_TYPESYS_TYPESYS_H_


#include "AbstArray.h"
#include "AbstBasic.h"
#include "AbstClass.h"
#include "AbstFunc.h"
#include "AbstType.h"
#include "InstArray.h"
#include "InstBasic.h"
#include "InstObj.h"
#include "InstVar.h"
#include "RcdValue.h"

typedef long AddrFrmt;


class TypeSys {
public:
	TypeSys();
	virtual ~TypeSys();
};

#endif /* SRC_TYPESYS_TYPESYS_H_ */
