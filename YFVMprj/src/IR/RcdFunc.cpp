/*
 * RcdFunc.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#include "RcdFunc.h"

RcdFunc::RcdFunc() {
	// TODO Auto-generated constructor stub

}

RcdFunc::~RcdFunc() {
	// TODO Auto-generated destructor stub
}

const string& RcdFunc::getName() const {
	return name;
}

void RcdFunc::setName(const string& name) {
	this->name = name;
}

const string& RcdFunc::getSig() const {
	return signature;
}

void RcdFunc::setSig(const string& signature) {
	this->signature = signature;
}

const string& RcdFunc::getScope() const {
	return scope;
}

void RcdFunc::setScope(const string& scope) {
	this->scope = scope;
}

vector<IRCode*>& RcdFunc::getBody(){
	return body;
}

void RcdFunc::setBody(const vector<IRCode*>& body) {
	this->body = body;
}

int RcdFunc::getRows() const {
	return rows;
}

void RcdFunc::setRows(int rows) {
	this->rows = rows;
}
list<IRCode*>& RcdFunc::getPars(){
	return this->pars;
}
