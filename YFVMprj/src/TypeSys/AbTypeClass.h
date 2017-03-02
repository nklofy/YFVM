/*
 * TClass.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABTYPECLASS_H_
#define SRC_TYPESYS_ABTYPECLASS_H_

#include <map>

#include "AbstType.h"
#include "InstObj.h"
#include "DatValue.h"

using namespace std;



class ClsField{
public:
	string name;
	long type;
	friend class AbTypeClass;
};
class ClsMethod{
	string name;
	long func;
	friend class AbTypeClass;
};

class AbTypeClass : public AbstType {
public:
	AbTypeClass();
	virtual ~AbTypeClass();
	TypeK getTypeK(){return tclass;}
	long getSize(){return sizeof(InstObj)+fields_n*AbstType::datwidth;}
	//map<string,ClsField*>& getFields();
	//map<string,ClsMethod*>& getMethods();
	//const AbstGnrc* getGnrcPars() const;
	//void setGnrcPars(const AbstGnrc* gnrcPars);
	long getFldIndex(string&);
	long getMthdIndex(string&,string&);
	long getFldAddr(string&);	//relative addr of field
	long getMthdAddr(string&,string&);	//relative addr of method
private:
	//AbstGnrc* gnrc_pars;
	long fields_n;
	long methods_n;
	map<string,ClsField*> fields;
	map<string,ClsMethod*> methods;
};
#endif /* SRC_TYPESYS_ABTYPECLASS_H_ */
