/*
 * TFunc.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: luyunfei
 */

#include "AbstFunc.h"

AbstFunc::AbstFunc() {
	// TODO Auto-generated constructor stub

}

AbstFunc::~AbstFunc() {
	//todo, delete pars n types
}


const AbstGnrc*& AbstFunc::getGnrcPars() const {
	return gnrc_pars;
}

void AbstFunc::setGnrcPars(const AbstGnrc*& gnrcPars) {
	gnrc_pars = gnrcPars;
}

RcdFunc*& AbstFunc::getFunc() const {
	return r_func;
}

void AbstFunc::setFunc(RcdFunc*& func) {
	r_func = func;
}

bool AbstFunc::isIsMthd() const {
	return isMthd;
}

void AbstFunc::setIsMthd(bool isMthod) {
	this->isMthd = isMthod;
}
