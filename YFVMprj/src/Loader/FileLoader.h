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

using namespace std;
class FileLoader {
public:
	FileLoader();
	virtual ~FileLoader();
	int doLoad(string);
	int doParse();
	int parseTypes();
	int parseFuncs();
	int parseScript();
	const list<RcdFunc*>& getFuncs() const {
		return funcs;
	}

	const list<IRCode*>& getScript() const {
		return script;
	}

	const list<RcdType*>& getTypes() const {
		return types;
	}

	const list<RcdVar*>& getVars() const {
		return vars;
	}

private:
	PckgManager pckMan;
	list<RcdType*> types;
	list<RcdFunc*> funcs;
	list<RcdVar*> vars;
	list<IRCode*> script;
};

#endif /* SRC_FILELOADER_H_ */
