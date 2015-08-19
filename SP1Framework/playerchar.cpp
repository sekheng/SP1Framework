#include "playerchar.h"

void characterInteraction(void)
{
	if (charLocation.X && charLocation.Y == cannonballLocationR.X && cannonballLocationR.Y)
	{
		g_quitGame = true;
	}
}