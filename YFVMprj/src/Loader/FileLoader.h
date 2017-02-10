/*
 * FileLoader.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_FILELOADER_H_
#define SRC_FILELOADER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "PckgManager.h"
#include "TokenStream.h"
#include "IRCode.h"
#include "RcdFunc.h"

using namespace std;
class FileLoader {
public:
	FileLoader();
	virtual ~FileLoader();
	int doLoad(string);
	int loadPckg(TokenStream*);
	int loadTypes(TokenStream*);
	int loadFuncs(TokenStream*);
	int loadScript(TokenStream*);
	list<RcdFunc*>& getFuncs() ;
	vector<IRCode*>* getScript() ;
	string* dcpLine(string);

private:
	PckgManager pckMan;
	list<RcdFunc*> funcs;
	vector<IRCode*>* script;
	//map<int,string> var_tbl;
	//map<int,string> type_tbl;
	//map<int,string> func_tbl;

};

#endif /* SRC_FILELOADER_H_ */
