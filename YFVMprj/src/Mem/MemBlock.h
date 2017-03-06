/*
 * MemBlock.h
 *
 *  Created on: Mar 4, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMBLOCK_H_
#define SRC_MEM_MEMBLOCK_H_
#include <list>
using namespace std;
class MemBlock {
public:
	MemBlock();
	virtual ~MemBlock();
	int initSize(long);
	long cpyObj(void*,long);	//source, size, copy from other block
	long pushObj(long);	//type, malloc new obj
	//int markAllObj();
	int markObj(long,char);	//addr, sign
	long getFreeSize();
	long getUsage();
	long extend(long);
	long getAddrBegin();
	void setAddrBegin(long);
	long getAddrEnd();
	void setAddrEnd(long);
	long getCapacity();
	long getFreeBegin() ;
	char* getMarkTable();
	char getMarkAddr(long);//get mark of obj on addr
	void setMarkTable(char* markTable);
	list<long>& getMemSet();
	void* getAddrPtr(long);

private:
	list<long> mem_set;
	void* block_ptr;
	long free_begin;
	long addr_begin;
	long addr_end;
	long capacity;
	char* mark_table;

};

#endif /* SRC_MEM_MEMBLOCK_H_ */
