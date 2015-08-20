#include "Converter.h"
#include "levels.h"
#include "game.h"
#include "traps.h"
extern int tempX;
extern int tempY;
extern int cno;
void convert(int &a)
{
	
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
	if (a == 67) //cannon
	{
		convert(tempY, tempX, cno);
		cno++;
	}
	
}

void convert(int &y, int &x,int num) //for cannon
{
	locationR(x,y,num);
}

void convert2(int&b, string &x, int &c)
{
	if (b == 0) { //wall
		x = " ";
		c = 0;
	}
	if (b == 1){//empty space
		x = " ";
		c = 5;
	}
	if (b == 2) {//end point
		x = "E";
		c = 0;
	}
	if (b == 3) {//crates/box
		x = "#";
		c = 0;
	}
	if (b == 4) {//starting point
		x = "S";
		c = 0;
	}
	
}