/*
 * Interpreter.h
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#ifndef SRC_INTERPRETER_H_
#define SRC_INTERPRETER_H_

class Interpreter {
public:
	Interpreter();
	virtual ~Interpreter();
	int doInterpret(IRCode*, StaticPool*, MemManager*,IOManager*);
};

#endif /* SRC_INTERPRETER_H_ */
