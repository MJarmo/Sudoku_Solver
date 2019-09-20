//============================================================================
// Name        : Sudoku.cpp
// Author      : Michal
// Version     :
// Copyright   : 4Fun
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>

#include <fstream>
#include "Cell.h"
#include "SuM.h"
using namespace std;
int su_in [9] [9] ={{5, 0, 0, 0, 3, 6, 0, 0, 0},

					{0, 4, 3, 8, 0, 0, 0, 0, 0},

					{1, 0, 0, 0, 0, 0, 0, 0, 2},

					{0, 0, 7, 2, 4, 0, 0, 6, 5},

					{0, 8, 0, 0, 0, 0, 0, 7, 0},

					{4, 5, 0, 0, 9, 3, 1, 0, 0},

					{7, 0, 0, 0, 0, 0, 0, 0, 6},

					{0, 0, 0, 0, 0, 2, 3, 8, 0},

					{0, 0, 0, 6, 1, 0, 0, 0, 4}};



int main() {


	bool mainB=true;
	int p=0;
	SuM sudoku;
	cout<<"##############################################"<<endl;
	cout<<"############WELCOME IN SUDOKU SOLVER##########"<<endl;
	cout<<"##############################################"<<endl;
	cout<<"What would you like to do?"<<endl;
	cout<<"1.Load sudoku from file"<<endl;
	cout<<"2.Check sudoku"<<endl;
	cout<<"3.Solve sudoku"<<endl;
	cout<<"4.Exit"<<endl;
	while(mainB)
	{
		cin>>p;
		switch (p)
		{
		case 1:
		{
			if(sudoku.getFromFile())
			{
				cout<<"Loaded sucesfully, Here's your sudoku: "<<endl; sudoku.printSu();
			}
			else cout<<"Failed to load sudoku, ther might be a mistake"<<endl;
			break;
		}
		case 2:
		{
			if(sudoku.checkSudoku()) cout<<"Sudoku looks ine.....for now"<<endl;
			else cout<<"Thers is mistake in your Input sudoku"<<endl;

			break;}
		case 3:
		{
			sudoku.brutforce();
			sudoku.printSu();
			break;
		}
		case 4:
		{
			cout<<"Have a nice day"<<endl;
			return 1;
		}
		}

	}



	return 0;
}
