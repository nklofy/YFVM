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
	long pushStack(ValueK,RRValue);
	DatValue& popStack();
	DatValue& peekStack();
	DatValue& fetchStack(long);
	void setTopAddr(long);
	long getTopAddr();
	long getSizeStk();

	//heap operation
	InstVar* fetchObj(long);
	long mallocObj(long);
	long callocObj(long,long);
	long reallocObj(long,long);
	int freeHObj(long);
	long allocStr(long);
	int cpyStr(long,string&);
	int cpyMem(long,long);
	int cpyValue(long,DatValue&);
	int initObj(long);
	long getSizeHp();
private:
	Mem_Stack stack;//ebp: link for searching; -1: return adress; -2: last frame's ebp; -3: args; 1: pars
	Mem_Heap heap;
};

#endif /* SRC_MEMMANAGER_H_ */
