/*
 * MemManager.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_MEMMANAGER_H_
#define SRC_MEMMANAGER_H_
#include "../Mem/Memory.h"

class MemManager {
public:
	MemManager();
	virtual ~MemManager();
	MZdata* getMZdata();
	MZheap* getMZheap();
private:
	Memory* memory;
};

#endif /* SRC_MEMMANAGER_H_ */
