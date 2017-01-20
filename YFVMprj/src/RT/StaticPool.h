/*
 * StaticPool.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_RT_STATICPOOL_H_
#define SRC_RT_STATICPOOL_H_
#include <list>
#include <map>
#include "../TypeSys/TypeSys.h"
#include "MemManager.h"

using namespace std;
class StaticPool {
public:
	StaticPool();
	virtual ~StaticPool();
	int importTypes();
	int importFuncs(list<RcdFunc*>&);
	int importScript(list<IRCode*>&);
private:
	map<string,int> func_tbl;//table recording functions, map name:signature to index
	map<string,int> var_tbl;//table recording variables
	map<string,int> type_tbl;//table of types
};

#endif /* SRC_RT_STATICPOOL_H_ */
