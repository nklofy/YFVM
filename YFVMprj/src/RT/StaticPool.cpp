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
	int i=0;
	for(auto f:funcs){//get all function and load to data zone
		RFunc *r=new RFunc;
		i=this->funclist.size();
		this->funclist.push_back(r);
		if(this->func_tbl.find(f->getName())==func_tbl.end()){
			auto m=this->func_tbl;
			auto m1=new map<string,int>();
			m[f->getName()]=m1;
			(&m1)[f->getSig()]=i;

		}else{
			auto m=this->func_tbl.find(f->getName());
			(&m)[f->getSig()]=i;
		}
		//translate f to r
		//deal with pars
		for(auto cp:f->pars){

		}
		//deal with codes
		for(auto cb:f->body){

		}
	}
	return 0;
}
int StaticPool::importScript(list<IRCode*>& script){
	for(auto s:script){

	}
	return 0;
}
