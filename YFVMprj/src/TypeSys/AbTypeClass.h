/*
 * TClass.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABTYPECLASS_H_
#define SRC_TYPESYS_ABTYPECLASS_H_

#include <map>
#include <unordered_map>

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
	long getSize(){return sizeof(InstObj)+fields_n*AbstType::RWidth;}
	//map<string,ClsField*>& getFields();
	//map<string,ClsMethod*>& getMethods();
	//const AbstGnrc* getGnrcPars() const;
	//void setGnrcPars(const AbstGnrc* gnrcPars);
	long getFldN2I(string&);//name to index
	long getMthdN2I(string&,string&);//name to index
	long getFldI2A(long);	//index to relative addr of field
	long getMthI2A(long);	//index to relative addr of method
	long *getChildren();
	long getChildrenN();

private:
	//AbstGnrc* gnrc_pars;
	long fields_n;
	long methods_n;
	long children_n;
	long* children;
	unordered_map<string,ClsField*> fields;
	unordered_map<string,ClsMethod*> methods;
};
#endif /* SRC_TYPESYS_ABTYPECLASS_H_ */
