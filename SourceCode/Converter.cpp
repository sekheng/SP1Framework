#include "Converter.h"
#include "levels.h"
#include "game.h"
#include "traps.h"
#include "playerchar.h"
#include "monster.h"
#include "item.h"
#include "pressureplate.h"

extern int tempEndX;
extern int tempEndY;
extern int cnoR;
extern int cnoL;
extern int cnoU;
extern int cnoD;
extern int mno;
extern int bno;
extern int sno;
extern int pno;
extern int hno;
int check_no_of_keys = 0;
int check_no_of_gates = 0;
char pass;
void convert(int &a);

void convert(int &a, int b, int c)
{
	if (a == 49) //white walls '1'
	{
		a = 1;
	}
	if (a == 48) // empty space '0'
	{
		a = 0;
	}
	if (a == 69) //end point 'E'
	{
		a = 2;
		characterEnd(tempEndX, tempEndY);
		//characterEnd(b,c);
	}
	if (a == 83)//start point 'S'
	{
		a = 4;
		characterSpawn(b,c);
	}
	if (a == 82 || a == 85 || a == 68 || a == 76) //cannon
	{
		switch (a)
		{
			case 'R':locationR(b, c, cnoR);  cnoR++; break;
			case 'U':locationU(b, c, cnoU);  cnoU++; break;
			case 'L':locationL(b, c, cnoL);  cnoL++; break;
			case 'D':locationD(b, c, cnoD);  cnoD++; break;
		}
	}
	if (a == 77) // monster 'M'
	{
		crazyMonSpawn(b,c,mno);
		mno++;
		a = 0;
	}
	if (a == 35) //box '#'
	{
		setBlock(b, c, bno);
		bno++;
		a = 0;
	}
    if ( a == 'K'|| a == 'Q')
    {
		int y;
        switch (a)
        {
			case 'K':  y = 0; break;
			case 'Q':  y = 1; break;
        }
		populate_keyArr(y);
		keys_locations(c, b, y);
        ++check_no_of_keys;
		a = 0;
    }
	if ( a == 'G'|| a == 'B')
    {
		int x;
        switch (a)
        {
            case 'G': x = 0 ; break;
            case 'B': x = 1; break;
        }        
        populate_gateArr(x);
		gate_location(c, b, x);
        ++check_no_of_gates;
    }
	if (a == 'N')
	{
		followMonSpawn(b, c, sno);
		sno++;
		a = 0;
	}
	if (a == 'P')
	{
		setPlate(b, c, pno);
		pno++;
	}
	if (a == 'H')
	{
		a = 0;
		setHatch(b, c, hno);
		hno++;
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
	if (b == 4) { //starting point
		x = "S";
		c = 0;
	}
}