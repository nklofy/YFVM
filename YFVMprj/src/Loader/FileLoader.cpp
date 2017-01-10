/*
 * FileLoader.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#include "FileLoader.h"
#include "TokenStream.h"
FileLoader::FileLoader() {
	// TODO Auto-generated constructor stub

}

FileLoader::~FileLoader() {
	// TODO Auto-generated destructor stub
}

int FileLoader::doLoad(string filename){
	auto ts=new TokenStream;
	if(ts->bindFile(filename)){
		cerr<<"error read "<<filename<<endl;return -1;
	}
	if(doParse(ts)){
		cerr<<"error parse "<<filename<<endl;return -1;
	}else{
		cout<<"finish parse "<<filename<<endl;return -1;
	}
	return 0;
}

int FileLoader::doParse(TokenStream *ts){
	string s=ts->getLine();
	if(s!="89597046"){		//check magic number
		cerr<<"error fault file type"<<ts->getFilename()<<endl;return -1;
	}
	if(parsePckg(ts)){
		cerr<<"error parse package"<<ts->getFilename()<<endl;return -1;
	}
	if(parseTypes(ts)){
		cerr<<"error parse types"<<ts->getFilename()<<endl;return -1;
	}
	if(parseFuncs(ts)){
		cerr<<"error parse functions"<<ts->getFilename()<<endl;return -1;
	}
	if(parseScript(ts)){
		cerr<<"error parse script"<<ts->getFilename()<<endl;return -1;
	}
	return 0;
}
int FileLoader::parsePckg(TokenStream *ts){
	string s=ts->getLine();
	if(s!=ts->getFilename()){
		cerr<<"error filename not match "<<ts->getFilename();return -1;
	}
	//package and imports
	return 0;
}
int FileLoader::parseTypes(TokenStream *ts){
	//class or interface
	return 0;
}

int FileLoader::parseFuncs(TokenStream *ts){
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
		s=ts->getLine();
		if(s!="defFunction"){
			ts->goBack1();
			return 0;
		}
	}
	return 0;
}

int FileLoader::parseScript(TokenStream *ts){

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
