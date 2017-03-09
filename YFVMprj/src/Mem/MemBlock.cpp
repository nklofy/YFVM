/*
 * MemBlock.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: luyunfei
 */

#include "MemBlock.h"

MemBlock::MemBlock() {
	// TODO Auto-generated constructor stub

}

MemBlock::~MemBlock() {
	free(this->block_ptr);
	delete[] mark_table;
}

int MemBlock::initSize(long size) {
	this->block_ptr=malloc(size);
	this->mark_table=new char[size/4];
	if(this->block_ptr==nullptr)return -1;
	return 0;
}

long MemBlock::cpyObj(void* src_ptr, long size) {
	void* new_ptr=getAddrPtr(free_begin);
	memcpy(new_ptr,src_ptr,size);
	free_begin+=size;
	return free_begin;
}

long MemBlock::pushObj(long size) {
	free_begin+=size;
	return free_begin;
}

int MemBlock::markObj(long addr1, char c) {
	long addr=addr1-addr_begin;
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

long MemBlock::getFreeSize() {
	return this->addr_end-this->free_begin;
}

long MemBlock::extend(long new_size) {
	this->block_ptr=realloc(block_ptr,new_size);
	delete[] mark_table;
	mark_table=new char[new_size/4];
	if(this->block_ptr==nullptr)return -1;
	return 0;
}

long MemBlock::getAddrBegin() {
	return this->addr_begin;
}

void MemBlock::setAddrBegin(long ad) {
	this->addr_begin=ad;
}

long MemBlock::getAddrEnd() {
	return this->addr_end;
}

void MemBlock::setAddrEnd(long ad) {
	this->addr_end=ad;
}

long MemBlock::getFreeBegin() {
	return free_begin;
}

char MemBlock::getMarkAddr(long addr1) {
	long addr=addr1-addr_begin;
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

void* MemBlock::getAddrPtr(long addr) {
	return this->block_ptr+addr-addr_begin;
}

int MemBlock::ZeroMarkTbl() {
	delete[] mark_table;
	this->mark_table=new char[(addr_end-addr_begin)/4];
}
