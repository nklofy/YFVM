/*
 * MemHeap.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#include "MemHeap.h"

long MemHeap::block_size=0XFFFF;
long MemHeap::eden_size=0X4FFFF;
long MemHeap::svr_size=0X4FFFF;
long MemHeap::older_size=0XFFFFF;
double MemHeap::eden_thresh1=0.5;
double MemHeap::eden_thresh2=0.2;
double MemHeap::eden_ext0=4;
double MemHeap::eden_ext1=4;
double MemHeap::eden_ext2=2;
double MemHeap::svr_thresh1=0.5;
double MemHeap::svr_thresh2=0.1;
double MemHeap::svr_ext0=4;
double MemHeap::svr_ext1=2;
double MemHeap::svr_ext2=0.5;
long MemHeap::older_age=8;
double MemHeap::older_thresh1;
double MemHeap::older_thresh2;
double MemHeap::older_ext0=2;
double MemHeap::older_ext1;
long MemHeap::bigObj_size=1024;

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
	eden.setAddrBegin(MemManager::max_singleMem);
	eden.setAddrEnd(eden_size+eden.getAddrBegin());
	next_svr->setAddrBegin(MemManager::max_singleMem*2);
	next_svr->setAddrEnd(svr_size+next_svr->getAddrBegin());
	crt_svr->setAddrBegin(MemManager::max_singleMem*3);
	crt_svr->setAddrEnd(crt_svr->getAddrBegin()+svr_size);
	older.setAddrBegin(MemManager::max_singleMem*4);
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
	mem_set.merge(mem_set_o);
	long size1=cpyMBlock(*next_svr);
	if(size1>eden_size*eden_thresh1){
		extendEden(eden_ext1);
	}else if(size1>eden_size*eden_thresh2){
		extendEden(eden_ext2);
	}
	if(size1>svr_size*svr_thresh1){
		extendSvr(svr_ext1);
	}else if(size1<svr_size*svr_thresh2){
		extendSvr(svr_ext2);
	}
	MemBlock* tsvr=crt_svr;
	crt_svr=next_svr;
	next_svr=tsvr;
	return 0;
}

long MemHeap::cpyMBlock(MemBlock& next){
	next.ZeroMarkTbl();
	list<long>& list=this->mem_set;
	//char* marktb=block.getMarkTable();
	for(auto p=list.iterator;p<list.end();p++){
		long addr1=*p;
		int bm=whereAddr(addr1);
		if(bm==-1) continue;
		RRValue* v=&(((DatValue*)fetchObj(addr1))->value);
		long addr2=v->ptr_value;
		bm=whereAddr(addr2);
		MemBlock* block;
		if(bm==1){
			block=&eden;
		}else if(bm==2){
			block=crt_svr;
		}else
			continue;
		long newad=cpyObj(addr2, *block, next, older);
		if(newad!=-1)
			v->ptr_value=newad;
	}
}
int MemHeap::whereAddr(long addr){
	if(addr>=stack->getTop()&&addr<MemManager::max_singleMem) return -1;
	if(addr<stack->getTop()) return 0;
	if(addr>MemManager::max_singleMem&&addr<eden.getAddrEnd()) return 1;
	if(addr>MemManager::max_singleMem*2&&addr<crt_svr->getAddrEnd()) return 2;
	if(addr>MemManager::max_singleMem*3&&addr<older.getAddrEnd()) return 3;
	return -1;
}
long MemHeap::cpyObj(long addr, MemBlock& block, MemBlock& next, MemOlder& older){//addr, source mem, target mem, older
	//currently used recursing, but need to use iterating
	//check cpy mark, cpy obj, mov free ptr, change fowarding ptr, cpy children of fwd ptr

	char m=block.getMarkAddr(addr);	//1 new obj, 2 visiting, 3 visited, 0 garbage

	InstVar* var=(InstVar*)fetchObj(addr);
	var->addObjAge();
	long freead=next.getFreeBegin();
	long newad=freead;
	if(m==1||m==3){
		block.markObj(addr,2);
		AbstType* type=stcz->getTypeFromList(var->getType());
		if(type->getTypeK()==tbasic){
			//
			cerr<<"error locate to basic type obj"<<endl;
			return -1;

		}else if(type->getTypeK()==tclass){
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
				newad=older.cpyObj(block.getAddrPtr(addr),tcl->getSize());//copy and mark table

			}
			if(next.getAddrEnd()-freead<tcl->getSize()){
				svr_size*=svr_ext0;
				next.extend(svr_size);
			}
			freead=next.cpyObj(block.getAddrPtr(addr),tcl->getSize());//copy and mark table
			var->setFwdPtr(freead);
			for(auto child:tcl->getChildren()){
				long childad=((DatValue*)fetchObj(newad+tcl->getFldI2A(child)))->value.ptr_value;
				cpyObj(childad,block,next,older);
			}
			//block.markObj(addr,3);
		}else if(type->getTypeK()==tarray){
			//

		}else{
			cerr<<"error GC cpy obj "<<addr<<"'s type "<<var->getType()<<endl;
			return -1;
		}
	}else
		newad=var->getFwdPtr();
	return newad;
}

int MemHeap::doFullGC() {
	//mark all obj and sweep
	this->zeroMemSet();
	eden.ZeroMarkTbl();
	crt_svr->ZeroMarkTbl();
	older.ZeroMarkTbl();
	for(int i=0;i<stack->getTop();i++){
		DatValue& v=stack->fetch(i);
		if(v.valuek==vk_ptr){
			markObj(i, v.value.ptr_value);//mark and memset
			mem_set.push_back(i);
		}
	}
	older.updateFreeList();
	return 0;
}
/*
int MemHeap::markMBlock(MemBlock& block){



}*/
int MemHeap::markObj(long addr1, long addr2){	//memset, marktable
	InstVar* var=(InstVar*)fetchObj(addr2);
	long ti=((InstVar*)fetchObj(addr2))->getType();
	AbstType* type=stcz->getTypeFromList(ti);
	if(type->getTypeK()==tbasic){
		//
		cerr<<"error locate to basic type obj"<<endl;
		return -1;
	}else if(type->getTypeK()==tclass){
		char c=markObjAs(addr2,2);
		if(c==1&&addr1>=older.getAddrBegin()){//obj locate at eden, source locate at older, update memset
			mem_set_o.push_back(addr1);
		}else if(c==2&&addr1>=older.getAddrBegin()){//obj locate at svr, source locate at older, update memset
			mem_set_o.push_back(addr1);
		}
		AbTypeClass* t1=(AbTypeClass*) type;
		for(auto child:t1->getChildren()){
			long childad=((DatValue*)fetchObj(addr2+t1->getFldI2A(child)))->value.ptr_value;
			markObj(addr2,childad);
		}
	}else if(type->getTypeK()==tarray){
		//
	}else{
		cerr<<"error mark object"<<endl;
	}
}

