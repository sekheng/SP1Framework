//\@^@/ monster that go left and right
/*
*/
#include "monster.h"

int sideMon(int &x,int &y)
{
	for(int i = 0; i <= 5 ; ++i)
	{
		gotoXY(x -=1  ,y);
		std::cout<<(char)92<<(char)40<<(char)62<<(char)94<<(char)62<<(char)41<<(char)47;
		if( i == 5)
		{
			for(int i = 0; i <= 5 ; ++i)
			{
				gotoXY(x +=1  ,y);
				std::cout<<(char)92<<(char)40<<(char)62<<(char)94<<(char)62<<(char)41<<(char)47;
			}
			i = 5;
		}
	}
	return 0;
}