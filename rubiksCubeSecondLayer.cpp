#include <iostream>
#include <fstream>
#include <cstdlib>

#include "rubiksCubeSecondLayer.hpp"

using namespace std;

int countRightEdgeSL(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int countEdge = 0;
	
	for(int index = 0; index < EDGE_NUM; index++)
	{
		if(array[FRONT][3] == arrayCenter[FRONT] && array[RIGHT][7] == arrayCenter[RIGHT])
		{
			countEdge++;
		}
		
		moveEntireCubeYNormal(array, arrayCenter, false);
		
	}
	
	return countEdge;
	
}


int findSLEdgeTop(string array[ROW][COLUMN], string arrayCenter[CENTER], string color)
{
	int nPosition = -1;
	
	int tempPosition = 0;
	
	for(int indexCol = 0; indexCol < EDGE_NUM; indexCol++)
	{
		if(array[TOP][(2*indexCol)+1] != color)
		{
			tempPosition = 2*indexCol+1;
			
			int iEdge = edgeIndex(array, arrayCenter, TOP, tempPosition);
			
			if (iEdge != TOP)
			{
				nPosition = tempPosition;
				indexCol = EDGE_NUM;	// exit loop
			}
		}
	}
	
	return nPosition;
}

void moveSLTopLeft(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	moveWhiteCornerTopLeft(array);	
	moveEntireCubeYReverse(array, arrayCenter, true);
	moveWhiteCornerTopRight(array);
	
}

void moveSLTopRight(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	moveWhiteCornerTopRight(array);
	moveEntireCubeYNormal(array, arrayCenter, true);
	moveWhiteCornerTopLeft(array);	
}

void moveSLTop(string array[ROW][COLUMN], string arrayCenter[CENTER], int positionEdgeTop, int nEdgeSide)
{
	string edgeTopColor = array[TOP][positionEdgeTop];	// the position of the top edge on the yellow side
	string edgeSideColor = arrayCenter[nEdgeSide];		// index of the color of that face that needs to go
	
	moveSideToFront(array, arrayCenter, nEdgeSide, true);
	
	for(int index = 0; index < CENTER; index++)	
	{
		if(arrayCenter[index] == edgeTopColor)
			positionEdgeTop = index;
	}
	
	while(array[FRONT][1] != edgeSideColor || array[TOP][5] != edgeTopColor)
	{
		moveCube(array, moveU, true);	// put edge in the center
	}
	
	if(positionEdgeTop == 2)
	{
		moveSLTopRight(array, arrayCenter);	
	}
	else if(positionEdgeTop == 4)
	{
		moveSLTopLeft(array, arrayCenter);	
	}

}

//---------------------------------------

void wrongSLEdgeMiddle(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int wrongEdge = 0;
	
	for(int index = 0; index < EDGE_NUM; index++)
	{
		if(arrayCenter[index+1] != array[index+1][7] && arrayCenter[(index+3)%4 + 1] != array[(index+3)%4 + 1][3])
		{
			wrongEdge = index + 1;			
		}
	}
	
	moveSideToFront(array, arrayCenter, wrongEdge, true);
	
	moveCubeReverse(array, moveL, true);
	moveCube(array, moveU, true);
	moveCube(array, moveL, true);
	moveEntireCubeYReverse(array, arrayCenter, true);
	moveWhiteCornerTopRight(array);

}

void makeSecondLayer(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	while(countRightEdgeSL(array, arrayCenter) != EDGE_NUM )
	{
				
		int edgeTopPosition = findSLEdgeTop(array, arrayCenter, YELLOW_CHAR);
		
		if(edgeTopPosition != -1)	// edge on top
		{
			int edgeSideIndex = edgeIndex(array, arrayCenter, TOP, edgeTopPosition);
			
			moveSLTop(array, arrayCenter, edgeTopPosition, edgeSideIndex);
			
		}
		else
		{
			wrongSLEdgeMiddle(array, arrayCenter);
		
		}
		
		cout << endl;
		printCube(array, arrayCenter);
	
	}
	
	cout << "Second Layer Done!" << endl;
	
}

