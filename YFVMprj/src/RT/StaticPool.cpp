/*
 * StaticPool.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#include "StaticPool.h"

StaticPool::StaticPool() {
	// TODO Auto-generated constructor stub

}

StaticPool::~StaticPool() {
	// TODO Auto-generated destructor stub
}
int StaticPool::importTypes(){
	return 0;
}
int StaticPool::importFuncs(list<RcdFunc*>& funcs){
	for(auto f:funcs){

	}
	return 0;
}
int StaticPool::importScript(list<IRCode*>& script){
	for(auto s:script){

	}
	return 0;
}
