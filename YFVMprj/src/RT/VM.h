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
#include "../Interpreter/Interpreter.h"
#include "../IO/Input.h"
#include "../IO/Output.h"
#include "../Mem/Memory.h"


class VM {
private:
	map<string,int> optnum;
	FileLoader* loader;
	Interpreter* intpr;
	Input* input;
	Output* output;
	Memory* mem;

public:
	VM();
	virtual ~VM();

	int initOptNum(string);//map opt to int num
	int initSettings(string);
	int attachLoader(FileLoader* loader);
	int attachIntpr(Interpreter* intpr);
	int attachMem(Memory* mem);
	int attachIO(Input* input, Output* output);
	int runLoadFile();//function table, class table, script;
	int runIntprScript();
};

#endif /* SRC_RT_VM_H_ */
