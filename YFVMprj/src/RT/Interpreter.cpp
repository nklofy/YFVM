/*
 * Interpreter.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: luyunfei
 */

#include "Interpreter.h"

Interpreter::Interpreter() {
	// TODO Auto-generated constructor stub

}

Interpreter::~Interpreter() {
	// TODO Auto-generated destructor stub
}

int Interpreter::doInterpret(IRCode* code, StaticPool* pool, MemManager* mem, IOManager* io) {
	switch(code->getOpt()){//in future, use ptr array to deal with distribution

	case "mov":

		break;
	case "load_i":

		break;
	case "load_d":

		break;
	case "load_s":

		break;
	case "load_c":

		break;
	case "load_b":

		break;


////////////////////////////////////
	case "GT":

		break;
	case "LT":

		break;
	case "GE":

		break;
	case "LE":

		break;
	case "NE":

		break;
	case "EQ":

		break;
	case "NOT":

		break;
	case "sub_i":

		break;
	case "sub_d":

		break;
	case "add_i":

		break;
	case "add_d":

		break;
	case "mul_i":

		break;
	case "mul_d":

		break;
	case "div_d":

		break;
	case "inc_1":

		break;
	case "dec_1":

		break;

//////////////////////
	case "if":

		break;
	case "while":

		break;
	case "goto":

		break;
	case "retExp":

		break;
	case "ret":

		break;
	case "defFunction":

		break;
	case "end":

		break;
	case "getFunc":

		break;
	case "pushTypeArg":

		break;
	case "pushFuncArg":

		break;
	case "invoke":

		break;

		/////////////////////////////
	case "defClass":

		break;
	case "defInterface":

		break;
	case "extends":

		break;
	case "impliments":

		break;
	case "Fields":

		break;
	case "defField":

		break;
	case "Methods":

		break;
	case "defMethod":

		break;
	case "defGnrcPar":

		break;
	case "defFuncPar":

		break;
	case "newArr":

		break;
	case "newObj":

		break;
	case "defLambdaExp":

		break;
	case "getFuncObj":

		break;
	case "getMethod":

		break;
	case "getArray":

		break;
	case "getField":

		break;
	case "getClass":

		break;

	default:
		break;
	}
	return 0;
}
