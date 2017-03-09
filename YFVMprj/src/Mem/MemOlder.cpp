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
	free(this->block_ptr);
	delete[] mark_table;
}

int MemOlder::initSize(long size) {
	this->block_ptr=malloc(size);
	this->mark_table=new char[size/4];
	if(this->block_ptr==nullptr)return -1;
	return 0;
}

long MemOlder::cpyObj(void* src_ptr, long size) {
	long new_ptr=pushObj(size);
	memcpy(getAddrPtr(new_ptr),src_ptr,size);//update mark table and free list
	return addr_begin+(new_ptr-block_ptr);
}

long MemOlder::pushObj(long size) {
	//get first fitting
	long addr=-1;
	for(list<long[2]>::iterator it=free_list.iterator;it!=free_list.end();){
		if((*it)[0]-(*it)[1]>size){
			addr=(*it)[0];
			(*it)[0]+=size;
			markObj(addr,1);
			free_size-=size;
			return addr;
		}else if((*it)[0]-(*it)[1]==size){
			addr=(*it)[0];
			free_list.erase(it);
			markObj(addr,1);
			free_size-=size;
			return addr;
		}else{
			it++;
		}
	}
	return addr;
}

int MemOlder::markObj(long addr1, char c) {
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

long MemOlder::getFreeSize() {
	return this->free_size;
}

long MemOlder::getMaxFree() {
	long size=-1;
	for(list<long[2]>::iterator it=free_list.iterator;it!=free_list.end();it++){
		if((*it)[0]-(*it)[1]>size){
			size=(*it)[0]-(*it)[1];
		}
	}
	return size;
}

long MemOlder::getFirstFree(long size) {
	for(list<long[2]>::iterator it=free_list.iterator;it!=free_list.end();it++){
		if((*it)[0]-(*it)[1]>size){
			return (*it)[0]-(*it)[1];
		}
	}
	return -1;
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

void* MemOlder::getAddrPtr(long addr1) {
	long addr=addr1-addr_begin;
	return this->block_ptr+addr-addr_begin;
}

char MemOlder::getMarkAddr(long addr1) {
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

void MemOlder::updateFreeList() {
	long begin=this->addr_begin;
	long end=this->addr_begin;
	for(long i=addr_begin;i<addr_end;i++){
		char c=getMarkAddr(i);
		if(c==1||c==3){
			end=i;
			InstVar* var=(InstVar*) getAddrPtr(i);
			long size=stcz->getTypeFromList(var->getType())->getSize();
			if(begin!=end){
				long f[2]={begin,end};
				free_list.push_back(f);
			}
			begin=end+size;
		}
	}
	if(end<begin){
		long f[2]={begin,addr_end};
		free_list.push_back(f);
	}
}

int MemOlder::ZeroMarkTbl() {
	delete[] mark_table;
	this->mark_table=new char[(addr_end-addr_begin)/4];
	return 0;
}

int MemOlder::resetFreeList() {
	free_list.clear();
	free_size=addr_end-addr_begin;
	long f[2]={addr_begin, addr_end};
	free_list.push_back(f);
	return 0;
}
void MemOlder::setStcz(StaticZone* stcz) {
		this->stcz = stcz;
	}
