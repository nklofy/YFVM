/*
 * MemManager.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#include "MemManager.h"

MemManager::MemManager() {
	// TODO Auto-generated constructor stub

}

MemManager::~MemManager() {
	// TODO Auto-generated destructor stub
}


void MemManager::pushStack(ValueK v, RRValue& r) {
	DatValue* d=this->stack.push();
	d->valuek=v;
	d->value=r;
}

DatValue& MemManager::popStack() {
	return this->stack.pop();
}

DatValue& MemManager::peekStack() {
	return this->stack.peak();
}

DatValue& MemManager::fetchStack(long i) {
	return this->stack.fetch(i);
}

//int MemManager::modifyStack(long a, DatValue& v) {
//	return -1;
//}

int MemManager::setStackTop(long top) {
	if(top>stack.getTop())
		return -1;
	stack.setTop(top);
		return 0;
}

long MemManager::getStackTop() {
	return stack.getTop();
}

long MemManager::allocStr(long longInt) {
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
InstVar* MemManager::fetchObj(long longInt) {
}

long MemManager::mallocObj(long longInt) {
}

long MemManager::callocObj(long longInt, long longInt1) {
}

long MemManager::reallocObj(long longInt, long longInt1) {
}

int MemManager::freeHObj(long longInt) {
}

int MemManager::cpyStr(long longInt, string& allocator) {
}

int MemManager::cpyMem(long longInt, long longInt1) {
}

int MemManager::modifyObj(long longInt, DatValue&) {
}

int MemManager::initObj(long longInt) {
}

long MemManager::getSizeHp() {
}
