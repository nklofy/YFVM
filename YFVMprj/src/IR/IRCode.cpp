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

string& IRCode::getOpd1() {
	return opd1;
}

string& IRCode::getOpd2()  {
	return opd2;
}

string& IRCode::getOpd3()  {
	return opd3;
}

string& IRCode::getOpt()  {
	return opt;
}

IRCode::IRCode(IRCode&) {
}

int IRCode::setLine(string s){
	return 0;
}
