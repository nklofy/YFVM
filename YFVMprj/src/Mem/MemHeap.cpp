/*
 * MemHeap.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#include "MemHeap.h"

#include <climits>



MemHeap::MemHeap() {
	// TODO Auto-generated constructor stub

}

MemHeap::~MemHeap() {
}

int MemHeap::init() {
	eden.initSize(eden_size);
	svr0.initSize(svr_size);
	svr1.initSize(svr_size);
	older.initSize(older_size);
	eden.setAddrBegin(0);
	eden.setAddrEnd(eden_size);
	svr0.setAddrBegin(eden.getAddrEnd());
	svr0.setAddrEnd(svr_size+svr0.getAddrBegin());
	svr1.setAddrBegin(svr1.getAddrEnd());
	svr1.setAddrEnd(svr1.getAddrBegin()+svr_size);
	older.setAddrBegin(svr1.getAddrEnd());
	older.setAddrEnd(older.getAddrBegin()+older_size);
	addr_begin=0;
	addr_end=older.getAddrEnd();

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
	//copy eden to survivor
	//copy svr to svr, if free >0.75, eden*2, if free <0.25, svr *2
	//if older is full do full GC , if cpr >0.5 older*2
}

int MemHeap::doFullGC() {
}
