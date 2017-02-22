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
	AbstType* t1=new AbstBasic;
	this->typelist.push_back(t1);

	(this->type_tbl)["double"]=this->typelist.size();
	AbstType* t2=new AbstBasic;
	this->typelist.push_back(t2);

	(this->type_tbl)["bool"]=this->typelist.size();
	AbstType* t3=new AbstBasic;
	this->typelist.push_back(t3);

	(this->type_tbl)["char"]=this->typelist.size();
	AbstType* t4=new AbstBasic;
	this->typelist.push_back(t4);

	(this->type_tbl)["string"]=this->typelist.size();
	AbstType* t5=new AbstBasic;
	this->typelist.push_back(t5);

	return 0;
}
int StaticZone::importTypes(){
	return 0;
}
int StaticZone::importFuncs(list<RcdFunc*>& funcs){
	int i=0;
	for(auto f:funcs){//get all function and load to data zone
		AbstFunc *tf=new AbstFunc;
		tf->setBody(&(f->getBody()));
		//tf->setFunc(f);
		tf->setName(f->getName());
		tf->setSig(f->getSig());
		i=this->func_list.size();
		this->func_list.push_back(tf);
		if(this->func_tbl.find(f->getName())==func_tbl.end()){	//if no overload
			//auto m=this->func_tbl;
			//auto m1=new map<string,int>();
			//m[f->getName()]=m1;
			//(&m1)[f->getSig()]=i;
			this->func_tbl[f->getName()]=i;
		}else{
			long id=this->func_tbl[f->getName()];
			AbstFunc* f1=this->func_list[id];
			tf->hasNext=true;
			tf->addNext(f1);
			this->func_tbl[f->getName()]=i;
		}
		//translate f to r
		//deal with pars
		for(auto cp:f->pars){
			tf->partypes.push_back(cp->getOpd1());
			tf->parnames.push_back(cp->getOpd2());
		}
	}
	return 0;
}
int StaticZone::importScript(vector<IRCode*>* script){
	this->codes=script;
	return 0;
}

vector<IRCode*>* StaticZone::getCodes() const {
	return codes;
}

const map<string, long>& StaticZone::getFuncTbl() const {
	return func_tbl;
}

const vector<AbstFunc*>& StaticZone::getFunclist() const {
	return func_list;
}

const vector<AbstFunc*>& StaticZone::getFuncList() const {
	return func_list;
}

const map<string, int>& StaticZone::getOptnum() const {
	return optnum;
}

const map<string, long>& StaticZone::getTypeTbl() const {
	return type_tbl;
}

const vector<AbstType*>& StaticZone::getTypelist() const {
	return typelist;
}
