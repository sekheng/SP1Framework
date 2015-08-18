////}~{ electric trap
////[] pit trap
//#include "traps.h"
//COORD cannonballLocationR;
//COORD cannonLocationR;
//COORD cannonballLocationL;
//COORD cannonLocationL;
//COORD cannonballLocationU;
//COORD cannonLocationU;
//COORD cannonballLocationD;
//COORD cannonLocationD;
//
//void cannonR()//for render//shoots towards right
//{
//	gotoXY(cannonLocationR);
//	std::cout << (char)67;
//	gotoXY(cannonballLocationR);
//    colour(0x0C);
//    std::cout << (char)79;
//}
//void cannonRupdateR(int x)//update
//{
//		if (cannonballLocationR.X != x && g_timer.getElapsedTime() != -1)
//	{
//		cannonballLocationR.X++;
//	}
//	else
//	{
//		cannonballLocationR.X-=x;
//	}
//}
//void cannonLocationOnmapR(int x, int y)//init
//{
//	cannonballLocationR.X = x;
//	cannonballLocationR.Y= y;
//
//	cannonLocationR.X = cannonballLocationR.X;
//	cannonLocationR.Y = cannonballLocationR.Y;
//}
//
//
//
//void cannonL()//for render//shoots towards left
//{
//	gotoXY(cannonLocationL);
//	std::cout << (char)67;
//	gotoXY(cannonballLocationL);
//    colour(0x0C);
//    std::cout << (char)79;
//}
//void cannonRupdateL(int x)//update
//{
//		if (cannonballLocationL.X != x && g_timer.getElapsedTime() != -1)
//	{
//		cannonballLocationL.X--;
//	}
//	else
//	{
//		cannonballLocationL.X+=x;
//	}
//}
//void cannonLocationOnmapL(int x, int y)//init
//{
//	cannonballLocationL.X = x;
//	cannonballLocationL.Y= y;
//
//	cannonLocationL.X = cannonballLocationL.X;
//	cannonLocationL.Y = cannonballLocationL.Y;
//}
//
//
//void cannonU()//for render//shoots towards up
//{
//	gotoXY(cannonLocationU);
//	std::cout << (char)67;
//	gotoXY(cannonballLocationU);
//    colour(0x0C);
//    std::cout << (char)79;
//}
//void cannonRupdateU(int x)//update
//{
//		if (cannonballLocationU.Y != x && g_timer.getElapsedTime() != -1)
//	{
//		cannonballLocationU.Y++;
//	}
//	else
//	{
//		cannonballLocationU.Y-=x;
//	}
//}
//void cannonLocationOnmapU(int x, int y)//init
//{
//	cannonballLocationU.X = x;
//	cannonballLocationU.Y= y;
//
//	cannonLocationU.X = cannonballLocationU.X;
//	cannonLocationU.Y = cannonballLocationU.Y;
//}
//
//
//void cannonD()//for render//shoots towards down
//{
//	gotoXY(cannonLocationU);
//	std::cout << (char)67;
//	gotoXY(cannonballLocationU);
//    colour(0x0C);
//    std::cout << (char)79;
//}
//void cannonRupdateD(int x)//update
//{
//	if (cannonballLocationD.Y != x && g_timer.getElapsedTime() != -1)
//	{
//		cannonballLocationD.Y--;
//	}
//	else
//	{
//		cannonballLocationD.Y+=x;
//	}
//}
//void cannonLocationOnmapD(int x, int y)//init
//{
//	cannonballLocationD.X = x;
//	cannonballLocationD.Y= y;
//
//	cannonLocationD.X = cannonballLocationD.X;
//	cannonLocationD.Y = cannonballLocationD.Y;
//}