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

IRCode::~IRCode() {
	// TODO Auto-generated destructor stub
}

string IRCode::getOpd1() const {
	return opd1;
}

void IRCode::setOpd1(string opd1) {
	this->opd1 = opd1;
}

string IRCode::getOpd2() const {
	return opd2;
}

void IRCode::setOpd2(string opd2) {
	this->opd2 = opd2;
}

string IRCode::getOpd3() const {
	return opd3;
}

void IRCode::setOpd3(string opd3) {
	this->opd3 = opd3;
}

string IRCode::getOpt() const {
	return opt;
}

void IRCode::setOpt(string opt) {
	this->opt = opt;
}
