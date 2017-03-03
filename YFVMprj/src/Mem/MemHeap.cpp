/*
 * MemHeap.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#include "MemHeap.h"

#include <climits>

//int MemHeap::width=sizeof(T_grid)/sizeof(T_element);
double MemHeap::ext_ratio=2;
long MemHeap::max_long=LONG_MAX;

MemHeap::MemHeap() {
	// TODO Auto-generated constructor stub

}

MemHeap::~MemHeap() {
	// TODO Auto-generated destructor stub
}

int MemHeap::init() {

	blocks=new void*[block_count];
	block_ptrB=new long[block_count];
	block_ptrE=new long[block_count];
	//block_info=new char[block_count];
	block_info={0,0,0,0,0,0,0,0,0};
	for(int i=0;i<block_count;i++){
		blocks[i]=malloc(block_size);
		block_ptrB[i]=0;
		block_ptrE[i]=0;
	}
	block_begin=0;
	block_end=8;
	older=malloc(older_size);
}

long MemHeap::mallocObj(long size) {
	//find a available block
	//find a available space
	//blocks[block_begin]+block_ptrB[block_begin];

}

int MemHeap::freeObj(long ptr) {


}
