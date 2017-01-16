/*
 * StaticPool.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_RT_STATICPOOL_H_
#define SRC_RT_STATICPOOL_H_
#include <list>
#include "../TypeSys/RcdFunc.h"
#include "../TypeSys/RcdType.h"
#include "../TypeSys/RcdVar.h"
using namespace std;
class StaticPool {
public:
	StaticPool();
	virtual ~StaticPool();
	int importTypes();
	int importFuncs(list<RcdFunc*>&);
	int importScript(list<IRCode*>&);
private:

};

#endif /* SRC_RT_STATICPOOL_H_ */
