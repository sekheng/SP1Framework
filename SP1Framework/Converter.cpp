#include "Converter.h"
#include "levels.h"
#include "game.h"
#include "traps.h"
void convert(int &a)
{
	
	const WORD colors[] =
	{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};
	if (a == 49) //white walls
	{
		a = 1;
	}
	if (a == 48) // empty space
	{
		a = 0;
	}
	if (a == 69) //end point
	{
		a = 2;
	}
	if (a == 35) // crate
	{
		a = 3;
	}
	if (a == 83)//start point 
	{
		a = 4;
	}
	
}
void convert(int &y, int &x,int num)
{
	locationR(x,y,num);
}

void convert2(int&b, string &x, int &c)
{
	if (b == 0) {
		x = " ";
		c = 0;
	}
	if (b == 1){
		x = " ";
		c = 5;
	}
	if (b == 2) {
		x = "E";
		c = 0;
	}
	if (b == 3) {
		x = "#";
		c = 0;
	}
	if (b == 4) {
		x = "S";
		c = 0;
	}
	
}