/*
 * VM.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_RT_VM_H_
#define SRC_RT_VM_H_

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "../Loader/FileLoader.h"
#include "Interpreter.h"
#include "IOManager.h"
#include "MemManager.h"
#include "StaticZone.h"
#include "../TypeSys/TypeSys.h"


using namespace std;
class VM {
private:

	FileLoader* loader;
	Interpreter* intpr;
	IOManager* io;
	MemManager* mem;
	StaticZone* stcpool;

public:
	VM();
	virtual ~VM();

	int initOptNum(string);//map opt to int num
	int initSettings(string);
	int attachLoader(FileLoader* loader);
	int attachIntpr(Interpreter* intpr);
	int attachMem(MemManager* mem);
	int attachIO(IOManager* io);
	int initStaticZone(StaticZone* stcz);
	int runLoadFile(string);//function table, class table, script;
	int runIntprScript();

};

#endif /* SRC_RT_VM_H_ */
