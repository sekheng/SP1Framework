#include "playerchar.h"
//#include "traps.cpp"

extern COORD charLocation;
extern COORD cannonballLocationR[20];
extern Console console;
extern int cno;

void characterInteraction()
{
	for (int i = 0; i < cno; ++i)
	{
		if (charLocation.X == cannonballLocationR[i].X && charLocation.Y == cannonballLocationR[i].Y)
		{
			g_quitGame = true;
		}
	}
}