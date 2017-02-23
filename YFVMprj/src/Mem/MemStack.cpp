/*
 * MemStack.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#include "MemStack.h"

template<typename T> MemStack<T>::MemStack() : bottom(0),top(0),capacity(1024) {
	real_bottom=new T[capacity*width];
	real_top=real_bottom+capacity*width;
}

template<typename T> MemStack<T>::~MemStack() {
	delete[] real_bottom;
}

template<typename T> int MemStack<T>::setTop(long nt) {
	this->top=nt;
	return 0;
}

template<typename T> T& MemStack<T>::fetch(long index) {
	T* p=(T*)(this->real_bottom+index*width);
	return (*p);
}

template<typename T> T& MemStack<T>::peak() {
	T* p=(T*)(this->real_bottom+width*top);
	return (*p);
}

template<typename T> T* MemStack<T>::push() {
	if(this->top>=this->capacity-1){
		if(!this->extend()){
			cerr<<"not enough space for stack extending"<<endl;return NULL;
		}
	}
	this->top++;
	T_element* p=this->real_bottom+width*top;
	T* pv=new(p) T;
	return pv;
}

template<typename T> T& MemStack<T>::pop() {
	T* p=(T*)(this->real_bottom+width*top);
	this->top--;
	return (*p);
}

template<typename T> int MemStack<T>::modify(long addr,T& e){
	return -1;
}
template<typename T> int MemStack<T>::extend() {
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

template<typename T>
inline long MemStack<T>::getTop() {
	return top;
}

template<typename T> int MemStack<T>::shrink() {
	double newc=(double)capacity*(double)width/ext_ratio;	//new capacity
	this->capacity=newc;
	T_element* newp=new T_element[capacity*width];	//new bottom
	memcpy(newp,this->real_bottom, width*(top+1));
	this->real_bottom=newp;
	this->real_top=newp+width*this->capacity;
	return 0;
}
