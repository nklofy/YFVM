/*
 * TokenStream.cpp
 *
 *  Created on: Dec 27, 2016
 *      Author: luyunfei
 */

#include "TokenStream.h"

TokenStream::TokenStream() {
	// TODO Auto-generated constructor stub

}

TokenStream::~TokenStream() {
	infile.close();
}

string& TokenStream::getFilename() {
	return filename;
}

void TokenStream::setFilename(string& filename) {
	this->filename = filename;
}

string& TokenStream::getNback() {
	if(goback){
		return pre_line;
	}
	goback=true;
	pre_line.clear();
	getline(infile,pre_line);
	return pre_line;
}

string& TokenStream::getLine() {
	if(goback){
		goback=false;
		return pre_line;
	}else{
		crt_line.clear();
		getline(infile,crt_line);
		return crt_line;
	}
}

int TokenStream::bindFile(string filename) {
	int p2=filename.rfind(".yfc");
	int p1=filename.rfind("/");

	this->filename=filename.substr(p1+1,p2-p1-1);
	infile.open(filename.c_str(),fstream::in);
	if(!infile){
		cerr<<"not open file "<<filename<<endl;
		return -1;
	}
	//infile.close();
	return 0;
}

int TokenStream::goBack1() {
	return 0;
}
