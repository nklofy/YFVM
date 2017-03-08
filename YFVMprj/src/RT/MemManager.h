/*
 * MemManager.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_MEMMANAGER_H_
#define SRC_MEMMANAGER_H_
#include "../Mem/Memory.h"
#include "../TypeSys/TypeSys.h"

class MemManager {
public:
	MemManager();
	virtual ~MemManager();

	//stack operation
	void pushStack(ValueK,RRValue&);
	DatValue& popStack();
	DatValue& peekStack();
	DatValue& fetchStack(long);
	//int modifyStack(long, DatValue&);
	int setStackTop(long);
	long getStackTop();

	//heap operation
	InstVar* fetchObj(long);
	long mallocObj(long);
	long callocObj(long,long);
	long reallocObj(long,long);
	int freeHObj(long);
	long allocStr(long);
	int cpyStr(long,string&);
	int cpyMem(long,long);
	int modifyObj(long,DatValue&);
	int initObj(long);
	long getSizeHp();
private:
	MemStack stack;//ebp: link for searching; -1: return adress; -2: last frame's ebp; 1: pars
	MemHeap heap;
};

#endif /* SRC_MEMMANAGER_H_ */
