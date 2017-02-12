/*
 * Memory.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMORY_H_
#define SRC_MEM_MEMORY_H_



class Memory {
public:
	Memory();
	virtual ~Memory();


private:
	Mem_Stack stack;
	Mem_Heap heap;
};

#endif /* SRC_MEM_MEMORY_H_ */
