/*
 * MemOlder.h
 *
 *  Created on: Mar 4, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMOLDER_H_
#define SRC_MEM_MEMOLDER_H_
#include <list>
using namespace std;
class MemOlder {
public:
	MemOlder();
	virtual ~MemOlder();
	int initSize(long);
	long cpyObj(long,long);	//source addr, size, copy from other block
	long pushObj(long);	//type, malloc new obj
	//int markAllObj();
	int markObj(long,char);	//addr, sign
	long getFreeSize();
	long getUsageRate();
	long extend(long);
	long getAddrBegin() ;
	void setAddrBegin(long);
	long getAddrEnd();
	void setAddrEnd(long);
	long getCapacity() ;
	long getFreeBegin() ;
	list<long[2]>& getFreeList();
	char* getMarkTable();
	void* getAddrPtr(long);

private:
	void* block_ptr;
	long free_begin;
	long addr_begin;
	long addr_end;
	long capacity;
	char* mark_table;
	list<long[2]> free_list;
};

#endif /* SRC_MEM_MEMOLDER_H_ */
