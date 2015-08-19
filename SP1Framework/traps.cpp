#include "traps.h"
COORD cannonballLocationR;
COORD cannonLocationR;
extern Console console;

void cannonR(int &i)
{
	COORD cannonballLocationR[20];
	COORD cannonLocationR[20];
	console.writeToBuffer(cannonLocationR[i], (char)67, 0x0C);
	console.writeToBuffer(cannonballLocationR[i], (char)79, 0x0C);
}
void cannonballR(int x)
{
	if(cannonballLocationR.X != (cannonLocationR.X + x) && g_timer.getElapsedTime() != - 1)
	{
		cannonballLocationR.X++;
	}
	else
	{
		cannonballLocationR.X-=x;
	}
}
void locationR(int x, int y)
{
	cannonballLocationR.X = x;
	cannonballLocationR.Y = y;
	cannonLocationR.X = x;
	cannonLocationR.Y = y;
}
