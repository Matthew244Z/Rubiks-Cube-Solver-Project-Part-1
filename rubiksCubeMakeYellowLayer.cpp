#include <iostream>
#include <fstream>
#include <cstdlib>

#include "rubiksCubeMakeYellowLayer.hpp"

using namespace std;

int countYellowEdges(string array[ROW][COLUMN])
{
	int countEdges = 0;
	
	for(int index = 0; index < EDGE_NUM; index++)
	{
		if(array[TOP][(index*2) + 1] == YELLOW_CHAR)
		{
			countEdges++; 
		}
	
	}
	
	return countEdges;	
}

void moveYellowCross(string array[ROW][COLUMN])
{
	moveCube(array, moveF, true);
	moveCube(array, moveR, true);
	moveCube(array, moveU, true);
	moveCubeReverse(array, moveR, true);
	moveCubeReverse(array, moveU, true);
	moveCubeReverse(array, moveF, true);
}

void moveYellowCrossTwoEdges(string array[ROW][COLUMN])
{
	while(array[TOP][7] != YELLOW_CHAR)
	{
		moveCube(array, moveU, true);
	}
	
	int nSide = 0;
	int yellowEdge = 0;
	
	findEdge(array, YELLOW_CHAR, nSide, yellowEdge);
	
	if(yellowEdge == 5)
	{
		moveCube(array, moveU, true);	
	}
	
	moveYellowCross(array);
}

void makeYellowCross(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	while(countYellowEdges(array) != EDGE_NUM)
	{
		int countEdges = countYellowEdges(array);

		if(countEdges == 0)
		{
			moveYellowCross(array);
		}
		else if(countEdges == 2)
		{
			moveYellowCrossTwoEdges(array);
		}
		
	}
	
	cout << "\nYellow Cross Done!" << endl;
	printCube(array, arrayCenter);
}

// ---------------------

int countYellowCorners(string array[ROW][COLUMN])
{
	int countCorners = 0;
	
	for(int index = 0; index < EDGE_NUM; index++)
	{
		if(array[TOP][index*2] == YELLOW_CHAR)
		{
			countCorners++;	
		}
	}
	return countCorners;	
}

void moveYellowCorners(string array[ROW][COLUMN])
{
	moveCube(array, moveR, true);
	moveCube(array, moveU, true);
	moveCubeReverse(array, moveR, true);
	moveCube(array, moveU, true);
	moveCube(array, moveR, true);
	moveCubeTwice(array, moveU, true);
	moveCubeReverse(array, moveR, true);

}

void moveYellowCornersReverse(string array[ROW][COLUMN])
{
	moveCubeReverse(array, moveR, true);
	moveCubeReverse(array, moveU, true);
	moveCube(array, moveR, true);
	moveCubeReverse(array, moveU, true);
	moveCubeReverse(array, moveR, true);
	moveCubeTwice(array, moveU, true);
	moveCube(array, moveR, true);

}

void oneYellowCorner(string array[ROW][COLUMN])
{
	while(array[TOP][6] != YELLOW_CHAR)		// make sure yellow is in 6 
	{
		moveCube(array, moveU, true);
//		cout << " One Yellow Corner " << endl; 		// ------------------------------------------------
	}
	
	if(array[FRONT][2] == YELLOW_CHAR)
	{
		moveYellowCorners(array);	
	}
	else
	{
		moveCube(array, moveU, true);
		moveYellowCornersReverse(array);	
	}
	
	
	
}

void noYellowCorners(string array[ROW][COLUMN])
{
	while(array[LEFT][0] != YELLOW_CHAR || array[LEFT][2] != YELLOW_CHAR )
	{
		moveCube(array, moveU, true);
//		cout << " No Yellow Corners " << endl; 		// -----------------------------------------------
	}
	
	moveYellowCorners(array);
	
}

void twoYellowCorners(string array[ROW][COLUMN])
{
	bool repeat = true;
	bool conditionOne = false;
	bool conditionTwo = false;	
	
	do
	{	
		conditionOne = (array[TOP][0] == YELLOW_CHAR);
		conditionTwo = (array[TOP][2] == YELLOW_CHAR || array[TOP][4] == YELLOW_CHAR); 
		
		if(array[TOP][4] == YELLOW_CHAR)
		{
			conditionTwo = (array[FRONT][0] == YELLOW_CHAR);	
		}
		
//		cout << conditionOne << " " << conditionTwo << endl;		// ----------------------------
		
		if(conditionOne && conditionTwo)
		{
			repeat = false;	
		}
		else 
			moveCube(array, moveU, true);
//			cout << "Two Yellow Corners " << endl; 		// ------------------------------------------------

	}while(repeat);
	
	moveYellowCorners(array);
}

void makeYellowCorners(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	while(countYellowCorners(array) != EDGE_NUM)
	{
		int countCorners = countYellowCorners(array);
		
//		cout << "Count Corners: " << countCorners << endl;		// ------------------------------------
		
		if(countCorners == 0)
		{
			noYellowCorners(array);	
// 			cout << " no yellow if " << endl;			//	--------------------------------------------
		}
		else if(countCorners == 1)
		{
			oneYellowCorner(array);	
		}
		else if(countCorners == 2)
		{
			twoYellowCorners(array);	
		}
	
	
	}
	
	cout << "\nYellow Corners Done! " << endl;
	printCube(array, arrayCenter);
}

