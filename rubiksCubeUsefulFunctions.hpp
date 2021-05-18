#ifndef RUBIKS_CUBE_USEFUL_FUNCTIONS
#define RUBIKS_CUBE_USEFUL_FUNCTIONS

#include "rubiksCubeBases.hpp"


void printCube(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void scramble(ifstream & fin, string array[ROW][COLUMN]);

// --------------------- Useful Functions

void findEdge(string array[ROW][COLUMN], string color, int & nSide, int & nPosition);
/*
	Find edge -> center index (nSide) and position index on the side (nPostion)
	return the first edge found, starting on TOP FRONT RIGHT BEHIND LEFT DOWN
*/

void findCorner(string array[ROW][COLUMN], string color, int & nSide, int & nPosition);
/*
	Find Corner: center index (nSide) and position index on the side (nPosition)
	return the first corner found, starting on TOP FRONT RIGHT BEHIND LEFT DOWN
*/

// findEdge and findCorner will check might check for all sides
// sideIndex has an especific side and position

int sideIndex(string array[ROW][COLUMN], string arrayCenter[CENTER], int initialSide, int positionIndex);
/*
	Receive the side index and position index of the piece(position relative to the side) ESPECIFIC POSITION
	Return the index of the side this piece must go
*/

void moveSideToFront(string array[ROW][COLUMN], string arrayCenter[CENTER], int colorToMove, bool print);
/*
	Move any side to the FRONT side and change the index of the other sides
*/

void cornerIndex(string array[ROW][COLUMN], string arrayCenter[CENTER], int nSide, int nPosition, int & colorTop, int & colorLeft);
/*
	Receive the side index and position index of a corner
	Return the other two colors of the corner (returns the index of the sides)
*/

int edgeIndex(string array[ROW][COLUMN], string arrayCenter[CENTER], int nSide, int nPosition);
/*
	Receive the side index and position index of an edge 
	Return the other color of the edge (return the index of the side)
*/


#endif

