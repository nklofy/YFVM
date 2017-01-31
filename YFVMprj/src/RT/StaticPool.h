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
#include <vector>
#include "../TypeSys/TypeSys.h"
#include "../IR/IR.h"
#include "MemManager.h"

using namespace std;
class StaticPool {
public:
	StaticPool();
	virtual ~StaticPool();
	int init();
	int importTypes();
	int importFuncs(list<RcdFunc*>&);
	int importScript(list<IRCode*>&);
private:
	map<string,map<string,int>*> func_tbl;//table recording functions, map name:signature to index
	vector<TFunc*> funclist;
	vector<long> codes;
	map<string,int> var_tbl;//table recording variables
	map<string,int> type_tbl;//table of types
	vector<TType*> typelist;
};

#endif /* SRC_RT_STATICPOOL_H_ */
