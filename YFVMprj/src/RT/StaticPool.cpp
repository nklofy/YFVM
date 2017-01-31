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
int StaticPool::init(){
	(this->type_tbl)["int"]=this->typelist.size();
	TType* t1=new TBasic;
	this->typelist.push_back(t1);

	(this->type_tbl)["double"]=this->typelist.size();
	TType* t2=new TBasic;
	this->typelist.push_back(t2);

	(this->type_tbl)["bool"]=this->typelist.size();
	TType* t3=new TBasic;
	this->typelist.push_back(t3);

	(this->type_tbl)["char"]=this->typelist.size();
	TType* t4=new TBasic;
	this->typelist.push_back(t4);

	(this->type_tbl)["string"]=this->typelist.size();
	TType* t5=new TBasic;
	this->typelist.push_back(t5);

	return 0;
}
int StaticPool::importTypes(){
	return 0;
}
int StaticPool::importFuncs(list<RcdFunc*>& funcs){
	int i=0;
	for(auto f:funcs){//get all function and load to data zone
		TFunc *r=new TFunc;
		i=this->funclist.size();
		this->funclist.push_back(r);
		if(this->func_tbl.find(f->getName())==func_tbl.end()){	//if no overload
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
		r->setName(f->getName());
		for(auto cp:f->pars){
			r->partypes.push_back(cp->getOpd1());
			r->parnames.push_back(cp->getOpd2());
		}
		//deal with codes, opt map to int, var name map to address, type and composed type map to index of string in const-pool
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
