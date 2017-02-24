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

list<string>& AbstFunc::getParNames(){
	return parnames;
}

string AbstFunc::getName() {
}

void AbstFunc::setName(string allocator) {
}

const string& AbstFunc::getSig() {
}

void AbstFunc::setSig(const string& sig) {
}

vector<IRCode*>* AbstFunc::getBody() {
}

void AbstFunc::setBody(vector<IRCode*>* allocator) {
}

void AbstFunc::addNext(AbstFunc*) {
}

AbstFunc* AbstFunc::getNext() {
}

long AbstFunc::getEntry() {
}

void AbstFunc::setEntry(long longInt) {
}

list<string>& AbstFunc::getParTypes(){
	return partypes;
}
