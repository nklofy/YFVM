/*
 * MemStack.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#include "MemStack.h"

int MemStack::width=sizeof(DatValue)/sizeof(T_element);
int MemStack::cwidth=sizeof(T_element);
int MemStack::org_height=1024;
double MemStack::ext_ratio=2;
long MemStack::max_long=0XFFFFFFFFFFFFFFFF;

MemStack::MemStack() : bottom(0),top(0),capacity(1024) {
	real_bottom=new T_element[capacity*width];
	real_top=real_bottom+capacity*width;
}

MemStack::~MemStack() {
	delete[] real_bottom;
}

int MemStack::setTop(long nt) {
	this->top=nt;
	return 0;
}

DatValue& MemStack::fetch(long index) {
	DatValue* p=(DatValue*)(this->real_bottom+index*width);
	return (*p);
}

DatValue& MemStack::peak() {
	DatValue* p=(DatValue*)(this->real_bottom+width*top);
	return (*p);
}

DatValue* MemStack::push() {
	if(this->top>=this->capacity-1){
		if(!this->extend()){
			cerr<<"not enough space for stack extending"<<endl;return NULL;
		}
	}
	this->top++;
	T_element* p=this->real_bottom+width*top;
	DatValue* pv=new(p) DatValue;
	return pv;
}

DatValue& MemStack::pop() {
	DatValue* p=(DatValue*)(this->real_bottom+width*top);
	this->top--;
	return (*p);
}

int MemStack::modify(long addr,DatValue& e){
	return -1;
}
int MemStack::extend() {
	double newc=ext_ratio*(double)capacity*(double)width;	//new capacity
	if(newc*sizeof(T_element)>=this->max_long){
		cerr<<"error too large stack"<<endl;
		return -1;
	}
	this->capacity=newc;
	T_element* newp=new T_element[capacity*width];	//new bottom
	memcpy(newp,this->real_bottom, width*(top+1));
	this->real_bottom=newp;
	this->real_top=newp+width*this->capacity;
	return 0;
}

long MemStack::getTop() {
	return top;
}

int MemStack::shrink() {
	double newc=(double)capacity*(double)width/ext_ratio;	//new capacity
	this->capacity=newc;
	T_element* newp=new T_element[capacity*width];	//new bottom
	memcpy(newp,this->real_bottom, width*(top+1));
	this->real_bottom=newp;
	this->real_top=newp+width*this->capacity;
	return 0;
}
