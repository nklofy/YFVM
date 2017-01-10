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

int IRCode::getOpd1() const {
	return opd1;
}

void IRCode::setOpd1(int opd1) {
	this->opd1 = opd1;
}

int IRCode::getOpd2() const {
	return opd2;
}

void IRCode::setOpd2(int opd2) {
	this->opd2 = opd2;
}

int IRCode::getOpd3() const {
	return opd3;
}

void IRCode::setOpd3(int opd3) {
	this->opd3 = opd3;
}

int IRCode::getOpt() const {
	return opt;
}

void IRCode::setOpt(int opt) {
	this->opt = opt;
}
