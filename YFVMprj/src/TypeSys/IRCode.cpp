/*
 * IRCode.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#include "IRCode.h"

IRCode::IRCode() {
	// TODO Auto-generated constructor stub

}
IRCode::IRCode(string s) {
	// TODO

}
IRCode::~IRCode() {
	// TODO Auto-generated destructor stub
}

string IRCode::getOpd1() const {
	return opd1;
}

string IRCode::getOpd2() const {
	return opd2;
}

string IRCode::getOpd3() const {
	return opd3;
}

string IRCode::getOpt() const {
	return opt;
}

int IRCode::setLine(string s){
	return 0;
}
