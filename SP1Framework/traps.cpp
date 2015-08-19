#include "traps.h"

extern Console console;
COORD cannonballLocationR[20];
COORD cannonLocationR[20];
void cannonR(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(cannonLocationR[b], (char)67, 0x0C);
		console.writeToBuffer(cannonballLocationR[b], (char)79, 0x0C);
	}
}
void cannonballR(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (cannonballLocationR[no].X != (cannonLocationR[no].X + x) && g_timer.getElapsedTime() != -1)
		{
			cannonballLocationR[no].X++;
		}
		else
		{
			cannonballLocationR[no].X -= x;
		}
	}

}
void locationR(int x, int y,int z)
{
	cannonballLocationR[z].X = x;
	cannonballLocationR[z].Y = y;
	cannonLocationR[z].X = x;
	cannonLocationR[z].Y = y;
}
