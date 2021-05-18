#include <iostream>
#include <fstream>
#include <cstdlib>

#include "rubiksCubeWhiteCorners.hpp"

using namespace std;



int countRightWhiteCorners(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int countCorners = 0;
	
	for(int index = 0; index < 4; index++)
	{
		if(array[BOTTOM][index*2] == WHITE_CHAR)
		{
			if(array[index+1][6] == arrayCenter[index+1])
			{
				countCorners++;
			}
		}
	
	}
		
	return countCorners;
	
}

void moveWhiteCornerTopLeft(string array[ROW][COLUMN])
{
	moveCubeReverse(array, moveU, true);
	moveCubeReverse(array, moveL, true);
	moveCube(array, moveU, true);
	moveCube(array, moveL, true);
}

void moveWhiteCornerTopRight(string array[ROW][COLUMN])
{
	moveCube(array, moveU, true);
	moveCube(array, moveR, true);
	moveCubeReverse(array, moveU, true);
	moveCubeReverse(array, moveR, true);

}

void moveWhiteCornerTopSide(string array[ROW][COLUMN], string arrayCenter[CENTER], int centerIndex, int whiteIndex)
{
	moveSideToFront(array, arrayCenter, centerIndex, true);   // check true or false

	int cornerTop = 0;
	int cornerLeft = 0;
	
	cornerIndex(array, arrayCenter, FRONT, whiteIndex, cornerTop, cornerLeft);
	
	int moveTimes = 0;
	int sideColor = 0;
	
	if(whiteIndex == 0)
	{
		moveTimes = cornerLeft;
		if(moveTimes == 4)
		{
			moveTimes = 0;
		}
		sideColor = cornerTop;
		
	}
	else if(whiteIndex == 2)
	{
		moveTimes = cornerTop - 2;	
		sideColor = cornerLeft;
	}
	
	while(moveTimes > 0)
	{
		moveCubeReverse(array, moveU, true);
		moveTimes--;	
	}
	
	moveSideToFront(array, arrayCenter, sideColor, true);  // check true or false
	
	cout << endl;
	
	if(whiteIndex == 0)
		moveWhiteCornerTopLeft(array);	
	else if(whiteIndex == 2)
		moveWhiteCornerTopRight(array);
	
}

void moveWhiteCornerTopTop(string array[ROW][COLUMN], string arrayCenter[CENTER], int whiteIndex)
{
	int cornerTop = 0;
	int cornerLeft = 0;
	
	cornerIndex(array, arrayCenter, TOP, whiteIndex, cornerTop, cornerLeft);
		
	string colorTop = arrayCenter[cornerTop];
	string colorLeft = arrayCenter[cornerLeft];
	

	int moveBack = 0;

	while(whiteIndex != 4)
	{
		moveCube(array, moveU, false);
		whiteIndex = (whiteIndex + 2)%8;
		moveBack++;
	}
		
	int moveCubeTimes = moveBack;
		
	while(moveBack > 0)
	{
		moveCubeReverse(array, moveU, false);
		moveBack--;
	}
	
	
	
	moveBack = moveCubeTimes;						
	
	while(moveBack > 0)		// have the corner on FAKE FRONT TOP RIGHT
	{
		moveEntireCubeYNormal(array, arrayCenter, false);
		moveBack--;
	}
	
	int difference = 0;

	for(int index = 0; index < CENTER; index++)
	{
		if(arrayCenter[index] == colorLeft)
		{
			difference = index - FRONT;	// gets how many moves I need to make
		}
	}
		
	moveBack = moveCubeTimes;						

	while(moveBack > 0)
	{
		moveEntireCubeYReverse(array, arrayCenter, false);
		moveBack--; 	
	}
	
	while(difference > 0)
	{
		moveCubeReverse(array, moveU, true);
		difference--;	
	}
	
	while(array[FRONT][2] != colorTop || array[RIGHT][0] != colorLeft)	// move cube 
	{
		moveEntireCubeYNormal(array, arrayCenter, true);
	}

	moveCube(array, moveR, true);
	moveCubeTwice(array, moveU, true);
	moveCubeReverse(array, moveR, true);
	moveCubeReverse(array, moveU, true);
	moveCube(array, moveR, true);
	moveCube(array, moveU, true);
	moveCubeReverse(array, moveR, true);

}

void moveWhiteCornerBotSide(string array[ROW][COLUMN], string arrayCenter[CENTER], int centerIndex, int whiteIndex)
{
	if(centerIndex != FRONT)
		moveSideToFront(array, arrayCenter, centerIndex, true);	
		
		
	if(whiteIndex == 4)
	{
		moveCube(array, moveR, true);
		moveCubeReverse(array, moveU, true);
		moveCubeReverse(array, moveR, true);
	}
	else if(whiteIndex == 6)
	{
		moveCubeReverse(array, moveL, true);
		moveCube(array, moveU, true);
		moveCube(array, moveL, true);
	}
	
}

int findWrongWhiteCornerBot(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int colorTop = 0, colorLeft = 0, whiteIndex = 0, turnCube = 0; 
	bool found = false;
	
	do
	{
		cornerIndex(array, arrayCenter, BOTTOM, whiteIndex, colorTop, colorLeft);
		
		if((whiteIndex/2)+1 != colorTop)
		{
			found = true;	
		}
		else
		{
			turnCube++;
			whiteIndex = whiteIndex + 2;	
		}
	
	}while(!found);
	
	return turnCube + FRONT;
}

void moveWhiteCornerBotBot(string array[ROW][COLUMN],string arrayCenter[CENTER], int turnSide)
{
	moveSideToFront(array, arrayCenter, turnSide, true);
	
	moveCubeReverse(array, moveL, true);
	moveCubeReverse(array, moveU, true);
	moveCube(array, moveL, true);
	
	// then call moveWhiteCornerTopSide function.
	
}

void makeWhiteCorners(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int sideIndex = 0, positionIndex = 0;
	
	while(countRightWhiteCorners(array, arrayCenter) != 4)
	{
		
		findCorner(array, WHITE_CHAR, sideIndex, positionIndex);
				
		if(sideIndex == TOP)
		{
			moveWhiteCornerTopTop(array, arrayCenter, positionIndex);	
		}
		else if(sideIndex != BOTTOM && (positionIndex == 0 || positionIndex == 2))
		{
			moveWhiteCornerTopSide(array, arrayCenter, sideIndex, positionIndex);
		}
		else if(sideIndex != BOTTOM && (positionIndex == 4 || positionIndex == 6))
		{
			moveWhiteCornerBotSide(array, arrayCenter, sideIndex, positionIndex);	
		}
		else
		{
			moveWhiteCornerBotBot(array, arrayCenter, sideIndex);	
		}
	
		//printCube(array, arrayCenter);
		
	}
	
	cout << "\nWhite Corners Done!" << endl;
	printCube(array, arrayCenter);
}
