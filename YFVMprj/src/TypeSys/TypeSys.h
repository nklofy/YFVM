/*
 * TypeSys.h
 *
 *  Created on: Jan 12, 2017
 *      Author: luy57690
 */

#ifndef SRC_TYPESYS_TYPESYS_H_
#define SRC_TYPESYS_TYPESYS_H_


#include "AbstType.h"
#include "AbTypeArray.h"
#include "AbTypeBasic.h"
#include "AbTypeClass.h"
#include "AbTypeFunc.h"
#include "InstArray.h"
#include "InstBasic.h"
#include "InstObj.h"
#include "InstVar.h"
#include "DatValue.h"

typedef long AddrFrmt;


class TypeSys {
public:
	TypeSys();
	virtual ~TypeSys();
};

#endif /* SRC_TYPESYS_TYPESYS_H_ */
