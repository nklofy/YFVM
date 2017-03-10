/*
 * MemManager.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#include "MemManager.h"

long MemManager::max_Mem=LONG_MAX;
long MemManager::max_singleMem=0XFFFFFFFFFFFF;
long MemManager::VWidth=AbstType::VWidth;

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

/*
long MemManager::allocStr(long longInt) {
}
int MemManager::cpyStr(long longInt, string& allocator) {
}*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
InstVar* MemManager::fetchObj(long addr) {
	return (InstVar*)(this->heap.fetchObj(addr));
}

long MemManager::mallocObj(long size) {
	return this->heap.mallocObj(size);
}

long MemManager::callocObj(long size, long count) {

}

long MemManager::reallocObj(long size, long new_size) {

}

int MemManager::freeHObj(long addr) {
	return 0;
}


int MemManager::cpyMem(long addr1, long addr2) {
	return heap.cpyMem(addr1,addr2);
}

int MemManager::modifyObj(long addr, DatValue&) {
	return 0;
}

int MemManager::initObj(long addr) {
	return 0;
}

int MemManager::setStcz(StaticZone* stcz) {
	heap.setStcz(stcz);
	stack.setStcz(stcz);
}

long MemManager::getHpSize() {
	return heap.eden_size+heap.svr_size+heap.older_size;

}
