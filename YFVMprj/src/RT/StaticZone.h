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
	vector<IRCode*>* getScript() const;
	const map<string, long>& getFuncTbl() const;
	const vector<AbstFunc*>& getFunclist() const;
	map<string,int>& getOptNum();
	int importScript(vector<IRCode*>*);
	vector<IRCode*>* StaticZone::getScript() const;
	map<string, long>& getCnstPlMap();
	vector<string>& getCnstplList();
	const vector<AbstFunc*>& getFuncList() const;
	const map<string, int>& getOptnum() const;
	const map<string, long>& getTypeTbl() const;
	const vector<AbstType*>& getTypelist() const;

private:
	map<string,int> optnum;
	map<string,long> func_tbl;//table recording functions, map name:signature to index
	vector<AbstFunc*> func_list;
	vector<IRCode*>* codes;//script codes
	map<string,long> var_tbl;//table recording variables, used for trans IRcode
	map<string,long> type_tbl;//table of types, as above
	vector<AbstType*> typelist;
	vector<string> cnstpl_list;
	map<string,long> cnstpl_map;
};

#endif /* SRC_RT_STATICZONE_H_ */
