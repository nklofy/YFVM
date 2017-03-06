/*
 * StaticPool.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#include "StaticZone.h"

StaticZone::StaticZone() {
	this->init();
}


StaticZone::~StaticZone() {
	for(auto f:func_list){
		delete f;
	}
	for(auto t:typelist){
		delete t;
	}
}
int StaticZone::init(){
	//optnum=new map<string,int>();
	//func_tbl=new map<string,long>();
	//func_list=new vector<AbstFunc*>();
	//typelist=new vector<AbstType*>();
	(this->type_tbl)["int"]=this->typelist.size();
	AbstType* t1=new AbTypeBasic;
	this->typelist.push_back(t1);

	(this->type_tbl)["double"]=this->typelist.size();
	AbstType* t2=new AbTypeBasic;
	this->typelist.push_back(t2);

	(this->type_tbl)["bool"]=this->typelist.size();
	AbstType* t3=new AbTypeBasic;
	this->typelist.push_back(t3);

	(this->type_tbl)["char"]=this->typelist.size();
	AbstType* t4=new AbTypeBasic;
	this->typelist.push_back(t4);

	(this->type_tbl)["string"]=this->typelist.size();
	AbstType* t5=new AbTypeBasic;
	this->typelist.push_back(t5);

	return 0;
}
int StaticZone::importTypes(){
	return 0;
}
int StaticZone::importFuncs(list<RcdFunc*>& funcs){
	int i=0;
	for(auto f:funcs){//get all function and load to data zone
		AbTypeFunc *tf=new AbTypeFunc;
		tf->setBody(&(f->getBody()));
		//tf->setFunc(f);
		tf->setName(f->getName());
		tf->setSig(f->getSig());
		i=this->func_list.size();
		tf->setIndex(i);
		this->func_list.push_back(tf);
		if(this->func_tbl.find(f->getName())==func_tbl.end()){	//if no overload
			//auto m=this->func_tbl;
			//auto m1=new map<string,int>();
			//m[f->getName()]=m1;
			//(&m1)[f->getSig()]=i;
			this->func_tbl[f->getName()]=i;
		}else{
			long id=this->func_tbl[f->getName()];
			AbTypeFunc* f1=this->func_list[id];
			tf->hasNext=true;
			tf->addNext(f1);
			this->func_tbl[f->getName()]=i;
		}
		//translate f to r
		//deal with pars
		for(auto cp:f->getPars()){
			tf->getParTypes().push_back(cp->getOpd1());
			tf->getParNames().push_back(cp->getOpd2());
		}
	}
	return 0;
}
int StaticZone::importScript(vector<IRCode*>& script){
	this->codes=&script;
	return 0;
}

vector<IRCode*>* StaticZone::getScript() {
	return codes;
}

unordered_map<string, long>& StaticZone::getFuncTbl() {
	return func_tbl;
}

vector<AbTypeFunc*>& StaticZone::getFuncLst() {
	return func_list;
}

vector<AbTypeFunc*>& StaticZone::getFuncList() {
	return func_list;
}

unordered_map<string, int>& StaticZone::getOptNum() {
	return optnum;
}

unordered_map<string, long>& StaticZone::getTypeTbl() {
	return type_tbl;
}

AbstType* StaticZone::getTypeFromList(long longInt) {
}

AbTypeFunc* StaticZone::getFuncFromList(long longInt) {
}

vector<AbstType*>& StaticZone::getTypeLst() {
	return typelist;
}
