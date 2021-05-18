#include <iostream>
#include <fstream>
#include <cstdlib>

#include "rubiksCubeWhiteCross.hpp"

using namespace std;

int countWhiteCross(string array[ROW][COLUMN])
{
	int count = 0;
	
	for(int index = 0; index < EDGE_NUM; index++)
	{
		if(array[BOTTOM][(2*index + 1)] == WHITE_CHAR)
		{
			count++;	
		}
	}
	return count;
}

bool isWhiteCrossDone(string array[ROW][COLUMN])
{
	return (countWhiteCross(array) == 4);	
}

void spaceOnWhite(string array[ROW][COLUMN], int position)
{
	bool spaceOnWhite = false;
	
	while(!spaceOnWhite)
	{
		spaceOnWhite = (array[BOTTOM][position] != WHITE_CHAR);

		if(!spaceOnWhite)
		{
			moveCube(array, moveD, true);
		}
	}	
}

void whiteEdgeOnYellow(string array[ROW][COLUMN], int nWhite)
{
	if(nWhite == 1 || nWhite == 5)		// position 1 and 5 are inverted on yellow and white
	{	// check that there is no white edge 
		spaceOnWhite(array,(nWhite+4)%8);	
	}
	else if(nWhite == 3 || nWhite == 7)
	{
		spaceOnWhite(array,nWhite);
	
	}
	switch(nWhite)
	{
		case 1:
			moveCubeTwice(array, moveB, true);
			break;
		case 3:
			moveCubeTwice(array, moveR, true);
			break;
		case 5:	
			moveCubeTwice(array, moveF, true);
			break;
		default:
			moveCubeTwice(array, moveL, true);
			break;
	}
	
}

void whiteEdgeOnSides(string array[ROW][COLUMN], string arrayCenter[CENTER], int sideIndex, int nWhite)
{
	moveSideToFront(array, arrayCenter, sideIndex, true);
	
	if(nWhite == 5)
	{
		moveCubeReverse(array, moveF, true);
		nWhite = 3;	
	}
	
	if(nWhite == 1)
	{
		spaceOnWhite(array, nWhite);
		moveCube(array, moveF, true);
		nWhite = 3; 
	}
	
	if(nWhite == 3)
	{
		spaceOnWhite(array, nWhite);
		moveCubeReverse(array, moveR, true);
	}
	
	if(nWhite == 7)
	{
		spaceOnWhite(array, nWhite);
		moveCube(array, moveL, true);	
	}
	
}

void makeWhiteCross(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	while(!isWhiteCrossDone(array))
	{
		int colorSide = 0;
		int whitePosition = 0;
		
		findEdge(array, WHITE_CHAR, colorSide, whitePosition);
		
		if(colorSide == TOP)
		{
			whiteEdgeOnYellow(array, whitePosition);	
		}
		else
			whiteEdgeOnSides(array, arrayCenter, colorSide, whitePosition);
	
		//printCube(array, arrayCenter);
	}
	
	cout << "\nWhite Cross Done!" << endl;
	printCube(array, arrayCenter);
	
}

// --------------------------

int countRightWhiteEdges(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int countEdge = 0;
	
	for(int index = 1; index < CENTER - 1; index++)
	{
		if(array[index][5] == arrayCenter[index])
		{
			countEdge++;	
		}
	}
	
	return countEdge;	
}

int whiteEdgeColor(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int color = 0;
	
	for(int index = 1; index < CENTER - 1; index++)
	{
		if(array[index][5] != arrayCenter[index])
		{
			color = index;
			index = CENTER; 	
		}	
	}
	
	return color;
}

void setTwoWhiteCross(string array[ROW][COLUMN], string arrayCenter[CENTER], int centerColor)
{
	int difference = centerColor - FRONT; // 1, 2 or 3 
	int indexCopy = difference;
	
	moveCubeTwice(array, moveF, true);
	
	while(difference > 0)
	{
		moveCubeReverse(array, moveU, true);	
		difference--;
	}
	
	if(indexCopy == 1 )
		moveCubeTwice(array, moveR, true);
	else if(indexCopy == 2)
		moveCubeTwice(array, moveB, true);
	else if(indexCopy == 3)
		moveCubeTwice(array, moveL, true);
		
	while(indexCopy > 0)
	{
		moveCube(array, moveU, true);
		indexCopy--;	
	}
	
	moveCubeTwice(array, moveF, true);
	
}


void setWhiteCross(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	while(countRightWhiteEdges(array, arrayCenter) == 0 )
	{
		moveCube(array, moveD, true);	
	}
	
	int numEdges = countRightWhiteEdges(array, arrayCenter);
	
	
	if(numEdges != 4)
	{
		int initialColor = whiteEdgeColor(array, arrayCenter);
		
		moveSideToFront(array, arrayCenter, initialColor, true);
			
		int positionToMove = sideIndex(array, arrayCenter, FRONT, 5); 
		
		if(numEdges == 2)
		{
			setTwoWhiteCross(array, arrayCenter, positionToMove);
		}
		else if(numEdges == 1)
		{
			setTwoWhiteCross(array, arrayCenter, positionToMove);
			setWhiteCross(array, arrayCenter);
		}
	}
	

}

