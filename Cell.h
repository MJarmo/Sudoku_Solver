/*
 * Cell.h
 *
 *  Created on: Apr 29, 2018
 *      Author: root
 */

#ifndef CELL_H_
#define CELL_H_
#include<iostream>
using namespace std;

struct Cell
{
	int mValue;
	bool mLock;
	Cell(){}
	Cell(int value)
	{

			mValue=value;
			if(value!=0)
			{
				mLock=true;
			}
			else
			{
				mLock=false;
			}
	}
	void setValue(int value)
	{
		mValue=value;
		if(value!=0)
			{
				mLock=true;
			}
			else
			{
				mLock=false;
			}
	}
	void set(int v)
	{
		mValue=v;
	}


};






#endif /* CELL_H_ */
