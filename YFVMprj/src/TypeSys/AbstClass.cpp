/*
 * TClass.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#include "AbstClass.h"

AbstClass::AbstClass() {
	// TODO Auto-generated constructor stub

}

AbstClass::~AbstClass() {
	// TODO Auto-generated destructor stub
}

const AbstGnrc*& AbstClass::getGnrcPars() const {
	return gnrc_pars;
}

void AbstClass::setGnrcPars(const AbstGnrc*& gnrcPars) {
	gnrc_pars = gnrcPars;
}
