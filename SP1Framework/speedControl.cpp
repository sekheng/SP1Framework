#include "speedControl.h"
#include "traps.h"
#include "monster.h"

extern startscreen state;
double timeTriggered;
double timeTriggeredChar;
double timeTriggeredCrazy;
double timeTriggeredFollow;

void update_charSpeed(double x)
{
	if( state == Start)
	{
		if(timeTriggeredChar > x)
		{
			return;
		}
		else
		{
			timeTriggeredChar = x + 0.075;
			moveCharacter(x);
		}
	}
	else
	{
		moveCharacter(x);
	}
}

void update_ballSpeed(int x, int y, int a, int b, int c, int d, double w)
{
	if(timeTriggered > w)
		return;
	timeTriggered = w + 0.250;
	cannonballR(x, y, d);
	cannonballL(x, a, d);
	cannonballU(x, b, d);
	cannonballD(x, c, d);
}

void update_crazyMonSpeed(int z,int y, double w)
{
	if(timeTriggeredCrazy > w)
		return;
	timeTriggeredCrazy = w + 0.150;
	crazyMonUpdate(z,y);
}

void update_followMonSpeed(int z,int y, double w)
{
	if(timeTriggeredFollow > w)
		return;
	timeTriggeredFollow = w + 0.175;
	followMonUpdate(z,y,timeTriggeredFollow);
}