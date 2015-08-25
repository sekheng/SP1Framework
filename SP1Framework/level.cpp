#include "levels.h"
#include "Converter.h"
#include "Framework\console.h"
#include "game.h"
#include "playerchar.h"

extern COORD charLocation;
extern Console console;
extern startscreen state;

void levelcheck(int a,string &level)
{
	switch (a)
	{
		case 1:level = "levels1.txt"; break;
		case 2:level = "levels2.txt"; break;
		case 3:level = "levels3.txt"; break;
		case 4:level = "levels4.txt"; break;
		case 5:level = "levels5.txt"; break;
		case 6:state = End; break;
	}
}
