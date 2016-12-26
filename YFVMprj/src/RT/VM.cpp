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
	int c1=1;
	while(!infile.eof()){
		s.clear();
		infile>>s;
		if(this->optnum.count(s)>0){
			cerr<<"optnum file dupl opt"<<s<<endl;
			return -1;
		}
		(this->optnum)[s]=c1++;
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

int VM::attachIO(Input* input, Output* output){
	this->input=input;

	this->output=output;

	return 0;
}
int VM::initStcPool(){
	this->stcpool=new StaticPool;
	return 0;
}
int VM::runLoadFile(string filename){
	this->loader->doLoad(filename);
	this->stcpool
	return 0;
}

int VM::runIntprScript(){

	return 0;
}
