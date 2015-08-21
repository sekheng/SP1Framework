#include "game.h"
#include "traps.h"
#include "Framework\console.h"
#include "levels.h"
#include "Converter.h"
#include "title.h"
#include "Loadlevel.h"
#include "playerchar.h"

extern Console console;
extern const WORD colors[] =
{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};
extern COORD LvL;
extern COORD CusLvL;
extern int color;
extern int row;
extern int col;
extern size_t g_map[140][100];
extern string content;
extern int cno;
extern int mno;
extern int tempX;
extern int tempY;
extern string level;
extern int change;
extern int levelno;
extern int tempEndX;
extern int tempEndY;
extern int cuscol;
extern int cusrow;
extern size_t g_custommap[140][100];
extern int cuschange;

void loadlevel()
{
	tempX = 0;
	tempY = 0;
	tempEndX = 0;
	tempEndY = 0;
	cno = 0;
	mno = 0;
	col = 0;
	row = 1;
	levelcheck(levelno, level);
	ifstream inData;
	inData.open(level);
	string Data;

	while (!inData.eof())
	{
		col = 0;
		getline(inData, Data);
		for (unsigned int x = 0; x < Data.length(); x++)
		{
			if (Data[x] == 'E')
			{
				tempEndX = col;
				tempEndY = row;
			}
			tempX = col;
			tempY = row;
			change = Data[x];
			convert(change);
			g_map[row][col] = change;
			++col;
		}
		++row;
	}
	inData.close();
}

void reloadlevel()
{
	LvL.Y = 1;
	LvL.X = 0;
	// Set up sample colours, and output shadings
	for (int i = 1; i < row; ++i)
	{
		LvL.X = 0;
		for (int j = 0; j < col; ++j) {
			int write = g_map[i][j];
			convert2(write, content, color);
			console.writeToBuffer(LvL, content, colors[color]);
			LvL.X += 1;
		}
		LvL.Y += 1;
	}
}

void loadcustomlevel()
{
	cuscol = 0;
	cusrow = 1;
	ifstream incusData;
	incusData.open("CustomLevelLegend.txt");
	string cusData;

	while (!incusData.eof())
	{
		cuscol = 0;
		getline(incusData, cusData);
		for (unsigned int x = 0; x < cusData.length(); x++)
		{
			cuschange = cusData[x];
			g_custommap[cusrow][cuscol] = cuschange;
			++cuscol;
		}
		++cusrow;
	}
	incusData.close();


	
}

void reloadcustomlevel()
{
	ofstream outcusData;
	string cusoutData;
	CusLvL.Y = 1;
	CusLvL.X = 0;
	int i = 1;
	// Set up sample colours, and output shadings
	for (; i < cusrow; ++i)
	{
		CusLvL.X = 0;
		for (int j = 0; j < cuscol; ++j) {
			char cuswrite = g_custommap[i][j];
			console.writeToBuffer(CusLvL, cuswrite, 0x0F);
			CusLvL.X += 1;
		}
		CusLvL.Y += 1;
	}
	//convert display
}
<<<<<<< HEAD
=======

>>>>>>> 5fd080b69de20df5283bf2965a52d3db49fca82b
/*void loadcustomlevel()
{
	if (i == cusrow)
	{
		cout << i << endl;
		CusLvL.X = 0;
		cout << "hi";
		outcusData.open("CustomLevel.txt");
		cin >> cusoutData;
		outcusData << cusoutData << endl;
		outcusData.close();
	}
}*/
//void loadcustomlevel()
//{
//	if (i == cusrow)
//	{
//		cout << i << endl;
//		CusLvL.X = 0;
//		cout << "hi";
//		outcusData.open("CustomLevel.txt");
//		cin >> cusoutData;
//		outcusData << cusoutData << endl;
//		outcusData.close();
//	}
//}
