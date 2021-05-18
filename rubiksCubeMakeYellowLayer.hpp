#ifndef RUBIKS_CUBE_MAKE_YELLOW_LAYER
#define RUBIKS_CUBE_MAKE_YELLOW_LAYER

#include "rubiksCubeBases.hpp"

int countYellowEdges(string array[ROW][COLUMN]);

void moveYellowCross(string array[ROW][COLUMN]);

void moveYellowCrossTwoEdges(string array[ROW][COLUMN]);

void makeYellowCross(string array[ROW][COLUMN], string arrayCenter[CENTER]);

// ------------------

int countYellowCorners(string array[ROW][COLUMN]);

void moveYellowCorners(string array[ROW][COLUMN]);

void moveYellowCornersReverse(string array[ROW][COLUMN]);

void oneYellowCorner(string array[ROW][COLUMN]);

void noYellowCorners(string array[ROW][COLUMN]);

void twoYellowCorners(string array[ROW][COLUMN]);

void makeYellowCorners(string array[ROW][COLUMN], string arrayCenter[CENTER]);






#endif

