/*
 * IRCode.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#include "../Loader/IRCode.h"

IRCode::IRCode() {
	// TODO Auto-generated constructor stub

}
IRCode::IRCode(string s) {
	int p1=s.find(" ");
	opt=s.substr(0,p1);
	int p2=s.find(" ",p1+1);
	opd1=s.substr(p1+1,p2-p1-1);
	int p3=s.find(" ",p2+1);
	opd2=s.substr(p2+1,p3-p2-1);
	opd3=s.substr(p3+1,s.length()-p3);



}
IRCode::~IRCode() {
	// TODO Auto-generated destructor stub
}

string& IRCode::getOpd1() {
	return opd1;
}

string& IRCode::getOpd2()  {
	return opd2;
}

string& IRCode::getOpd3()  {
	return opd3;
}

string& IRCode::getOpt()  {
	return opt;
}

IRCode::IRCode(IRCode&) {
}

int IRCode::setLine(string s){
	return 0;
}
