/*
 * TType.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#include "TType.h"

TType::TType() {
	// TODO Auto-generated constructor stub

}

TType::~TType() {
	// TODO Auto-generated destructor stub
}

bool TType::isIsDummy() const {
	return isDummy;
}

void TType::setIsDummy(bool isDummy) {
	this->isDummy = isDummy;
}

bool TType::isIsGnrc() const {
	return isGnrc;
}

void TType::setIsGnrc(bool isGnrc) {
	this->isGnrc = isGnrc;
}
