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
		cerr<<"error read "<<filename<<endl;
	}
	doParse();
	return 0;
}
