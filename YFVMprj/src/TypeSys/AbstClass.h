/*
 * TClass.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABSTCLASS_H_
#define SRC_TYPESYS_ABSTCLASS_H_

#include <map>

#include "AbstType.h"

using namespace std;

class AbstClass : public AbstType {
public:
	AbstClass();
	virtual ~AbstClass();
	TypeK getTypeK(){return tclass;}
	map<string,ClsField*> getFields();
	map<string,ClsMethod*> getMethods();
	const AbstGnrc*& getGnrcPars() const;
	void setGnrcPars(const AbstGnrc*& gnrcPars);

private:
	AbstGnrc* gnrc_pars;
	map<string,ClsField*> fields;
	map<string,ClsMethod*> methods;
};
class ClsField{
	friend class AbstClass;
};
class ClsMethod{
	friend class AbstClass;

};
#endif /* SRC_TYPESYS_ABSTCLASS_H_ */
