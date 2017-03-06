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
	return 0;
}

long MemHeap::cpyMBlock(MemBlock& block, MemBlock& next){
	list<long>& list=block.getMemSet();
	char* marktb=block.getMarkTable();
	for(auto p=list.iterator;p<list.end();p++){
		long addr1=*p;
		RRValue* v=(RRValue*)fetchObj(addr1);
		long addr2=v->ptr_value;
		long newad=cpyObj(addr2, block, next, older);
		if(newad!=-1)
			v->ptr_value=newad;
	}
}

long MemHeap::cpyObj(long addr, MemBlock& block, MemBlock& next, MemOlder& older){
	//check cpy mark, cpy obj, mov free ptr, change fowarding ptr, cpy children of fwd ptr
	char m=block.getMarkAddr(addr);	//1 new obj, 2 visiting, 3 visited, 0 garbage
	InstVar* var=(InstVar*)fetchObj(addr);

	long freead=next.getFreeBegin();
	long newad=freead;
	if(m==1||m==3){
		block.markObj(addr,2);
		AbstType* type=stcz->getTypeFromList(var->getType());
		if(type->getTypeK()==tclass){
			AbTypeClass* tcl=(AbTypeClass*)type;
			if(var->getObjAge()>older_age){
				//cpy Obj to Older
				if(older.getFreeSize()<tcl->getSize()){
					extendOlder(older_ext0);
				}
				if(older.getMaxFree()>tcl->getSize()){
					doFullGC();
				}
				if(older.getMaxFree()>tcl->getSize()){
					compactOlder();
				}
				newad=older.cpyObj(block.getAddrPtr(addr),tcl->getSize());
			}
			if(next.getAddrEnd()-freead<tcl->getSize()){
				svr_size*=svr_ext0;
				next.extend(svr_size);
			}
			freead=next.cpyObj(block.getAddrPtr(addr),tcl->getSize());
			var->setFwdPtr(freead);
			for(auto child:tcl->getChildren()){
				long childad=((RRValue*)fetchObj(newad+tcl->getFldI2A(child)))->ptr_value;
				cpyObj(childad,block,next,older);
			}
			block.markObj(addr,3);
		}else if(type->getTypeK()==tarray){

		}else{
			cerr<<"error GC cpy obj "<<addr<<"'s type "<<var->getType()<<endl;
		}
	}else
		newad=var->getFwdPtr();
	return newad;
}

int MemHeap::doFullGC() {
	//mark all obj, set forward ptr, set ptr, mov obj
	for(int i=0;i<stack->getTop();i++){
		DatValue& v=stack->fetch(i);
		if(v.valuek==vk_ptr){
			markObj2(v.value.ptr_value);//mark and memset
		}
	}
	older.updateFreeList();
	return 0;
}
/*
int MemHeap::markMBlock(MemBlock& block){
	long ti=v->getType();
	AbstType* t=stcz->getTypeLst()[ti];
	if(t->getTypeK()==tclass){
		AbTypeClass* t1=(AbTypeClass*) t;
		for(int i=0;i<t1->getChildrenN();i++){
			int fi=t1->getChildren()[i];
			int addri=t1->getFldAddr(fi);
			*p=cpyObj(addr1+addri,block,next);
		}
	}

}*/

int  MemHeap::markObj2(long){

}

int  MemHeap::markObj3(long){

}
/*
int MemHeap::markAllObj(){

}

long MemHeap::sweepAllObj(){

}*/

long MemHeap::compactOlder(){
	for(long addr=older.getAddrBegin();addr<older.getAddrEnd();addr++){
		if(older.getMarkAddr(addr)==3){

		}
	}
}

int MemHeap::extendEden(double r){

}


void MemHeap::setStcz(StaticZone* stcz) {
	this->stcz = stcz;
}

void* MemHeap::fetchObj(long longInt) {
}


int MemHeap::extendSvr(double r){

}


int MemHeap::extendOlder(double double1) {
}
