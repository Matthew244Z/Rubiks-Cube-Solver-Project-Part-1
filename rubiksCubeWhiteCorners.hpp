#ifndef RUBIKS_CUBE_WHITE_CORNERS
#define RUBIKS_CUBE_WHITE_CORNERS

#include "rubiksCubeBases.hpp"

int countRightWhiteCorners(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void moveWhiteCornerTopLeft(string array[ROW][COLUMN]);

void moveWhiteCornerTopRight(string array[ROW][COLUMN]);

void moveWhiteCornerTopSide(string array[ROW][COLUMN], string arrayCenter[CENTER], int centerIndex, int whiteIndex);

void moveWhiteCornerTopTop(string array[ROW][COLUMN], string arrayCenter[CENTER], int whiteIndex);

void moveWhiteCornerBotSide(string array[ROW][COLUMN], string arrayCenter[CENTER], int centerIndex, int whiteIndex);

int findWrongWhiteCornerBot(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void moveWhiteCornerBotBot(string array[ROW][COLUMN],string arrayCenter[CENTER], int turnSide);





#endif
