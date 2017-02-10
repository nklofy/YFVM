/*
 * TFunc.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: luyunfei
 */

#include "TFunc.h"

TFunc::TFunc() {
	// TODO Auto-generated constructor stub

}

TFunc::~TFunc() {
	//todo, delete pars n types
}


const TGnrc*& TFunc::getGnrcPars() const {
	return gnrc_pars;
}

void TFunc::setGnrcPars(const TGnrc*& gnrcPars) {
	gnrc_pars = gnrcPars;
}

RcdFunc*& TFunc::getFunc() const {
	return r_func;
}

void TFunc::setFunc(RcdFunc*& func) {
	r_func = func;
}
