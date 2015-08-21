#include "Converter.h"
#include "levels.h"
#include "game.h"
#include "traps.h"
#include "playerchar.h"
#include "monster.h"

extern int tempX;
extern int tempY;
extern int tempEndX;
extern int tempEndY;
extern int cno;
extern int mno;
extern int bno;
char pass;
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
		characterEnd(tempEndX, tempEndY);
	}
	if (a == 35) // crate
	{
		a = 3;
	}
	if (a == 83)//start point 
	{
		a = 0;
		convertStart(tempY, tempX);
	}
	if (a == 82 || a == 85 || a == 68 || a == 76) //cannon
	{
		pass = a;
		convert(tempY, tempX,cno,pass);
		cno++;
	}
	if (a == 77) // monster
	{
		convert(tempY, tempX, mno);
		mno++;
	}
	if (a == 66) //box
	{
		convertbox(tempY, tempX, bno);
		bno++;
	}
	
}
//void convertbox(int &tempY, int &tempX, int bno)
//{
//	characterBox(tempX, tempY, bno);
//}
void convertStart(int &y, int &x)
{
	characterSpawn(x,y);
}
void convert(int &tempY, int &tempX, int mno)
{
	aiMonSpawn(tempX,tempY,mno);
}
void convert(int &y, int &x,int num,char pass) //for cannon
{
	switch (pass)
	{
		case 'R':locationR(x, y, num); break;
		case 'U':locationU(x, y, num); break;
		case 'L':locationL(x, y, num); break;
		case 'D':locationD(x, y, num); break;
	}
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