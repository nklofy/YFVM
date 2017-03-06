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
#include <unordered_map>
#include <vector>
#include <string>
#include "../TypeSys/TypeSys.h"
#include "../Loader/IR.h"
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
	vector<IRCode*>* getScript();
	AbstType* getTypeFromList(long);
	AbTypeFunc* getFuncFromList(long);
	AbstType* getTypeFromName(string&);
	AbTypeFunc* getFuncFromName(string&);
	unordered_map<string, long>& getFuncTbl();
	vector<AbTypeFunc*>& getFuncLst();
	unordered_map<string,int>& getOptNum();
	unordered_map<string, long>& getCnstPlMap();
	vector<string>& getCnstplList();
	vector<AbTypeFunc*>& getFuncList();
	unordered_map<string, long>& getTypeTbl();
	vector<AbstType*>& getTypeLst();

private:
	unordered_map<string,int> optnum;
	unordered_map<string,long> func_tbl;//table recording functions, map name:signature to index
	vector<AbTypeFunc*> func_list;
	vector<IRCode*>* codes;//script codes
	unordered_map<string,long> var_tbl;//table recording variables, used for trans IRcode
	unordered_map<string,long> type_tbl;//table of types, as above
	vector<AbstType*> typelist;
	vector<string> cnstpl_list;
	unordered_map<string,long> cnstpl_map;
};

#endif /* SRC_RT_STATICZONE_H_ */
