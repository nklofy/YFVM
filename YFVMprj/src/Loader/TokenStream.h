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
	int bindFile(string);
private:
	string crt_token;
};

#endif /* SRC_LOADER_TOKENSTREAM_H_ */
