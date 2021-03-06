/*
 * TokenStream.h
 *
 *  Created on: Dec 27, 2016
 *      Author: luyunfei
 */

#ifndef SRC_LOADER_TOKENSTREAM_H_
#define SRC_LOADER_TOKENSTREAM_H_
#include <string>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;
class TokenStream {
public:
	TokenStream();
	virtual ~TokenStream();
	string& getNback();//get next line but go back 1
	void goNext();
	string& getLine();//move next line and return first string
	int bindFile(string);//bind and read file

	string& getFilename();
	void setFilename(string& filename);
	bool isEnd=false;

private:
	string filename;
	ifstream infile;
	string crt_token;
	string crt_line;
	string pre_line;
	int line_no;
	int line_tks;
	bool goback=false;
	list<string> file_data;//read total file to ram and then analyze, but not a good design
	int goBack1();
};

#endif /* SRC_LOADER_TOKENSTREAM_H_ */
