//}~{ electric trap
//[] pit trap
#include "traps.h"
COORD cannonballLocation;
COORD cannonLocation;

void cannonR()//for render
{
	gotoXY(cannonLocation);
	std::cout << (char)68;
	gotoXY(cannonballLocation);
    colour(0x0C);
    std::cout << (char)79;
}
void cannonRupdate(int x)//update
{
		if (cannonballLocation.X != x && g_timer.getElapsedTime() != -1)
	{
		cannonballLocation.X++;
	}
	else
	{
		cannonballLocation.X-=10;
	}
}
void cannonLocationOnmap(int x, int y)//init
{
	cannonballLocation.X = x;
	cannonballLocation.Y= y;

	cannonLocation.X = cannonballLocation.X;
	cannonLocation.Y = cannonballLocation.Y;
}