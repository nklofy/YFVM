/*
 * Memory.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#include "Memory.h"

Memory::Memory() {
	// TODO Auto-generated constructor stub

}

Memory::~Memory() {
	// TODO Auto-generated destructor stub
}

const MZdata*& Memory::getData() const {
	return data;
}

void Memory::setData(const MZdata*& data) {
	this->data = data;
}

const MZheap*& Memory::getHeap() const {
	return heap;
}

void Memory::setHeap(const MZheap*& heap) {
	this->heap = heap;
}

const MZstack*& Memory::getStack() const {
	return stack;
}

void Memory::setStack(const MZstack*& stack) {
	this->stack = stack;
}
