#include "levels.h"
#include "Converter.h"
#include "Framework\console.h"
#include "game.h"
#include "playerchar.h"
extern COORD charLocation;
extern Console console;
extern startscreen state;

void levelcheck(int &a,string &level)
{

	if (a == 1)
	{
		level = "levels1.txt";
	}
	else if (a == 2)
	{
		level = "levels2.txt";
	}
	else if (a == 3)
	{
		level = "levels3.txt";
	}
	else if (a == 4)
	{
		level = "levels4.txt";
	}
	else if (a == 5)
	{
		level = "levels5.txt";
	}
<<<<<<< HEAD
=======
	else if (a == 100)
	{
		level = "CustomLevelLegend.txt";
    }

	else if (a == 100)
	{
		level = "CustomLevelLegend.txt";
	}
>>>>>>> 5fd080b69de20df5283bf2965a52d3db49fca82b
	else if (a == 6)
	{
		state = End;
	}
}
