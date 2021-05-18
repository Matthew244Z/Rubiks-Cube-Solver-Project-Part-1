#include <iostream>
#include <fstream>
#include <cstdlib>
#include "rubiksCubeUsefulFunctions.hpp"

using namespace std;

void printCube(string array[ROW][COLUMN], string arrayCenter[CENTER])
{	
	cout << endl;
	
	for(int indexRow = 0; indexRow < ROW; indexRow++)
	{
		for(int indexCol = 0; indexCol < 3; indexCol++)
		{
			cout << "[" << array[indexRow][indexCol] << "]";
		}
		cout << "  ";
	}
	
	cout << endl;
	
	for(int indexRow = 0; indexRow < ROW; indexRow++)
	{
		cout << "[" << array[indexRow][7] << "][";
		
		cout << arrayCenter[indexRow];

		cout << "][" << array[indexRow][3] << "]  ";	
	}
	
	cout << endl;
	
	for(int indexRow = 0; indexRow < ROW; indexRow++)
	{		
		for(int indexCol = 6; indexCol > 3; indexCol--)
		{
			cout << "[" << array[indexRow][indexCol] << "]";
		}
		cout << "  ";
	}
	
	cout << endl << endl;
}

// -------------

void scramble(ifstream & fin, string array[ROW][COLUMN])
{
	string move = "";
	
	while(fin >> move)
	{
		if(move == "R")
			moveCube(array, moveR, true);	
		else if(move == "L")
			moveCube(array, moveL, true);
		else if(move == "U")
			moveCube(array, moveU, true);
		else if(move == "D")
			moveCube(array, moveD, true);
		else if(move == "F")
			moveCube(array, moveF, true);
		else if(move == "B")
			moveCube(array, moveB, true); // -------------
		else if(move == "R'")
			moveCubeReverse(array, moveR, true);
		else if(move == "L'")
			moveCubeReverse(array, moveL, true);
		else if(move == "U'")
			moveCubeReverse(array, moveU, true);
		else if(move == "D'")
			moveCubeReverse(array, moveD, true);
		else if(move == "F'")
			moveCubeReverse(array, moveF, true);
		else if(move == "B'")
			moveCubeReverse(array, moveB, true); // -----------------
		else if(move == "R2")
			moveCubeTwice(array, moveR, true);
		else if(move == "L2")
			moveCubeTwice(array, moveL, true);
		else if(move == "U2")
			moveCubeTwice(array, moveU, true);
		else if(move == "D2")
			moveCubeTwice(array, moveD, true);
		else if(move == "F2")
			moveCubeTwice(array, moveF, true);
		else if(move == "B2")
			moveCubeTwice(array, moveB, true);
			
	
	}
	
	cout << endl;
}

// ---------------

void findEdge(string array[ROW][COLUMN], string color, int & nSide, int & nPosition)
{
	for(int indexRow = 0; indexRow < ROW; indexRow++)
	{
		for(int indexCol = 0; indexCol < EDGE_NUM; indexCol++)
		{
			if(array[indexRow][(2*indexCol)+1] == color)
			{
				nSide = indexRow;
				nPosition = 2*indexCol+1;
				
				indexCol = EDGE_NUM;	// exit loop
				indexRow = ROW;	
			}
		}
	}
	
}

void findCorner(string array[ROW][COLUMN], string color, int & nSide, int & nPosition)
{
	for(int indexRow = 0; indexRow < ROW; indexRow++)
	{		
		for(int indexCol = 0; indexCol < EDGE_NUM; indexCol++)
		{
			if(array[indexRow][2*indexCol] == color)
			{
				nSide = indexRow;
				nPosition = (2*indexCol);
				
				indexCol = EDGE_NUM;	// exit loop
				indexRow = ROW;	
			}
		}
	}
	
}

int sideIndex(string array[ROW][COLUMN], string arrayCenter[CENTER], int initialSide, int positionIndex)
{
	int centerIndex = 0;
	
	for(int index = 0; index < CENTER; index++)
	{
		if(array[initialSide][positionIndex] == arrayCenter[index])
		{
			centerIndex = index;
		}
	}
	
	return centerIndex;	
}

void moveSideToFront(string array[ROW][COLUMN], string arrayCenter[CENTER], int colorToMove, bool print)
{
	if(colorToMove == 2)
		moveEntireCubeYNormal(array, arrayCenter, print);
	else if(colorToMove == 3)	
		moveEntireCubeYTwice(array, arrayCenter, print);
	else if(colorToMove == 4)
		moveEntireCubeYReverse(array, arrayCenter, print);	
	else if(colorToMove == 0)
		moveEntireCubeXReverse(array, arrayCenter, print);
	else if(colorToMove == 5)
		moveEntireCubeXNormal(array, arrayCenter, print); 
}


void cornerIndex(string array[ROW][COLUMN], string arrayCenter[CENTER], int nSide, int nPosition, int & colorTop, int & colorLeft)
{
	string moveBack = arrayCenter[FRONT];	// get color , not index 
	
	moveSideToFront(array, arrayCenter, nSide, false);	
	
	int turnsF = 0;
	
	while(nPosition != 0)		// make sure corner is in position 0 (top left)
	{
		moveCube(array, moveF, false);
		nPosition = (nPosition + 2) % 8;
		turnsF++;
	}
	
	string cornerTop = array[TOP][6];	// get color only
	string cornerLeft = array[LEFT][2];	// since the index will change back
	
	int moveCubeBack = 0;
	
	for(int index = 0; index < CENTER; index++)
	{
		if(arrayCenter[index] == moveBack)
		{
			moveCubeBack = index;	// change the color to the index
		}
	}
	
	while(turnsF > 0)
	{
		moveCubeReverse(array, moveF, false);
		turnsF--; 	
	}
	
	moveSideToFront(array, arrayCenter, moveCubeBack, false);	// original cube orientation
	
	
	for(int index = 0; index < CENTER; index++)
	{
		if(arrayCenter[index] == cornerTop)
		{
			colorTop = index;
		}
		
		if(arrayCenter[index] == cornerLeft)
		{
			colorLeft = index;
		}
	}
	
}

int edgeIndex(string array[ROW][COLUMN], string arrayCenter[CENTER], int nSide, int nPosition)
{
	string moveBack = arrayCenter[FRONT];
	
	moveSideToFront(array, arrayCenter, nSide, false);
	
	int turnsF = 0;
	
	while(nPosition != 1)
	{
		moveCube(array, moveF, false);
		nPosition = (nPosition + 2)%8;
		turnsF++; 
	}
	
	string edgeColor = array[TOP][5];	// color string
	
	while(turnsF > 0)
	{
		moveCubeReverse(array, moveF, false); 	
		turnsF--;
	}
	
	int moveCubeBack = 0;
	
	for(int index = 0; index < CENTER; index++)
	{
		if(arrayCenter[index] == moveBack)
		{
			moveCubeBack = index;	// change the color to the index
		}
	}
	
	moveSideToFront(array, arrayCenter, moveCubeBack, false);
	
	int edgeIndex = 0;
	
	for(int index = 0; index < CENTER; index++)
	{
		if(arrayCenter[index] == edgeColor)
		{
			edgeIndex = index;
		}
		
	}
	
	
	return edgeIndex;
		
}

