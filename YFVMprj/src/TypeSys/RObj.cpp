/*
 * RObj.cpp
 *
 *  Created on: Feb 1, 2017
 *      Author: luyunfei
 */

#include "RObj.h"

RObj::RObj() {
	// TODO Auto-generated constructor stub

}

RObj::~RObj() {
	// TODO Auto-generated destructor stub
}

const RValue& RObj::getValue() const {
	return value;
}

void RObj::setValue(const RValue& value) {
	this->value = value;
}
