/*
 * MemHeap.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#include "MemHeap.h"

#include <climits>
/*
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
*/
MemHeap::MemHeap() {
	// TODO Auto-generated constructor stub

}

MemHeap::~MemHeap() {
	delete crt_svr;
	delete next_svr;
}

int MemHeap::init() {
	eden.initSize(eden_size);
	crt_svr->initSize(svr_size);
	next_svr->initSize(svr_size);
	older.initSize(older_size);
	eden.setAddrBegin(max_singleMem);
	eden.setAddrEnd(eden_size+eden.getAddrBegin());
	next_svr->setAddrBegin(max_singleMem*2);
	next_svr->setAddrEnd(svr_size+next_svr->getAddrBegin());
	crt_svr->setAddrBegin(max_singleMem*3);
	crt_svr->setAddrEnd(crt_svr->getAddrBegin()+svr_size);
	older.setAddrBegin(max_singleMem*4);
	older.setAddrEnd(older.getAddrBegin()+older_size);
	//addr_begin=0;
	//addr_end=older.getAddrEnd();

}

long MemHeap::mallocObj(long size) {
	if(size>bigObj_size){//big object
		return older.pushObj(size);
	}
	if(size>eden.getFreeSize()){
		doGC();
	}
	return eden.pushObj(size);

}

long MemHeap::mallocStr(string& allocator) {
	return -1;
}

long MemHeap::mallocArray(long size, long count) {
	return -1;
}



int MemHeap::doGC() {
	//copy eden to survivor, if cpr>0.5, eden*4, >0.2 eden*2
	//copy svr to svr, if free <1/2, svr *2, cpr<0.1, svr*0.5
	markMBlock(eden);
	markMBlock(*crt_svr);
	long size1=cpyMBlock(eden,*next_svr);
	if(size1>eden_size*eden_thresh1){
		extendEden(eden_ext1);
	}else if(size1>eden_size*eden_thresh2){
		extendEden(eden_ext2);
	}
	long size2=cpyMBlock(*crt_svr, *next_svr)+crt_svr->getUsage();
	if(size2>svr_size*svr_thresh1){
		extendSvr(svr_ext1);
	}else if(size2<svr_size*svr_thresh2){
		extendSvr(svr_ext2);
	}
	MemBlock* tsvr=crt_svr;
	crt_svr=next_svr;
	next_svr=tsvr;


}

int MemHeap::markMBlock(MemBlock& block){
	//mark 1, then search memset, visiting 2, visited 3
	list<long>& list=block.getMemSet();
	char* marktb=block.getMarkTable();
	for(int i=block.getAddrBegin();i<block.getAddrEnd();i++){
		if(block.getMarkAddr(i)==1){
			markObj2(i);
		}
	}

}
void markObj2(long){

}void markObj3(long){

}

long MemHeap::cpyMBlock(MemBlock& block, MemBlock& next){

}

int MemHeap::doFullGC() {
	//if older full, do mark-sweep full GC
	//free <1/2, older *2
	//still cannot insert, do compact

}

int MemHeap::markAllObj(){

}

long MemHeap::sweepAllObj(){

}

long MemHeap::compactMBlock(){

}

int MemHeap::extendEden(double r){

}

int MemHeap::extendSvr(double r){

}
