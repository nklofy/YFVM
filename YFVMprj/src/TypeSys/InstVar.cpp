/*
 * RVar.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#include "InstVar.h"

InstVar::InstVar() {
	// TODO Auto-generated constructor stub

}

InstVar::~InstVar() {
	// TODO Auto-generated destructor stub
}

long InstVar::getMark() const {
	return mark;
}

void InstVar::setMark(long mark) {
	this->mark = mark;
}

long InstVar::getType() const {
	return type;
}

void InstVar::setType(long type) {
	this->type = type;
}

