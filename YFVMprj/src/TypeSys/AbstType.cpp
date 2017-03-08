/*
 * TType.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#include "AbstType.h"

AbstType::AbstType() {
	// TODO Auto-generated constructor stub

}

AbstType::~AbstType() {
	// TODO Auto-generated destructor stub
}

bool AbstType::isIsDummy() const {
	return isDummy;
}

void AbstType::setIsDummy(bool isDummy) {
	this->isDummy = isDummy;
}

bool AbstType::isIsGnrc() const {
	return isGnrc;
}

void AbstType::setIsGnrc(bool isGnrc) {
	this->isGnrc = isGnrc;
}
