/*
 * RVar.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#include "RVar.h"

RVar::RVar() {
	// TODO Auto-generated constructor stub

}

RVar::~RVar() {
	// TODO Auto-generated destructor stub
}

long RVar::getMark() const {
	return mark;
}

void RVar::setMark(long mark) {
	this->mark = mark;
}

long RVar::getType() const {
	return type;
}

void RVar::setType(long type) {
	this->type = type;
}

