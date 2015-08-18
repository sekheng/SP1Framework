#include "Converter.h"
#include "levels.h"
#include "game.h"

void convert(int &a)
{
	const WORD colors[] =
	{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};
	if (a == 49) //white walls
	{
		a = ' ';
	}
	if (a == 48) // empty space
	{
		a = ' ';
	}
	if (a == 69) //end point
	{
		a = 'E';
	}
	if (a == 35) // crate
	{
		a = '#';
	}
}