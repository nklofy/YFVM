/*
 * FileLoader.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#include "FileLoader.h"

FileLoader::FileLoader() {
	// TODO Auto-generated constructor stub

}

FileLoader::~FileLoader() {
	// TODO Auto-generated destructor stub
}

int FileLoader::doLoad(string filename){
	auto ts=new TokenStream();
	if(ts->bindFile(filename)){
		cerr<<"error read "<<filename<<endl;return -1;
	}
	string s=ts->getLine();
	if(s!="89597046"){		//check magic number
		cerr<<"error fault file type"<<ts->getFilename()<<endl;return -1;
	}
	if(loadPckg(ts)){
		cerr<<"error parse package"<<ts->getFilename()<<endl;return -1;
	}
	if(loadTypes(ts)){
		cerr<<"error parse types"<<ts->getFilename()<<endl;return -1;
	}
	if(loadFuncs(ts)){
		cerr<<"error parse functions"<<ts->getFilename()<<endl;return -1;
	}
	if(loadScript(ts)){
		cerr<<"error parse script"<<ts->getFilename()<<endl;return -1;
	}
	cout<<"finish parse "<<filename<<endl;

	return 0;
}

int FileLoader::loadPckg(TokenStream *ts){
	string s=ts->getLine();
	if(s!=ts->getFilename()){
		cerr<<"error filename not match "<<ts->getFilename();return -1;
	}
	//package and imports
	return 0;
}
int FileLoader::loadTypes(TokenStream *ts){
	//class or interface
	return 0;
}

int FileLoader::loadFuncs(TokenStream *ts){
	string s=ts->getLine();
	string* ss=dcpLine(s);
	while(ss[0]=="defFunction"){
		if(ts->isEnd){
			cerr<<"error parse fucntion "<<ts->getFilename();return -1;
		}
		//parse func name and signature
		RcdFunc* func=new RcdFunc();
		func->setName(ss[1]);
		func->setSig(ss[2]);
		func->setScope(ss[3]);
		s=ts->getLine();
		while(s!="end"){
			//parse func body
			func->getBody().push_back(new IRCode(s));
			s=ts->getLine();
		}
		this->funcs.push_back(func);
		if(ts->isEnd){
			return 0;
		}
		if(ts->getNback()!="defFunction"){
			return 0;
		}
	}
	return 0;
}

int FileLoader::loadScript(TokenStream *ts){
	string s=ts->getLine();
		while(s!="end"){
			//parse func body
			script.push_back(new IRCode(s));
			s=ts->getLine();
		}
		if(ts->isEnd){
			cerr<<"error no end flag "<<ts->getFilename()<<endl;return -1;
		}
	return 0;
}
string* FileLoader::dcpLine(string s){
	string* ss=new string[4];
	int p0=0,p1=s.find(' ');
	int i=0;
	while(p1!=string::npos&&i<4){
		ss[i++]=s.substr(p0,p1-p0);
		p0=p1;
		p1=s.find(' ',p0);
	}
	return ss;
}
list<RcdFunc*>& FileLoader::getFuncs()  {
	return funcs;
}

list<IRCode*>& FileLoader::getScript() {
	return script;
}

list<RcdType*>& FileLoader::getTypes() {
	return types;
}

list<RcdVar*>& FileLoader::getVars() {
	return vars;
}
