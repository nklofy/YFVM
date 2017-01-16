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

#include "PckgManager.h"
#include "TokenStream.h"
#include "../TypeSys/TypeSys.h"

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
	list<IRCode*>& getScript() ;
	list<RcdType*>& getTypes();
	list<RcdVar*>& getVars() ;
	string* dcpLine(string);

private:
	PckgManager pckMan;
	list<RcdType*> types;
	list<RcdFunc*> funcs;
	list<RcdVar*> vars;
	list<IRCode*> script;
	map<int,string> var_tbl;
	map<int,string> type_tbl;
	map<int,string> func_tbl;

};

#endif /* SRC_FILELOADER_H_ */
