#include "traps.h"
extern Console console;

void cannonR()
{
	console.writeToBuffer(cannonLocationR, (char)67, 0x0C);
	console.writeToBuffer(cannonballLocationR, (char)79, 0x0C);
}
void cannonball(int x)
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
