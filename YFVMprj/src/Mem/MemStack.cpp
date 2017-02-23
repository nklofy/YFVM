/*
 * MemStack.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#include "MemStack.h"

MemStack::MemStack() : bottom(0),top(0),capacity(1024) {
	real_bottom=new T_element[capacity*width];
	real_top=real_bottom+capacity*width;
}

MemStack::~MemStack() {
	delete[] real_bottom;
}

void MemStack::setTop(long nt) {
	this->top=nt;
}

T_element& MemStack::fetch(long index) {
	T_element* p=(T_element*)(this->real_bottom+index*width);
	return (*p);
}

T_element& MemStack::peak() {
	T_element* p=(T_element*)(this->real_bottom+width*top);
	return (*p);
}

T_element* MemStack::push() {
	if(this->top>=this->capacity-1){
		if(!this->extend()){
			cerr<<"not enough space for stack extending"<<endl;return NULL;
		}
	}
	this->top++;
	T_stackele* p=this->real_bottom+width*top;
	T_element* pv=new(p) T_element;
	return pv;
}

T_element& MemStack::pop() {
	T_element* p=(T_element*)(this->real_bottom+width*top);
	this->top--;
	return (*p);
}

int MemStack::modify(long addr,T_element& e){
	return -1;
}
int MemStack::extend() {
	double newc=ext_ratio*(double)capacity*(double)width;	//new capacity
	if(newc*sizeof(T_stackele)>=this->max_long){
		cerr<<"error too large stack"<<endl;
		return -1;
	}
	this->capacity=newc;
	T_stackele* newp=new T_stackele[capacity*width];	//new bottom
	memcpy(newp,this->real_bottom, width*(top+1));
	this->real_bottom=newp;
	this->real_top=newp+width*this->capacity;
	return 0;
}


int MemStack::shrink() {
	double newc=(double)capacity*(double)width/ext_ratio;	//new capacity
	this->capacity=newc;
	T_stackele* newp=new T_stackele[capacity*width];	//new bottom
	memcpy(newp,this->real_bottom, width*(top+1));
	this->real_bottom=newp;
	this->real_top=newp+width*this->capacity;
	return 0;
}
