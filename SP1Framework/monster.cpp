//\@^@/ monster that go left and right
/*
(char)92<<(char)40<<(char)64<<(char)94<<(char)64<<(char)41<<(char)47
*/
#include "monster.h"
string sideMonR = "\@^@/";
int sideMon(int &x,int &y)
{
	string sideMonR = "\@^@/";
	gotoXY(x ,y);
	std::cout<<sideMonR;
	/*for(int i = 0; i <= 4 ; ++i)
	{
		gotoXY(x-=1  ,y);
		
		if( i == 4)
		{
			for(int i = 0; i <= 4 ; ++i)
			{
				gotoXY(x +=1  ,y);
				
			}
			i = 0;
		}
	}*/
	return 0;
}