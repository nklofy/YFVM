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
	Mem_Stack stack;//ebp: link for searching; -1: return adress; -2: last frame's ebp; -3: args; 1: pars
	Mem_Heap heap;
};

#endif /* SRC_MEMMANAGER_H_ */
