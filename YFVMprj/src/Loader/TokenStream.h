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
	string getToken();
	string getLine();
	int bindFile(string);
	int goBack1();
	const string& getFilename() const;
	void setFilename(const string& filename);

private:
	string filename;
	string crt_token;
	string crt_line;
};

#endif /* SRC_LOADER_TOKENSTREAM_H_ */
