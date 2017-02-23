/*
 * MemStack.h
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMSTACK_H_
#define SRC_MEM_MEMSTACK_H_
#include <string.h>
#include "TypeSys/TypeSys.h"

using namespace std;
typedef char T_element;

template <typename T> class MemStack {
public:
	static int width=sizeof(T)/sizeof(T_element);
	static int cwidth=sizeof(T_element);
	static int org_height=1024;
	static double ext_ratio=2;
	static long max_long=0XFFFFFFFFFFFFFFFF;

	MemStack();
	virtual ~MemStack();

	T& fetch(long);
	T& peak();
	T* push();
	T& pop();
	int modify(long,T&);
	int setTop(long);
	long getTop();

private:

	long bottom;	//0
	long top;	//from 0 to max_N, index of element
	long capacity;
	T_element* real_top;
	T_element* real_bottom;

	int extend();
	int shrink();

};

#endif /* SRC_MEM_MEMSTACK_H_ */
