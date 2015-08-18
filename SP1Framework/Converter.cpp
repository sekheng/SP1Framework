#include "Converter.h"
#include "levels.h"

void convert(int &a)
{
	if (a == 49) //white walls
	{
        collision(a);
		colour(0xF6);
		cout << ' ';
	}
	if (a == 48) // empty space
	{
		colour(0x0F);
		cout << ' ';
	}
	if (a == 69) //end point
	{
		colour(0x0F);
		cout << "E";
	}
	if (a == 35) // crate
	{
		colour(0x0F);
		cout << "#";
	}



	/*if (hit end point)
	
	{
		level++
		level(level)
	}*/

}