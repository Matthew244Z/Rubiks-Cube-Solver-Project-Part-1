#include <iostream>
#include <fstream>
#include <cstdlib>
#include "rubiksCubeBases.hpp"

using namespace std;


void buildArray(ifstream & fin, string array[ROW][COLUMN])	
{
	string color = "";
	
	for(int indexRow = 0; indexRow < ROW; indexRow++)
	{
		for(int indexCol = 0; indexCol < COLUMN; indexCol++)
		{
			fin >> color;
			array[indexRow][indexCol] = color;
		}
	}
	
}

void printArray(string array[ROW][COLUMN])		// not used
{
	
	for(int indexRow = 0; indexRow < ROW; indexRow++)
	{
		for(int indexCol = 0; indexCol < COLUMN; indexCol++)
		{
			cout << array[indexRow][indexCol] << " ";
		}
		cout << "\n";
	}
	
	cout << "\n";
}

// --------------------	

void moveLayer(string array[ROW][COLUMN], Movement const & moveX)
{
	string copy[FOUR_SIDES];
	
	copy[0] = array[moveX.get_sideA()][moveX.get_sA0()];
	copy[1] = array[moveX.get_sideA()][moveX.get_sA1()];
	copy[2] = array[moveX.get_sideA()][moveX.get_sA2()];
	
	copy[3] = array[moveX.get_sideB()][moveX.get_sB0()];
	copy[4] = array[moveX.get_sideB()][moveX.get_sB1()];
	copy[5] = array[moveX.get_sideB()][moveX.get_sB2()];
	
	copy[6] = array[moveX.get_sideC()][moveX.get_sC0()];
	copy[7] = array[moveX.get_sideC()][moveX.get_sC1()];
	copy[8] = array[moveX.get_sideC()][moveX.get_sC2()];
	
	copy[9] = array[moveX.get_sideD()][moveX.get_sD0()];
	copy[10] = array[moveX.get_sideD()][moveX.get_sD1()];
	copy[11] = array[moveX.get_sideD()][moveX.get_sD2()];
	
	// change
	
	array[moveX.get_sideA()][moveX.get_sA0()] = copy[3];
	array[moveX.get_sideA()][moveX.get_sA1()] = copy[4];
	array[moveX.get_sideA()][moveX.get_sA2()] = copy[5];
	
	array[moveX.get_sideB()][moveX.get_sB0()] = copy[6];
	array[moveX.get_sideB()][moveX.get_sB1()] = copy[7];
	array[moveX.get_sideB()][moveX.get_sB2()] = copy[8];
	
	array[moveX.get_sideC()][moveX.get_sC0()] = copy[9];
	array[moveX.get_sideC()][moveX.get_sC1()] = copy[10];
	array[moveX.get_sideC()][moveX.get_sC2()] = copy[11];
	
	array[moveX.get_sideD()][moveX.get_sD0()] = copy[0];
	array[moveX.get_sideD()][moveX.get_sD1()] = copy[1];
	array[moveX.get_sideD()][moveX.get_sD2()] = copy[2];
}

void moveSide(string array[ROW][COLUMN], Movement const & moveX)
{
	string copySide[ONE_SIDE];
	
	for(int index = 0; index < ONE_SIDE; index++)
	{
		copySide[index] = array[moveX.get_side()][index];	
	}
	
	for(int index = 0; index < ONE_SIDE; index++)
	{
		array[moveX.get_side()][(index+2)%ONE_SIDE] = copySide[index];	
	}
	
}

void moveCube(string array[ROW][COLUMN], Movement const & moveX, bool print)
{
	moveLayer(array, moveX);
	moveSide(array, moveX);
	if(print)
	{
		moveX.print_side();
		cout << " ";
	}
}

void moveCubeTwice(string array[ROW][COLUMN], Movement const & moveX, bool print)
{
	moveLayer(array, moveX);
	moveSide(array, moveX);
	moveLayer(array, moveX);
	moveSide(array, moveX);
	if(print)
	{
		moveX.print_side();
		cout << "2 ";
	}
}

void moveCubeReverse(string array[ROW][COLUMN], Movement const & moveX, bool print)
{
	moveLayer(array, moveX);
	moveSide(array, moveX);
	moveLayer(array, moveX);
	moveSide(array, moveX);
	moveLayer(array, moveX);
	moveSide(array, moveX);	
	if(print)
	{
		moveX.print_side();
		cout << "' ";
	}
}


