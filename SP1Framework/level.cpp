#include "levels.h"
#include "Converter.h"
#include "Framework\console.h"


void level(int &a)
{
	ifstream indata;
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


}