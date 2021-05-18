#ifndef RUBIKS_CUBE_WHITE_CROSS
#define RUBIKS_CUBE_WHITE_CROSS

#include "rubiksCubeBases.hpp"

int countWhiteCross(string array[ROW][COLUMN]);

bool isWhiteCrossDone(string array[ROW][COLUMN]);

void spaceOnWhite(string array[ROW][COLUMN], int position);

void whiteEdgeOnYellow(string array[ROW][COLUMN], int nWhite);

void whiteEdgeOnSides(string array[ROW][COLUMN], string arrayCenter[CENTER], int sideIndex, int nWhite);

void makeWhiteCross(string array[ROW][COLUMN], string arrayCenter[CENTER]);

// --------------- 

int countRightWhiteEdges(string array[ROW][COLUMN], string arrayCenter[CENTER]);

int whiteEdgeColor(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void setTwoWhiteCross(string array[ROW][COLUMN], string arrayCenter[CENTER], int centerColor);

void setWhiteCross(string array[ROW][COLUMN], string arrayCenter[CENTER]);

#endif 
