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

string& AbstFunc::getName() {
	return this->name;
}

void AbstFunc::setName(string allocator) {
this->name=name;
}

const string& AbstFunc::getSig() {
return this->sig;
}

void AbstFunc::setSig(const string& sig) {
	this->sig=sig;
}

vector<IRCode*>* AbstFunc::getBody() {
return this->body;
}

void AbstFunc::setBody(vector<IRCode*>* body) {
this->body=body;
}

void AbstFunc::addNext(AbstFunc*) {
}

AbstFunc* AbstFunc::getNext() {
	return this->next;
}

long AbstFunc::getEntry() {
}

void AbstFunc::setEntry(long longInt) {
}

list<string>& AbstFunc::getParTypes(){
	return partypes;
}

long AbstFunc::getIndex()  {
	return index;
}

void AbstFunc::setIndex(long index) {
	this->index = index;
}

map<string, long>& AbstFunc::getSymInner() {
	return sym_inner;
}

void AbstFunc::setSymInner(map<string, long>& symInner) {
	sym_inner = symInner;
}
