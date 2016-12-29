/*
 * TokenStream.h
 *
 *  Created on: Dec 27, 2016
 *      Author: luyunfei
 */

#ifndef SRC_LOADER_TOKENSTREAM_H_
#define SRC_LOADER_TOKENSTREAM_H_
#include <string>
using namespace std;
class TokenStream {
public:
	TokenStream();
	virtual ~TokenStream();
	string getToken();//get next string in a line
	string getLine();//move next line and return first string
	int bindFile(string);//bind and read file
	int goBack1();
	const string& getFilename() const;
	void setFilename(const string& filename);

private:
	string filename;
	string crt_token;
	string crt_line;
	int line_no;
	int line_tks;
	bool goback;
	list<string> file_data;//read total file to ram and then analyze, but not a good design
};

#endif /* SRC_LOADER_TOKENSTREAM_H_ */
