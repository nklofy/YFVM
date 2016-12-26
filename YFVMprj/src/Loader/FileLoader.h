/*
 * FileLoader.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_FILELOADER_H_
#define SRC_FILELOADER_H_

#include <string>
#include "PckgManager.h"

using namespace std;
class FileLoader {
public:
	FileLoader();
	virtual ~FileLoader();
	int doLoad(string);
private:
	PckgManager pckMan;
};

#endif /* SRC_FILELOADER_H_ */
