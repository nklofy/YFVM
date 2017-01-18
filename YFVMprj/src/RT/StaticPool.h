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
#include "../TypeSys/RcdFunc.h"
#include "../TypeSys/RcdType.h"
#include "../TypeSys/RcdVar.h"
#include "../Mem/MemManager.h"
using namespace std;
class StaticPool {
public:
	StaticPool();
	virtual ~StaticPool();
	int importTypes();
	int importFuncs(list<RcdFunc*>&);
	int importScript(list<IRCode*>&);
private:
	map<string,int> func_tbl;
	map<string,int> var_tbl;
	map<string,int> type_tbl;
};

#endif /* SRC_RT_STATICPOOL_H_ */
