#include <iostream>
#include <fstream>
#include <cstdlib>

#include "rubiksCubeOrientYellowLayer.hpp"

using namespace std;

int findTwoRightCorners(string array[ROW][COLUMN])
{
	int position = -1;
	bool repeat = true;
	
	for(int index = 0; index < EDGE_NUM; index++)
	{
		if(array[BEHIND][0] == array[BEHIND][2] && repeat)
		{
			position = index;
			repeat = false;	
		}
		
		moveCube(array, moveU, false);
		
	}
	
	return position;
	
}

void moveCorners(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	moveEntireCubeXReverse(array, arrayCenter, true);
	moveCubeReverse(array, moveR, true);
	moveCube(array, moveD, true);
	moveCubeReverse(array, moveR, true);
	moveCubeTwice(array, moveU, true);
	moveCube(array, moveR, true);
	moveCubeReverse(array, moveD, true);
	moveCubeReverse(array, moveR, true);
	moveCubeTwice(array, moveU, true);
	moveCubeTwice(array, moveR, true);
	moveEntireCubeXNormal(array, arrayCenter, true);
}

void orientYellowCorners(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int cornerPosition = findTwoRightCorners(array);
	
	if(cornerPosition == -1)
	{
		moveCorners(array, arrayCenter);
		cornerPosition = findTwoRightCorners(array);
	}
	
	while(cornerPosition > 0)
	{
		moveCube(array, moveU, true);	
		cornerPosition--;
	}
	
	if(array[FRONT][0] != array[FRONT][2])
	{
		moveCorners(array, arrayCenter);	
	}
	
	cout << "\nYellow Corners Oriented!" << endl;
	printCube(array, arrayCenter);
		

}

int findOneRightEdge(string array[ROW][COLUMN])
{
	int position = -1;
	bool repeat = true;
	
	for(int index = 0; index < EDGE_NUM; index++)
	{
		if(array[BEHIND][0] == array[BEHIND][1] && repeat)
		{
			position = index;
			repeat = false;
		}
		
		moveCube(array, moveU, false);
		
	}
	
	return position;
}

void moveYellowEdgesRight(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	moveCubeTwice(array, moveF, true);
	moveCubeReverse(array, moveU, true);
	moveMiddleReverse(array, arrayCenter, true);
	moveCubeTwice(array, moveU, true);
	moveMiddleNormal(array, arrayCenter, true);
	moveCubeReverse(array, moveU, true);
	moveCubeTwice(array, moveF, true);

}

void moveYellowEdgesLeft(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	moveCubeTwice(array, moveF, true);
	moveCube(array, moveU, true);
	moveMiddleReverse(array, arrayCenter, true);
	moveCubeTwice(array, moveU, true);
	moveMiddleNormal(array, arrayCenter, true);
	moveCube(array, moveU, true);
	moveCubeTwice(array, moveF, true);

}

void orientYellowEdges(string array[ROW][COLUMN], string arrayCenter[CENTER])
{
	int edgePosition = findOneRightEdge(array);
		
	if(edgePosition == -1)		// make sure I have one right edge 
	{
		moveYellowEdgesRight(array, arrayCenter);
		edgePosition = findOneRightEdge(array);	
	}
	
	while(edgePosition > 0)		// make sure the right edge is behind
	{
		moveCube(array, moveU, true);
		edgePosition--;
	}
	
	while(array[BEHIND][1] != arrayCenter[BEHIND])
	{
		moveEntireCubeYReverse(array, arrayCenter, true);
		moveCube(array, moveU, true);	
	}
	
	if(array[FRONT][1] != arrayCenter[FRONT])
	{
		if(array[FRONT][1] == arrayCenter[RIGHT])
		{
			moveYellowEdgesRight(array, arrayCenter);	
		}
		else if(array[FRONT][1] == arrayCenter[CENTER])
		{
			moveYellowEdgesLeft(array, arrayCenter);	
		}
	}
	
	cout << "\nYellow Edges Oriented!" << endl;
	printCube(array, arrayCenter);
}
