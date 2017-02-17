/*
 * TClass.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_TCLASS_H_
#define SRC_TYPESYS_TCLASS_H_

#include "TType.h"
#include <map>

using namespace std;

class TClass : public TType {
public:
	TClass();
	virtual ~TClass();
	TypeK getTypeK(){return tclass;}
	map<string,ClsField*> getFields();
	map<string,ClsMethod*> getMethods();
	const TGnrc*& getGnrcPars() const;
	void setGnrcPars(const TGnrc*& gnrcPars);

private:
	TGnrc* gnrc_pars;
	map<string,ClsField*> fields;
	map<string,ClsMethod*> methods;
};
class ClsField{
	friend class TClass;
};
class ClsMethod{
	friend class TClass;

};
#endif /* SRC_TYPESYS_TCLASS_H_ */
