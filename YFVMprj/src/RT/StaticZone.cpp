/*
 * StaticPool.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#include "StaticZone.h"

StaticZone::StaticZone() {
	// TODO Auto-generated constructor stub

}

StaticZone::~StaticZone() {
	// TODO delete resources

}
int StaticZone::init(){
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
int StaticZone::importTypes(){
	return 0;
}
int StaticZone::importFuncs(list<RcdFunc*>& funcs){
	int i=0;
	for(auto f:funcs){//get all function and load to data zone
		TFunc *r=new TFunc;
		i=this->func_list.size();
		this->func_list.push_back(r);
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
		//deal with codes
		for(auto c:f->body){
			long cs[4];
			string& opt=c->getOpt();
			string& opd1=c->getOpd1();
			string& opd2=c->getOpd2();
			string& opd3=c->getOpd3();
			cs[0]=this->optnum[opt];
			r->getBody().push_back(cs);

		}
	}
	return 0;
}
int StaticZone::importScript(list<IRCode*>& script){
	this->codes=&script
	return 0;
}

const vector<long[4]>& StaticZone::getCodes() const {
	return codes;
}

const map<string, map<string, long> *>& StaticZone::getFuncTbl() const {
	return func_tbl;
}

const vector<TFunc*>& StaticZone::getFunclist() const {
	return func_list;
}
