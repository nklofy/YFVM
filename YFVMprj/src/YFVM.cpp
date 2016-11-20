#include <iostream>
#include <stdio.h>
#include <string>

#include "RT/VM.h"
#include "Loader/FileLoader.h"
#include "Interpreter/Interpreter.h"
#include "IO/Input.h"
#include "IO/Output.h"
#include "Mem/Memory.h"

using namespace std;

int main(int argc, char **argv){
	string filename;
	if(argc==1){
		filename="testcode/test1.yfc";
	}else{
		filename=argv[1];
		int p1=filename.find_last_of('.');
		int p2=filename.length();
		if(filename.substr(p1,p2)!=".yfc"){
			cerr<<"illegal filename "<<filename<<endl;
			return -1;
		}
	}
	cout<<"start YFVM"<<endl;
	VM machine;
	FileLoader* loader=new FileLoader(filename);
	Interpreter* intpr=new Interpreter;
	Input* input=new Input;
	Output* output=new Output;
	Memory* mem=new Memory;
	machine.initOptNum("./src/Settings/optnum.txt");//map opt to int num
	machine.initSettings("./src/Settings/vmconfig.txt");
	machine.attachLoader(loader);
	machine.attachIntpr(intpr);
	machine.attachMem(mem);
	machine.attachIO(input,output);
	machine.runLoadFile();//function table, class table, script;
	machine.runIntprScript();

	delete loader; delete intpr; delete input; delete output; delete mem;
	cout<<"finish YFVM"<<endl;

	return 0;
}
