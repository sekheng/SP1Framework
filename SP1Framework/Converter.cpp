#include "Converter.h"
#include "levels.h"

void convert(int &a)
{
	if (a == 49) //white walls
	{
		colour(0xF6);
        char spce = ' ';
        wall(spce);
		cout << spce;
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

char wall( char & charact)
{
    return charact;
}