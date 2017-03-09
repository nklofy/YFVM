/*
 * MemOlder.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: luyunfei
 */

#include "MemOlder.h"

MemOlder::MemOlder() {
	// TODO Auto-generated constructor stub

}

MemOlder::~MemOlder() {
	// TODO Auto-generated destructor stub
}

int MemOlder::initSize(long size) {
	this->block_ptr=malloc(size);
	this->mark_table=new char[size/4];
	if(this->block_ptr==nullptr)return -1;
	return 0;
}

long MemOlder::cpyObj(void* src_ptr, long size) {
	void* new_ptr=pushObj(size);
	memcpy(new_ptr,src_ptr,size);
	return addr_begin+(new_ptr-block_ptr);
}

long MemOlder::pushObj(long size) {
	/////////////



}

int MemOlder::markObj(long addr, char c) {
	long i=addr/4;
	int clr=addr%4;
	if(clr==0){
		mark_table[i]=(mark_table[i]>>2)<<2+c;
	}else if(clr==1){
		int t=mark_table[i]&0b11;
		mark_table[i]=((mark_table[i]>>4)<<2+c)<<2+t;
	}else if(clr==2){
		int t=mark_table[i]&0b1111;
		mark_table[i]=((mark_table[i]>>6)<<4+c)<<4+t;
	}else if(clr==3){
		int t=mark_table[i]&0b111111;
		mark_table[i]=c<<6+t;
	}
	return 0;

}

long MemOlder::getFreeSize() {
	return this->free_size;
}

long MemOlder::getMaxFree() {
	return this->free_max;
}

long MemOlder::getBestFitFree(long longInt) {///////////

}

long MemOlder::extend(long new_size) {
	this->block_ptr=realloc(block_ptr,new_size);
	delete[] mark_table;
	mark_table=new char[new_size/4];
	if(this->block_ptr==nullptr)return -1;
	return 0;

}

long MemOlder::getAddrBegin() {
	return this->addr_begin;
}

void MemOlder::setAddrBegin(long a) {
	this->addr_begin=a;
}

long MemOlder::getAddrEnd() {
	return this->addr_end;
}

void MemOlder::setAddrEnd(long a) {
	this->addr_end=a;
}

void* MemOlder::getAddrPtr(long addr) {
	return this->block_ptr+addr-addr_begin;
}

char MemOlder::getMarkAddr(long addr) {
	long i=addr/4;
	int clr=addr%4;
	if(clr==0){
		return mark_table[i]&0b11;
	}else if(clr==1){
		return mark_table[i]&0b1100;
	}else if(clr==2){
		return mark_table[i]&0b110000;
	}else if(clr==3){
		return mark_table[i]&0b11000000;
	}
	return 0;

}

void MemOlder::updateFreeList() {///////

}

int MemOlder::ZeroMarkTbl() {
	delete[] mark_table;
	this->mark_table=new char[(addr_end-addr_begin)/4];
}

int MemOlder::resetFreeList() {//////////////

}
