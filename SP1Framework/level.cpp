#include "levels.h"
#include "Converter.h"
#include "Framework\console.h"
#include "game.h"
extern Console console;

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

}