/*
 * MemHeap.h
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMHEAP_H_
#define SRC_MEM_MEMHEAP_H_

#include <string>
#include "../TypeSys/TypeSys.h"
#include "GCAlgo.h"

using namespace std;

class MemHeap {
friend GCAlgo;
public:

	//typedef char T_element;
	typedef char T_grid;
	//static int width;
	static double ext_ratio;
	static long max_long;

	MemHeap();
	virtual ~MemHeap();
	int init();
	long mallocObj(long);
	long mallocStr(string&);
	long mallocArray(long,long);

	int freeObj(long);
	int freeArray(long);

private:
	GCAlgo gcer;
	int GC();//total 80%, run GC,
	void** blocks;
	long block_begin;	//begin of available block
	long block_end;	//end of available block
	long* block_ptrB;	//begin ptr of each block
	long* block_ptrE;	//end ptr of each block
	long block_size=0XFFFF;//65k, actually 500k
	long block_count=8;
	char* block_info;	//0 empty, 1b in using, 10b full, 000b eden, 100b survivor
	void* older;
	long older_size=0XFFFFF;//1M, actually 8m
	double block_u_ratio;
	double older_u_ratio;
	long* stack_stab;
	long* older_stab;
	long** block_stab;
	int resetBlockSize(long);
	int resetBlockCount(long);
	int resetOlderSize(long);

};

#endif /* SRC_MEM_MEMHEAP_H_ */
