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
	// TODO Auto-generated destructor stub
}

const string& TokenStream::getFilename() const {
	return filename;
}

void TokenStream::setFilename(const string& filename) {
	this->filename = filename;
}

string TokenStream::getNback() {
	return NULL;
}

string TokenStream::getLine() {
	return NULL;
}

int TokenStream::bindFile(string allocator) {
	return 0;
}

int TokenStream::goBack1() {
	return 0;
}
