#include "speedControl.h"
#include "traps.h"

extern startscreen state;
double timeTriggered;
double timeTriggeredChar;

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
			timeTriggeredChar = x + 0.091;
			moveCharacter(x);
		}
	}
	else
	{
		moveCharacter(x);
	}
}

void update_ballSpeed(int x, int y, double w)
{
	if(timeTriggered > w)
		return;
	timeTriggered = w + 0.250;
	cannonballR(x, y);
	cannonballL(x, y);
	cannonballU(x, y);
	cannonballD(x, y);
}