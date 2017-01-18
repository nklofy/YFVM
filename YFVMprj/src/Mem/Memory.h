/*
 * Memory.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMORY_H_
#define SRC_MEM_MEMORY_H_

#include "MZheap.h"
#include "MZstack.h"
#include "MZdata.h"

class Memory {
public:
	Memory();
	virtual ~Memory();
	const MZdata*& getData() const;
	void setData(const MZdata*& data);
	const MZheap*& getHeap() const;
	void setHeap(const MZheap*& heap);
	const MZstack*& getStack() const;
	void setStack(const MZstack*& stack);

private:
	MZheap* heap;
	MZstack* stack;
	MZdata* data;
};

#endif /* SRC_MEM_MEMORY_H_ */
