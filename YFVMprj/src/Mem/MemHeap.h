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
#include "MemBlock.h"
#include "MemOlder.h"
using namespace std;

class MemHeap {
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
	void setStack(MemStack* stack);
	int cpyMem(long,long);

private:
	StaticZone* stcz;
	MemStack* stack;
	MemBlock eden;	//eden generation
	MemBlock* crt_svr=new MemBlock;	//survivor generation
	MemBlock* next_svr=new MemBlock;
	MemOlder older;	//older generation
	list<long> mem_set;
	list<long> mem_set_o;
	//long addr_begin=0;
	//long addr_end=0;
	int zeroMemSet();
	int whereAddr(long);
	int doGC();
	//int markMBlock(MemBlock&);
	int markObj(long, long);
	int markObjAs(long, char);
	//int markObj3(long);
	long cpyMBlock(MemBlock&);
	long cpyObj(long,MemBlock&, MemBlock&, MemOlder&);
	int doFullGC();
	//int markAllObj();
	//long sweepAllObj();
	long compactOlder();
	//int extendEden(double);
	//int extendSvr(double);
	//int extendOlder(double);

public:
	static long block_size=0XFFFF;//65k, actually 500k
	static long eden_size=0X4FFFF;//256k,actually 2M
	static long svr_size=0X4FFFF;//256k,actually 2M
	static long older_size=0XFFFFF;//1M, actually 8m
	static double eden_thresh1;
	static double eden_thresh2;
	static double eden_ext0;
	static double eden_ext1;
	static double eden_ext2;
	static double svr_thresh1;
	static double svr_thresh2;
	static double svr_ext0;
	static double svr_ext1;
	static double svr_ext2;
	static long older_age;
	static double older_thresh1;
	static double older_thresh2;
	static double older_ext0;
	static double older_ext1;
	static long bigObj_size;
};

#endif /* SRC_MEM_MEMHEAP_H_ */
