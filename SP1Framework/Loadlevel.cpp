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

void loadlevel()
{
	int levelno = 5;
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