/*
 * MemStack.h
 *
 *  Created on: Feb 12, 2017
 *      Author: luyunfei
 */

#ifndef SRC_MEM_MEMSTACK_H_
#define SRC_MEM_MEMSTACK_H_
#include <string>
#include <string.h>
#include <iostream>
#include "../TypeSys/TypeSys.h"

using namespace std;

class MemStack {
public:
	typedef char T_element;
	static int width;//basic width of stack node in memory
	static int cwidth;
	static int org_height;
	static double ext_ratio;
	static long max_long;

	MemStack();
	virtual ~MemStack();

	DatValue& fetch(long);
	DatValue& peak();
	DatValue* push();
	DatValue& pop();
	int modify(long,DatValue&);
	int setTop(long);
	long getTop();
	void setStcz(StaticZone*);

private:
	StaticZone* stcz;
	long bottom;	//0
	long top;	//from 0 to max_N, index of element
	long capacity;
	T_element* real_top;
	T_element* real_bottom;

	int extend();
	int shrink();

};

#endif /* SRC_MEM_MEMSTACK_H_ */