// --------------------

void moveEntireCubeY(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	string temp[ONE_SIDE];
	
	for(int indexCol = 0; indexCol < COLUMN; indexCol++)
	{
		temp[indexCol] = array[FRONT][indexCol];	
	}
	
	for(int indexRow = 1; indexRow < ROW - 1; indexRow++)
	{
		for(int indexCol = 0; indexCol < COLUMN; indexCol++)
		{
			array[indexRow][indexCol] = array[indexRow + 1][indexCol];
		}
	}
	
	for(int indexCol = 0; indexCol < COLUMN; indexCol++)
	{
		array[LEFT][indexCol] = temp[indexCol];	
	}
	
	string tempCenter = "";	
	tempCenter = arrayCenter[FRONT];	
	
	for(int index = 1; index < ROW - 1; index++)
	{
		arrayCenter[index] = arrayCenter[index+1];	
	}
	
	arrayCenter[LEFT] = tempCenter;
	
	moveSide(array, moveU);
	moveSide(array, moveD);
	moveSide(array, moveD);
	moveSide(array, moveD);	
}

void moveEntireCubeYNormal(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print)
{
	moveEntireCubeY(array, arrayCenter);
	if(print)
	{
		cout << "Y ";
	}
}

void moveEntireCubeYReverse(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print)
{
	moveEntireCubeY(array, arrayCenter);
	moveEntireCubeY(array, arrayCenter);
	moveEntireCubeY(array, arrayCenter);
	if(print)
	{
		cout << "Y' ";
	}
}

void moveEntireCubeYTwice(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print)
{
	moveEntireCubeY(array, arrayCenter);
	moveEntireCubeY(array, arrayCenter);
	if(print)
	{
		cout << "Y2 ";
	}	
}

// --------------------

void moveEntireCubeX(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	string temp[ONE_SIDE];	
	
	//make copy of yellow
	for(int indexCol = 0; indexCol < COLUMN; indexCol++)
		temp[indexCol] = array[TOP][indexCol];

	// blue to yellow
	for(int indexCol = 0; indexCol < COLUMN; indexCol++)
		array[TOP][indexCol] = array[FRONT][indexCol];	

	// white to blue
	for(int indexCol = 0; indexCol < COLUMN; indexCol++)
		array[FRONT][indexCol] = array[BOTTOM][indexCol];

	// green to white
	for(int indexCol = 4; indexCol < 8; indexCol++)
		array[BOTTOM][indexCol - 4] = array[BEHIND][indexCol];

	for(int indexCol = 0; indexCol < 4; indexCol++)
		array[BOTTOM][indexCol + 4] = array[BEHIND][indexCol];

	// copy to green		
	for(int indexCol = 4; indexCol < 8; indexCol++)
		array[BEHIND][indexCol - 4] = temp[indexCol];
		
	for(int indexCol = 0; indexCol < 4; indexCol++)
		array[BEHIND][indexCol + 4] = temp[indexCol];
		
		
	string tempCenter = "";
	
	tempCenter = arrayCenter[0];
	
	arrayCenter[0] = arrayCenter[1];
	
	for(int index = 0; index < 2; index++)
		arrayCenter[index*4 + 1] = arrayCenter[((index+1)*4 + 1)%6];
		
	arrayCenter[3] = tempCenter;
	
	
	moveSide(array, moveR);
	moveSide(array, moveL);
	moveSide(array, moveL);
	moveSide(array, moveL);
}

void moveEntireCubeXNormal(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print)
{
	moveEntireCubeX(array, arrayCenter);
	if(print)
	{
		cout << "X ";
	}	
}

void moveEntireCubeXReverse(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print)
{
	moveEntireCubeX(array, arrayCenter);
	moveEntireCubeX(array, arrayCenter);
	moveEntireCubeX(array, arrayCenter);
	if(print)
	{
		cout << "X' ";
	}
}

// ------------- 

void moveMiddleNormal(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print)
{
	moveEntireCubeXReverse(array, arrayCenter, false);
	moveCube(array, moveR, false);
	moveCubeReverse(array, moveL, false);
	if(print)
	{
		cout << "M "; 	
	}
		
}

void moveMiddleReverse(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print)
{
	moveEntireCubeXNormal(array, arrayCenter, false);
	moveCube(array, moveL, false);
	moveCubeReverse(array, moveR, false);
	if(print)
	{
		cout << "M' "; 	
	}
		
	
}