int  MemHeap::markObjAs(long addr,char c){
	if(addr>=eden.getAddrBegin()&&addr<eden.getAddrEnd()){
		eden.markObj(addr,c);
		return 1;
	}else if(addr<crt_svr->getAddrEnd()){
		crt_svr->markObj(addr,c);
		return 2;
	}else if(addr<older.getAddrEnd()){
		eden.markObj(addr,c);
		return 3;
	}
	cerr<<"error illegal addr "<<addr<<endl;
	return 0;
}

long MemHeap::compactOlder(){
	//set forward ptr, set ptr, mov obj
	this->zeroMemSet();
	older.resetFreeList();
	long freebegin=older.getAddrBegin();
	for(long addr=older.getAddrBegin();addr<older.getAddrEnd();addr++){
		if(older.getMarkAddr(addr)==3){
			InstVar* var=fetchObj(addr);
			var->setFwdPtr(freebegin);
			freebegin+=stcz->getTypeFromList(var->getType())->getSize();
		}
	}
	for(long addr=older.getAddrBegin();addr<older.getAddrEnd();addr++){
		if(older.getMarkAddr(addr)==3){
			InstVar* var=fetchObj(addr);
			//update children's ptr
		}
	}
	for(long addr=older.getAddrBegin();addr<older.getAddrEnd();addr++){
		if(older.getMarkAddr(addr)==3){
			InstVar* var=fetchObj(addr);
			older.cpyObj(fetchObj(addr),var->getFwdPtr());
			//update memset
		}
	}
}

int MemHeap::extendEden(double r){

}


void MemHeap::setStcz(StaticZone* stcz) {
	this->stcz = stcz;
}

void* MemHeap::fetchObj(long addr) {

}


int MemHeap::extendSvr(double r){

}


int MemHeap::extendOlder(double r) {
}
