/*
 * MemHeap.h
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMHEAP_H_
#define SRC_MEM_MEMHEAP_H_

#include <string>
#include <list>

#include "../TypeSys/TypeSys.h"
#include "GCAlgo.h"

using namespace std;

class MemHeap {
friend GCAlgo;
public:

	static double block_ext;
	static double block_ext1;
	static double eden_cpr;
	static double eden_cpr1;
	static double svr_cpr;
	static double

	static long max_long;

	MemHeap();
	virtual ~MemHeap();
	int init();
	long mallocObj(long);
	long mallocStr(string&);
	long mallocArray(long,long);

private:
	GCAlgo GCer;
	MemBlock eden;	//eden generation
	MemBlock svr0;	//survivor generation
	MemBlock svr1;
	MemOlder older;	//older generation

	long block_size=0XFFFF;//65k, actually 500k
	long eden_size=0X4FFFF;//256k,actually 2M
	long svr_size=0X2FFFF;//128k,actually 1M
	long older_size=0XFFFFF;//1M, actually 8m
	long addr_begin=0;
	long addr_end=0;
	long bigObj_size;
	int doGC();
	int doFullGC();
	int extendEden();
	int extendSvr();
	int extendOlder();
};

#endif /* SRC_MEM_MEMHEAP_H_ */
