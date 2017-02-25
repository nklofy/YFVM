#include <iostream>
#include <stdio.h>
#include <string>

#include "RT/VM.h"
#include "Loader/FileLoader.h"
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
	FileLoader* loader=new FileLoader;
	Interpreter* intpr=new Interpreter;
	IOManager* io=new IOManager;
	MemManager* mem=new MemManager;
	StaticZone* stcz=new StaticZone;
	machine.initSettings("Settings/vmconfig.txt");
	machine.attachLoader(loader);
	machine.attachIntpr(intpr);
	machine.attachMem(mem);
	machine.attachIO(io);
	machine.initStaticZone(stcz);
	machine.initOptNum("Settings/optnum.txt");//map opt to int num
	machine.runLoadFile(filename);//function table, class table, script;
	machine.runIntprScript();
	cout<<"finish YFVM"<<endl;

	return 0;
}
