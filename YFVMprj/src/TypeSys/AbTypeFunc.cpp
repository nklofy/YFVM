/*
 * TFunc.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: luyunfei
 */

#include "AbTypeFunc.h"

AbTypeFunc::AbTypeFunc() {
	// TODO Auto-generated constructor stub

}

AbTypeFunc::~AbTypeFunc() {
	//todo, delete pars n types
}

list<string>& AbTypeFunc::getParNames(){
	return parnames;
}

string& AbTypeFunc::getName() {
	return this->name;
}

void AbTypeFunc::setName(string allocator) {
this->name=name;
}

const string& AbTypeFunc::getSig() {
return this->sig;
}

void AbTypeFunc::setSig(const string& sig) {
	this->sig=sig;
}

vector<IRCode*>* AbTypeFunc::getBody() {
return this->body;
}

void AbTypeFunc::setBody(vector<IRCode*>* body) {
this->body=body;
}

void AbTypeFunc::addNext(AbTypeFunc*) {
}

AbTypeFunc* AbTypeFunc::getNext() {
	return this->next;
}

long AbTypeFunc::getEntry() {
}

void AbTypeFunc::setEntry(long longInt) {
}

list<string>& AbTypeFunc::getParTypes(){
	return partypes;
}

long AbTypeFunc::getIndex()  {
	return index;
}

void AbTypeFunc::setIndex(long index) {
	this->index = index;
}

unordered_map<string, long>& AbTypeFunc::getSymInner() {
	return sym_inner;
}

void AbTypeFunc::setSymInner(unordered_map<string, long>& symInner) {
	sym_inner = symInner;
}
