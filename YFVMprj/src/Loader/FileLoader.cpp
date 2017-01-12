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
	while(s=="defFunction"){
		if(ts->isEnd){
			cerr<<"error parse fucntion "<<ts->getFilename();return -1;
		}
		s=ts->getLine();
		while(s!="end"){
			//load func body

			s=ts->getLine();
		}
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

	return 0;
}

const list<RcdFunc*>& FileLoader::getFuncs() const {
	return funcs;
}

const list<IRCode*>& FileLoader::getScript() const {
	return script;
}

const list<RcdType*>& FileLoader::getTypes() const {
	return types;
}

const list<RcdVar*>& FileLoader::getVars() const {
	return vars;
}
