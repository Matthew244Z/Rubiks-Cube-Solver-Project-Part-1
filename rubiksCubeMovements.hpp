#ifndef RUBIKS_CUBE_MOVEMENTS
#define RUBIKS_CUBE_MOVEMENTS

#include <cstdlib>
#include <iostream>

using namespace std;

class Movement
{
	private:
		int sA0, sA1, sA2, sB0, sB1, sB2, sC0, sC1, sC2, sC3, sD0, sD1, sD2; // new
		int sideA, sideB, sideC, sideD;
		int side;
		string moveSide;
		
	public:
		Movement()
		{
			sA0 = sA1 = sA2 = sB0 = sB1 = sB2 = sC0 = sC1 = sC2 = sC3 = sD0 = sD1 = sD2 = 0;
			sideA = 0;
			sideB = 1;
			sideC = 2;
			sideD = 3;
			side = 0;
			moveSide = "none";
		}
		
		Movement(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10, int i11,
			int sA, int sB, int sC, int sD, int newSide, string sideToMove)
		{ 
			sA0 = i0; 	// old = initial
			sA1 = i1;
			sA2 = i2;
			sB0 = i3;
			sB1 = i4;
			sB2 = i5;
			sC0 = i6;
			sC1 = i7;
			sC2 = i8;
			sD0 = i9;
			sD1 = i10;
			sD2 = i11;
			sideA = sA;
			sideB = sB;
			sideC = sC;
			sideD = sD;
			side = newSide;
			moveSide = sideToMove;
		}
		
		int get_sideA() const
		{
			return sideA;	
		}
		
		int get_sideB() const
		{
			return sideB;	
		}
		
		int get_sideC() const
		{
			return sideC;	
		}
		
		int get_sideD() const
		{
			return sideD;	
		}
		
		int get_sA0() const
		{
			return sA0;	
		}
		
		int get_sA1() const
		{
			return sA1;	
		}
		
		int get_sA2() const
		{
			return sA2;	
		}
		
		int get_sB0() const
		{
			return sB0;	
		}
		
		int get_sB1() const
		{
			return sB1;	
		}
		
		int get_sB2() const
		{
			return sB2;	
		}
		
		int get_sC0() const
		{
			return sC0;	
		}
		
		int get_sC1() const
		{
			return sC1;	
		}
		
		int get_sC2() const
		{
			return sC2;	
		}
		
		int get_sD0() const
		{
			return sD0;	
		}
		
		int get_sD1() const
		{
			return sD1;	
		}
		
		int get_sD2() const
		{
			return sD2;	
		}
		
		int get_side() const
		{
			return side;	
		}
		
		void print_side() const
		{
			cout << moveSide;	
		}
	
};

#endif

