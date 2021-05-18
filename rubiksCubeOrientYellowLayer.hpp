#ifndef RUBIKS_CUBE_ORIENT_YELLOW_LAYER
#define RUBIKS_CUBE_ORIENT_YELLOW_LAYER

#include "rubiksCubeBases.hpp"

// -------------------- Orient Yellow Corners

int findTwoRightCorners(string array[ROW][COLUMN]);

void moveCorners(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void orientYellowCorners(string array[ROW][COLUMN], string arrayCenter[CENTER]);

// -------------------- Orient Yellow Edges

int findOneRightEdge(string array[ROW][COLUMN]);

void moveYellowEdgesRight(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void moveYellowEdgesLeft(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void orientYellowEdges(string array[ROW][COLUMN], string arrayCenter[CENTER]);
	// make a better way to move the cube



#endif
