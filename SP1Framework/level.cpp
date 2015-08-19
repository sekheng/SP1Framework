#include "levels.h"
#include "Converter.h"
#include "Framework\console.h"

extern Console console;

void level(int &a)
{
	/*ifstream indata;
	string data;
	string levelno;
	int change;
	if (a == 1)
	{
		levelno = "levels1.txt";
	}
	else if (a == 2)
	{
		levelno = "levels2.txt";
	}
	else if (a == 3)
	{
		levelno = "levels3.txt";
	}
	else if (a == 4)
	{
		levelno = "levels4.txt";
	}
	else if (a == 5)
	{
		levelno = "levels5.txt";
	}
	indata.open(levelno);
	while (!indata.eof())
	{
		getline(indata, data);
		for (unsigned int x = 0; x < data.length(); x++)
		{
			change = data[x];
			convert(change);
		}
		cout << endl;
	}
	indata.close();
*/
	const WORD colors[] =
	{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	string level;

	int change;
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
	ifstream inData;
	inData.open(level);
	string Data;
	COORD Ttle;
	Ttle.X = 0;
	Ttle.Y = 1;
	int row = 1;    // For collision Detection
	int col = 0;    // For collision Detection

	while (!inData.eof())
	{
		col = 0;
		Ttle.X = 0;
		getline(inData, Data);
		for (unsigned int x = 0; x < Data.length(); x++)
		{
			change = Data[x];

			//if (change == 49) {   // For the collision detection
			//	g_map[row][col] = 1;
			//}
			//else {
			//	g_map[row][col] = 0;
			//}

			if (change == 49) {
				convert(change);
				console.writeToBuffer(Ttle, change, colors[5]);
				Ttle.X += 1;
				++col;
				continue;
			}
			convert(change);
			console.writeToBuffer(Ttle, change, colors[0]);
			Ttle.X += 1;
			++col;
		}
		++row;
		Ttle.Y += 1;
	}
	inData.close();


}