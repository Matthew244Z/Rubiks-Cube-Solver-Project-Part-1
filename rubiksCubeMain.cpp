#include <iostream>
#include <cstdlib>
#include <fstream>

#include "rubiksCubeMovements.hpp"

#include "rubiksCubeBases.hpp"
#include "rubiksCubeBases.cpp"

#include "rubiksCubeUsefulFunctions.hpp"
#include "rubiksCubeUsefulFunctions.cpp"

#include "rubiksCubeWhiteCross.hpp"
#include "rubiksCubeWhiteCross.cpp"

#include "rubiksCubeWhiteCorners.hpp"
#include "rubiksCubeWhiteCorners.cpp"

#include "rubiksCubeSecondLayer.hpp"
#include "rubiksCubeSecondLayer.cpp"

#include "rubiksCubeMakeYellowLayer.hpp"
#include "rubiksCubeMakeYellowLayer.cpp"

#include "rubiksCubeOrientYellowLayer.hpp"
#include "rubiksCubeOrientYellowLayer.cpp"

using namespace std; 

int main()
{
	ifstream finScramble("scramble.txt");
	ifstream finRubiksCube("rubiksCube.txt");

	if(!finScramble)
	{
		cout << "Scramble File Not Found!" << endl;
		return EXIT_FAILURE;	
	}
	
	if(!finRubiksCube)	
	{
		cout << "rubiksCube.txt not found!" << endl;
		return EXIT_FAILURE;	
	}
	
	// --------------------------------

	string cube[ROW][COLUMN];
	
	string cubeCenter[CENTER] = {YELLOW_CHAR, BLUE_CHAR, RED_CHAR, GREEN_CHAR, ORANGE_CHAR, WHITE_CHAR};

	buildArray(finRubiksCube, cube);
	
	// ------------------------------------
	
	cout << "Hello! This is a Rubik's Cube Solver!\n" << endl;
	
	cout << "Place blue side on your front and yellow side on top and apply this scramble:" << endl;	
	scramble(finScramble, cube);
	
	cout << "Your cube should be like this: (YELLOW - blue down | BLUE, RED, GREEN, ORANGE - white down | WHITE - green down)" << endl;

	printCube(cube, cubeCenter);
	
	// --------------
	
	cout << "Start Solving" << endl;

	makeWhiteCross(cube, cubeCenter);
			
	setWhiteCross(cube, cubeCenter);
	
	cout << "\nWhite Cross Oriented!" << endl;
	printCube(cube, cubeCenter);

	makeWhiteCorners(cube, cubeCenter);
	
	makeSecondLayer(cube, cubeCenter);
	
	makeYellowCross(cube, cubeCenter);
	
	makeYellowCorners(cube, cubeCenter);
		
	orientYellowCorners(cube, cubeCenter);
	
	orientYellowEdges(cube, cubeCenter);
	
	//-----------------------------------------------


	finScramble.close();
	finRubiksCube.close();
	
	system("PAUSE");
	return EXIT_SUCCESS;		
}



