#include "Converter.h"
#include "levels.h"

void convert(int &a)
{
	if (a == 49)
	{
		colour(0xF6);
		cout << ' ';
	}
	if (a == 48)
	{
		colour(0x0F);
		cout << ' ';
	}
	if (a == 69)
	{
		cout << "E";
	}
	if (a == 35)
	{
		cout << "#";
	}


	/*if (hit end point)
	
	{
		level++
		level(level)
	}*/

}