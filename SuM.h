/*
 * SuM.h
 *
 *  Created on: Apr 29, 2018
 *      Author: root
 */

#ifndef SUM_H_
#define SUM_H_
#include "Cell.h"
#include "Check.h"
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

class SuM
{
public:
	Cell b[9][9];
	Check check;
	SuM()
	{
		for(int r=0;r<9;r++)
		{
			for(int c=0;c<9;c++)
			{
				b[r][c].setValue(0);
			}
		}
	}
	void printSu();
	void setSudoku(int su_in[9][9]);
	int  checkRow(int r);
	int  checkColumn(int col);
	bool  checkSudoku();
	void fillColumn(int col);
	void fillColumns();
	void fillRow(int row);
	int  checkSqr(int rowSqr, int colSqr);
	void fillSqr(int rowSqr, int colSqr);
	void fillSqrs();
	void checkPosib(int row, int col);
	bool solvesudoku();
	bool checkRowByNr(int nr, int row);
	bool checkColByNr (int nr, int col);
	bool checkSqrByNr(int nr, int row, int col);
	void recu(int row, int col, int nr);
	void brutforce();
	bool getFromFile();
	std::string listFiles();

};



#endif /* SUM_H_ */
