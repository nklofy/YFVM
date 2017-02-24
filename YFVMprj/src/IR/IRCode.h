/*
 * IRCode.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_CODES_IRCODE_H_
#define SRC_CODES_IRCODE_H_

#include <string>

using namespace std;

class IRCode {
public:
	IRCode();
	IRCode(IRCode&);
	IRCode(string);
	virtual ~IRCode();
	string& getOpd1();
	//void setOpd1(string opd1);
	string& getOpd2();
	//void setOpd2(string opd2);
	string& getOpd3();
	//void setOpd3(string opd3);
	string& getOpt();
	//void setOpt(string opt);
	int setLine(string);

private:
	string opt;
	string opd1;
	string opd2;
	string opd3;

};

#endif /* SRC_CODES_IRCODE_H_ */
