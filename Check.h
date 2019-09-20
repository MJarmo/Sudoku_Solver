/*
 * Check.h
 *
 *  Created on: Apr 29, 2018
 *      Author: root
 */

#ifndef CHECK_H_
#define CHECK_H_

struct Check
{
	int mNr[9];
	int mCounter[9];

	Check()
	{
		for(int i=0;i<9;i++)
		{
			mNr[i]=i+1;
			mCounter[i]=0;
		}
	}

	void cleanCounter()
	{
		for(int i=0;i<9;i++)
		{
			mCounter[i]=0;
		}
	}
};



#endif /* CHECK_H_ */
