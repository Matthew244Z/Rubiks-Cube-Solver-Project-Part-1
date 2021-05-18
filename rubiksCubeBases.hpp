#ifndef RUBIKS_CUBE_BASES
#define RUBIKS_CUBE_BASES

#include "rubiksCubeMovements.hpp"

const int ROW = 6;
const int COLUMN = 8;
const int FOUR_SIDES = 12;
const int ONE_SIDE = 8;
const int CENTER = 6;

const int TOP = 0;
const int FRONT = 1;
const int RIGHT = 2;
const int BEHIND = 3;
const int LEFT = 4;
const int BOTTOM = 5;

const string YELLOW_CHAR = "Y";
const string BLUE_CHAR = "B";
const string RED_CHAR = "R";
const string GREEN_CHAR = "G";
const string ORANGE_CHAR = "O";
const string WHITE_CHAR = "W";

const int EDGE_NUM = 4;

Movement moveU(0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 1, 2, 3, 4, 0, "U");
Movement moveD(4, 5, 6, 4, 5, 6, 4, 5, 6, 4, 5, 6, 1, 4, 3, 2, 5, "D");
Movement moveR(2, 3, 4, 2, 3, 4, 2, 3, 4, 6, 7, 0, 0, 1, 5, 3, 2, "R");	
Movement moveL(6, 7, 0, 2, 3, 4, 6, 7, 0, 6, 7, 0, 0, 3, 5, 1, 4, "L");
Movement moveF(4, 5, 6, 2, 3, 4, 0, 1, 2, 6, 7, 0, 0, 4, 5, 2, 1, "F");
Movement moveB(0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 0, 0, 2, 5, 4, 3, "B");

// -------------------- Array Functions

void buildArray(ifstream & fin, string array[ROW][COLUMN]);

void printArray(string array[ROW][COLUMN]);

// --------------------	Move one layer

void moveLayer(string array[ROW][COLUMN], Movement const & moveX);

void moveSide(string array[ROW][COLUMN], Movement const & moveX);

void moveCube(string array[ROW][COLUMN], Movement const & moveX, bool print);

void moveCubeTwice(string array[ROW][COLUMN], Movement const & moveX, bool print);

void moveCubeReverse(string array[ROW][COLUMN], Movement const & moveX, bool print);

// --------------------- Move Entire Cube Y

void moveEntireCubeY(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void moveEntireCubeYNormal(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print);

void moveEntireCubeYReverse(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print);

void moveEntireCubeYTwice(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print);

// ---------------------- Move Entire Cube X

void moveEntireCubeX(string array[ROW][COLUMN], string arrayCenter[CENTER]);

void moveEntireCubeXNormal(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print);

void moveEntireCubeXReverse(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print);

// --------------------- Move Middle Layer

void moveMiddleNormal(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print);

void moveMiddleReverse(string array[ROW][COLUMN], string arrayCenter[CENTER], bool print);

#endif


