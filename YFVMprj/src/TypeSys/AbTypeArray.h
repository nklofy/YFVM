/*
 * TArray.h
 *
 *  Created on: Jan 20, 2017
 *      Author: luyunfei
 */

#ifndef SRC_TYPESYS_ABTYPEARRAY_H_
#define SRC_TYPESYS_ABTYPEARRAY_H_

#include "AbstType.h"
#include "InstArray.h"

class AbTypeArray : public AbstType {
public:
	AbTypeArray();
	virtual ~AbTypeArray();
	TypeK getTypeK(){return tarray;}
	//layout of isntarray: mark, type, coretype, dim_n, data_size, dims, data
	//long getCoreType(long);
	//long getDimN(long);	//count of dims
	//long getDataLength(long);	//get the total count of data
	long getNthDim(long,long);	//the nth dim's size
	long getEleAddr(long,long);	//get nth data of array. pars: instarray, relative addr from head of data.
	long getSize(long);//total size of instarray obj

};

#endif /* SRC_TYPESYS_ABTYPEARRAY_H_ */
