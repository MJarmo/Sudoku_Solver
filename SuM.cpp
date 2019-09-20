/*
 * SuM.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: root
 */

#ifndef SUM_CPP_
#define SUM_CPP_
#include "SuM.h"
using namespace std;
void SuM::printSu()
{
	for(int r=0;r<9;r++)
	{
		for(int c=0;c<9;c++)
		{
			cout<<b[r][c].mValue<<", ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void SuM::setSudoku(int su_in[9][9])
{
	for(int r=0;r<9;r++)
	{
		for(int c=0;c<9;c++)
		{
			b[r][c].setValue(su_in[r][c]);
		}
	}
}

bool SuM::checkSudoku()
{
	//By Columns
	for(int r=0;r<9;r++)
	{
		if(SuM::checkColumn(r)!=13) return false;
	}
	//By Rows
	for(int r=0;r<9;r++)
	{
		if(SuM::checkRow(r)!=13) return false;
	}
	//By Sqr
	for(int r=0;r<3;r++)
	{
		for(int c=0;c<3;c++)
		{
			if(SuM::checkSqr(c,r) !=13) return false;
		}
	}
	return true;

}

int SuM::checkRow(int r)
{
	check.cleanCounter();
	for(int nr=1;nr<10;nr++)
	{
		for (int c=0;c<9;c++)
		{
			if(nr==b[c][r].mValue)
			{
				check.mCounter[nr-1]+=1;
			}
		}
	}
	for(int n=0;n<9;n++)
	{
		if(check.mCounter[n]>1)
		{
			cout<<"Ther is few same numbers: "<<check.mNr[n]<<" in column: "<<r+1<<endl;
			return check.mNr[n];
		}
	}
	check.cleanCounter();
	return 13;
}
int SuM::checkColumn(int col)
{
	check.cleanCounter();
	int r=col;
	for(int nr=1;nr<10;nr++)
	{
		for (int c=0;c<9;c++)
		{
			if(nr==b[r][c].mValue)
			{
				check.mCounter[nr-1]+=1;
			}
		}
	}
	for(int n=0;n<9;n++)
	{
		if(check.mCounter[n]>1)
		{
			cout<<"Ther is few same numbers:"<<check.mNr[n]<<" in row: "<<r+1<<endl;
			return check.mNr[n]; 					}
	}
	check.cleanCounter();
	return 13;
}
void SuM::fillColumn(int col)
{
	if(SuM::checkColumn(col) == 13)
	{
		int zeroCol=0;
		int zeroCount = 0;
		for(int row=0;row<9;row++)
		{
			if(b[row][col].mValue == 0)
			{
				++zeroCount;
				zeroCol=row;
			}

		}
		if(zeroCount==1)
		{
			for (int n=1;n<10;n++)
			{
				bool didIFind = false;
				for (int row=0;row<9;row++)
				{
					if(b[row][col].mValue==n)
					{
						didIFind = true;
						break;
					}
				}
				if(didIFind == false)
				{
					b[zeroCol][col].mValue = n;
					cout<<"I've filled some shit"<<endl;

				}
			}

		}
	}
	else
	{
		cout<<"Ther is mistake in column :"<< col<<endl;
	}
}
void SuM::fillColumns()
{
	for(int i=0;i<9;i++)
	{
		SuM::fillColumn(i);
	}
}
void SuM::fillRow(int row)
{
	if(SuM::checkRow(row) == 13)
	{
		SuM::checkRow(row);
		int zeroRow=0;
		int zeroCount = 0;
		for(int col=0;col<9;col++)
		{
			if(b[row][col].mValue == 0)
			{
				++zeroCount;
				zeroRow=col;
			}

		}
		if(zeroCount==1)
		{
			for (int n=1;n<10;n++)
			{
				bool didIFind = false;
				for (int col=0;col<9;col++)
				{
					if(b[row][col].mValue==n)
					{
						didIFind = true;
						break;
					}
				}
				if(didIFind == false)
				{
					b[row][zeroRow].mValue = n;
					cout<<"I've filled some shit"<<endl;

				}
			}

		}
	}
	else
	{
		cout<<"Ther is mistake in row: "<<row<<endl;
	}
}

int SuM::checkSqr(int rowSqr, int colSqr)
{
	check.cleanCounter();
	for(int row=rowSqr*3;row<rowSqr*3+3;row++)
	{
		for(int col=colSqr*3;col<colSqr*3+3;col++)
		{

			for(int nr=1;nr<10;nr++)
			{											{
				if(nr==b[row][col].mValue)
				{
					check.mCounter[nr-1]+=1;
				}
			}
			}
		}
		for(int n=0;n<9;n++)
		{
			if(check.mCounter[n]>1)
			{
				cout<<"Ther is few same numbers:"<<check.mNr[n]<<" in square x: "<<rowSqr<<" y: "<<colSqr<<endl;
				return check.mNr[n]; 					}
		}
	}
	check.cleanCounter();
	return 13;
}

void SuM::fillSqr(int rowSqr, int colSqr)
{
	if(SuM::checkSqr(rowSqr, colSqr) == 13)
	{
		int zeroRow = 0;
		int zeroCol = 0;
		int zeroCount = 0;
		for(int row=rowSqr*3;row<rowSqr*3+3;row++)
		{
			for(int col=colSqr*3;col<colSqr*3+3;col++)
			{
				if(b[row][col].mValue == 0)
				{
					++zeroCount;
					zeroRow = row;
					zeroCol = col;
				}
			}
		}
		if(zeroCount==1)
		{
			for (int n=1;n<10;n++)
			{
				bool didIFind = false;
				for (int row=rowSqr*3;row<rowSqr*3+3;row++)
				{
					for(int col=colSqr*3;col<colSqr*3+3;col++)
						if(b[row][col].mValue==n)
						{
							didIFind = true;
							break;
						}
				}
				if(didIFind == false)
				{
					b[zeroRow][zeroCol].mValue = n;
					cout<<"I've filled some shit"<<endl;
				}
			}
		}
	}
	else
	{
		cout<<"Ther is mistake in row x: "<<rowSqr<<" Y: "<<colSqr<<endl;
	}
}
void SuM::fillSqrs()
{
	for (int r=0;r<3;r++)
	{
		for(int c=0;c<3;c++)
		{
			SuM::fillSqr(r,c);
		}
	}
}
bool SuM::solvesudoku()
{
	int zeroCount = 0;
	for(int col=0;col<9;col++)
	{
		for(int row=0;row<9;row++)
		{
			if(b[row][col].mValue == 0)
			{
				++zeroCount;
			}

		}
	}
	if(zeroCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool SuM::checkColByNr(int nr, int col)
{
	for(int r=0;r<9;r++)
	{
		if(b[r][col].mValue == nr)
		{
			return false;
		}
	}
	return true;
}
bool SuM::checkRowByNr(int nr, int row)
{
	for(int c=0;c<9;c++)
	{
		if(b[row][c].mValue == nr)
		{
			return false;
		}
	}
	return true;
}
bool SuM::checkSqrByNr(int nr, int row, int col)
{
	//transfer row/col for sqr
	short rowSqr=row/3;
	short colSqr=col/3;
	for(int row=rowSqr*3;row<rowSqr*3+3;row++)
	{
		for(int col=colSqr*3;col<colSqr*3+3;col++)
		{
			if(nr == b[row][col].mValue)
			{return false;}
		}
	}
	return true;
}

void SuM::brutforce()
{
	short numbers = 1;
	bool t=true;
	for(int col=0;col<9;col++)
	{
		for(int row=0;row<9;row++)
		{ numbers =1;
		t=true;
		if(b[row][col].mLock==false)
		{numbers = 1;
		//printSu();
		while(t)
		{
			if(numbers>9)
			{
				if(row<=0 )
				{
					if(b[row][col].mLock==false)
					{
						b[row][col].set(20);
					}
					if(col>0)
					{
						--col;
					}
					row=8;
					numbers=b[row][col].mValue+1;
				}
				else
				{
					if(b[row][col].mLock==false)
					{
						b[row][col].set(20);
					}
					if(row>=1)
					{
						--row;
					}
					numbers=b[row][col].mValue+1;

				}
			}
			while(true)
			{

				if(b[row][col].mLock==false && numbers<10 && checkColByNr(numbers, col)== true && checkRowByNr(numbers, row)==true && checkSqrByNr(numbers,row,col) )
				{
					b[row][col].set(numbers);
					t=false;
					break;
				}
				if(numbers>9)
				{
					break;
				}
				++numbers;

			}


		}
		}
		}
	}


}
bool SuM::getFromFile()
{
	std::ifstream sudokuin("suin.txt");
	std::string line;
	short row=0, col=0;
	int happy=0;

	while(std::getline(sudokuin, line))
	{	row=0;
	stringstream ssin(line);
	while(row<18)
	{
		happy=line[row]-'0';
		cout<<happy<<" ";
		if(happy<0 ||9<happy)
		{
			cout<<"Ther is to high number in input"<<endl;
			return false;
		}
		if(happy != 0)
		{
			b[col][row/2].setFirstTime(happy);
		}
		else
		{
			b[col][row/2].mValue = happy;

		}
		row+=2;
	}
	cout<<endl;
	if(col>8) {cout<<"Ther is to much lines in input"<<endl; return false;}
	++col;
	}
	return true;
}

#endif /* SUM_CPP_ */
