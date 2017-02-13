/*
 * MemManager.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_MEMMANAGER_H_
#define SRC_MEMMANAGER_H_
#include "Mem/Memory.h"

class MemManager {
public:
	MemManager();
	virtual ~MemManager();

	//stack operation
	long pushStack(RValueK,RRValue);
	RValue& popStack();
	RValue& peekStack();
	RValue& fetchStack(long);
	void setTopAddr(long);
	long getTopAddr();
	long getSizeStk();
	//heap operation
	long allocObj(long);
	void freeHObj(long);
	long getSizeHp();
private:
	Mem_Stack stack;
	Mem_Heap heap;
};

#endif /* SRC_MEMMANAGER_H_ */
