#include "levels.h"
#include "Converter.h"
void level(int &a)
{
	if (a == 1)
	{
		const int collumn = 4;

		string levelno[collumn]=
		{
			"1111111111111111111111111111111111111111",
			"1100000000000000000000000000000000000011",
			"1100000000000000000000000000000000000011",
			"1111111111111111111111111111111111111111"
		};
		for (int x = 0; x < 4; x++)
		{
			for (unsigned int i = 0; i < 40; i++)
			{
				//cout << levelno[x][i];
				int change = levelno[x][i];
				convert(change);
			}
			cout << endl;
		}
		//cout << levelno[0][1];
		//convert(levelno[collumn][row], collumn);
		
	}
	//else if (a == 2)
	//{

	//}
	//else if (a == 3)
	//{

	//}
	//else if (a == 4)
	//{

	//}
	//else if (a == 5)
	//{

	//}

}