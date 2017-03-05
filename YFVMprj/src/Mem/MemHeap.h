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


	static long max_long;

	MemHeap();
	virtual ~MemHeap();
	int init();
	long mallocObj(long);
	void* fetchObj(long);
	long mallocStr(string&);
	long mallocArray(long,long);
	void setStcz(StaticZone* stcz);

private:
	StaticZone* stcz;
	GCAlgo GCer;
	MemBlock eden;	//eden generation
	MemBlock* crt_svr=new MemBlock;	//survivor generation
	MemBlock* next_svr=new MemBlock;
	MemOlder older;	//older generation
	long block_size=0XFFFF;//65k, actually 500k
	long eden_size=0X4FFFF;//256k,actually 2M
	long svr_size=0X4FFFF;//256k,actually 2M
	long older_size=0XFFFFF;//1M, actually 8m
	//long addr_begin=0;
	//long addr_end=0;

	int doGC();
	int markMBlock(MemBlock&);
	long cpyMBlock(MemBlock&, MemBlock&);
	int doFullGC();
	int markAllObj();
	long sweepAllObj();
	long compactMBlock();
	int extendEden(double);
	int extendSvr(double);
	int extendOlder(double);

public:
	static double eden_thresh1;
	static double eden_thresh2;
	static double eden_ext1;
	static double eden_ext2;
	static double svr_thresh1;
	static double svr_thresh2;
	static double svr_ext1;
	static double svr_ext2;
	static double older_thresh1;
	static double older_thresh2;
	static double older_ext1;
	static long max_Mem;
	static long max_singleMem;
	static long bigObj_size;
	//copy eden to survivor, free <0.5, *2
	//copy svr to svr, if free <1/4, svr *2, free>7/8, svr*0.5
	//if older is full do mark-sweep full GC
	//cpr >3/4, older *2
	//cpr >1/2, do mark-compact GC
};

#endif /* SRC_MEM_MEMHEAP_H_ */
