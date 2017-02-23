/*
 * MemStack.h
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMSTACK_H_
#define SRC_MEM_MEMSTACK_H_

#include "TypeSys/TypeSys.h"

using namespace std;
typedef char T_stackele;
typedef DatValue T_element;

class MemStack {
public:
	static int width=sizeof(T_element)/sizeof(T_stackele);
	static int cwidth=sizeof(T_stackele);
	static int org_height=1024;
	static double ext_ratio=2;
	static long max_long=0XFFFFFFFFFFFFFFFF;

	MemStack();
	virtual ~MemStack();

	T_element& fetch(long);
	T_element& peak();
	T_element* push();
	T_element& pop();
	int modify(long,T_element&);
	void setTop(long);

private:

	long bottom;	//0
	long top;	//from 0 to max_N, index of element
	long capacity;
	T_stackele* real_top;
	T_stackele* real_bottom;

	int extend();
	int shrink();

};

#endif /* SRC_MEM_MEMSTACK_H_ */
