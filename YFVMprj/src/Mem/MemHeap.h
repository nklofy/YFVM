/*
 * MemHeap.h
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMHEAP_H_
#define SRC_MEM_MEMHEAP_H_

class MemHeap {
public:
	MemHeap();
	virtual ~MemHeap();
	int init();
	long mallocObj(long);
	long mallocStr(string&);
	long mallocArray(long,long);

	int freeObj(long);
	int freeArray(long);

private:
	int GC();
	void* block;
	long block_size=0XFFFF;
	long block_count=7;
	char* block_info;
	long* stack_stab;
	long** block_stab;
	int resetBlockSize(long);
	int resetBlockCount(long);

};

#endif /* SRC_MEM_MEMHEAP_H_ */
