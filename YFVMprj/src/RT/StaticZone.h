/*
 * StaticPool.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_RT_STATICZONE_H_
#define SRC_RT_STATICZONE_H_
#include <list>
#include <map>
#include <vector>
#include "../TypeSys/TypeSys.h"
#include "../IR/IR.h"
#include "MemManager.h"

using namespace std;
class StaticZone {
public:
	StaticZone();
	virtual ~StaticZone();
	int init();
	int importTypes();
	int importFuncs(list<RcdFunc*>&);
	int importScript(vector<IRCode*>&);
	const vector<IRCode*>*& getCodes() const;
	const map<string, map<string, int> *>& getFuncTbl() const;
	const vector<TFunc*>& getFunclist() const;


private:
	map<string,map<string,int>*> func_tbl;//table recording functions, map name:signature to index
	vector<TFunc*> func_list;
	vector<IRCode*>* codes;
	map<string,int> var_tbl;//table recording variables, used for trans IRcode
	map<string,int> type_tbl;//table of types, as above
	vector<TType*> typelist;
	vector<string> const_pool;
	map<string,int> cnstpl_index;
};

#endif /* SRC_RT_STATICZONE_H_ */
