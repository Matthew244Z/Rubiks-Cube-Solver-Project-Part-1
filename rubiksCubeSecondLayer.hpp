#ifndef RUBIKS_CUBE_SECOND_LAYER
#define RUBIKS_CUBE_SECOND_LAYER

#include "rubiksCubeBases.hpp"

int countRightEdgeSL(string array[ROW][COLUMN], string arrayCenter[CENTER]);

int findSLEdgeTop(string array[ROW][COLUMN], string arrayCenter[CENTER], string color);

void moveSLTopLeft(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void moveSLTopRight(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void moveSLTop(string array[ROW][COLUMN], string arrayCenter[CENTER], int positionEdgeTop, int nEdgeSide);

void wrongSLEdgeMiddle(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void makeSecondLayer(string array[ROW][COLUMN], string arrayCenter[CENTER]);

#endif
