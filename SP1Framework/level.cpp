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
	//else if (a == 6)
	//{
	//	//run endgamescreen
	//}

	else if (a == 100)
	{
		level = "CustomLevelLegend.txt";
	}
>>>>>>> 8b0d1a3fa8d3d4c90f953f3acb390716979b3c59
	else if (a == 6)
	{
		state = End;
	}
}
