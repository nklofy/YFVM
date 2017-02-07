/*
 * TClass.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#include "TClass.h"

TClass::TClass() {
	// TODO Auto-generated constructor stub

}

TClass::~TClass() {
	// TODO Auto-generated destructor stub
}

const TGnrc*& TClass::getGnrcPars() const {
	return gnrc_pars;
}

void TClass::setGnrcPars(const TGnrc*& gnrcPars) {
	gnrc_pars = gnrcPars;
}
