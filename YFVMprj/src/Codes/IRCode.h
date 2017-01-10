/*
 * IRCode.h
 *
 *  Created on: Nov 19, 2016
 *      Author: luyunfei
 */

#ifndef SRC_CODES_IRCODE_H_
#define SRC_CODES_IRCODE_H_

class IRCode {
public:
	IRCode();
	virtual ~IRCode();
	int getOpd1() const;
	void setOpd1(int opd1);
	int getOpd2() const;
	void setOpd2(int opd2);
	int getOpd3() const;
	void setOpd3(int opd3);
	int getOpt() const;
	void setOpt(int opt);

private:
	int opt;
	int opd1;
	int opd2;
	int opd3;

};

#endif /* SRC_CODES_IRCODE_H_ */
