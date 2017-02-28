/*
 * VM.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#include "VM.h"
#include <stdio.h>
VM::VM() {
	// TODO Auto-generated constructor stub

}

VM::~VM() {
	// TODO Auto-generated destructor stub
}

int VM::initOptNum(string filename){//map opt to int num
	ifstream infile;
	infile.open(filename.c_str(),fstream::in);
	if(!infile){
		cerr<<"not open optnum file "<<filename<<endl;
		return -1;
	}
	string s;
	int c1=0;
	auto m=&(stcz->getOptNum());
	while(!infile.eof()){
		s.clear();
		infile>>s;
		//m=new map<string, int>();
		auto p=m->find("num");
		if(p!=m->end()){
			cerr<<"err optnum file opt"<<s<<endl;
			return -1;
		}
		(*m)[s]=c1++;
		//cout<<s<<"e"<<endl;
	}
	infile.close();
/*	FILE* f=fopen("./1.txt","r");
	if(!f)cerr<<"not open file "<<endl;
	char c=fgetc(f);
	cout<<c<<endl;
	fclose(f);
*/
	return 0;
}
int VM::initSettings(string filename){

	return 0;
}

int VM::attachLoader(FileLoader* loader){
	this->loader=loader;

	return 0;
}

int VM::attachIntpr(Interpreter* intpr){
	this->intpr=intpr;

	return 0;
}

int VM::attachMem(MemManager* mem){
	this->mem=mem;

	return 0;
}

int VM::attachIO(IOManager* io){
	this->io=io;
	return 0;
}
int VM::initStaticZone(StaticZone* z){
	this->stcz=z;
	this->stcz->init();
	return 0;
}
int VM::runLoadFile(string filename){
	this->loader->doLoad(filename);
	this->stcz->importTypes();
	this->stcz->importFuncs(this->loader->getFuncs());
	this->stcz->importScript(this->loader->getScript());
	return 0;
}

int VM::runIntprScript(){
	cout<<"start running interpreter"<<endl;
	this->intpr->doInterpret(this->stcz,this->mem, this->io);

	return 0;
}

