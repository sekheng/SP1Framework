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
extern COORD charCustomLocation;
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
extern size_t g_customizemap[140][100];
extern int cuschange;

COORD display_level_text;
char leveltext_arr[200][100];
COORD purelystatic_level_text;
int leveltext_row = 0;
int leveltext_col = 0;

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
	string cusoutData;
	CusLvL.Y = 18;
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
	
}

void writelevel(char &a)
{
	g_customizemap[charCustomLocation.X][charCustomLocation.Y] = a;
}
void renderwrittenlevel()
{
	COORD levellocation;
	levellocation.Y = 0;
	levellocation.X = 0;
	for (int i = 0; i < 17;i++)
	{
		levellocation.X = 0;
		for (int j = 0; j < 100;j++)
		{
			char cuswrite = g_customizemap[j][i];
			if (cuswrite == '\0')
			{
				cuswrite = '0';
			}
			console.writeToBuffer(levellocation, cuswrite, 0x0F);
			levellocation.X += 1;
		}
		levellocation.Y += 1;
	}
}
void savecustomlevel()
{
	ofstream outData;
	string Data;
	outData.open("CustomLevel.txt");
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 140; j++)
		{
			char cuswrite = g_customizemap[j][i];
			outData << cuswrite;
		}
		outData << endl;
	}
	outData.close();
}
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
//}+

void initLevelText()
{
    ifstream instatic_level_text;
    instatic_level_text.open("Level_Text.txt");
    string purelystatic_Text;
    while ( getline (instatic_level_text, purelystatic_Text) && !instatic_level_text.eof() )
    {
        leveltext_col = 0;
        for ( size_t y = 0; y < purelystatic_Text.size(); ++y) {
            leveltext_arr[leveltext_row][leveltext_col] = purelystatic_Text[y];
            ++leveltext_col;
        }
        ++leveltext_row;
    }
    instatic_level_text.close();
    purelystatic_level_text.X = 60;
    purelystatic_level_text.Y = 1;
}

void displayleveltext() 
{
    display_level_text.X = 108;
    display_level_text.Y = 1;
    purelystatic_level_text.Y = 1;
    string level_text;
    for ( int i = 0 ; i  < leveltext_row; ++i)
    {
        purelystatic_level_text.X = 60;
        for ( int j = 0; j < leveltext_col; ++j)
        {
            console.writeToBuffer( purelystatic_level_text, leveltext_arr[i][j], 0x0F);
            purelystatic_level_text.X += 1;
        }
        purelystatic_level_text.Y += 1;
    }

    switch (levelno)
    {
    case 1: level_text = "level1_text.txt"; 
        break;
    case 2: level_text = "level2_text.txt";
        break;
    case 3: level_text = "level3_text.txt";
        break;
    case 4: level_text = "level4_text.txt";
        break;
    case 5: level_text = "level5_text.txt";
        break;
    }
    ifstream inlevelText;
    inlevelText.open(level_text);
    string display_LevelText;
    while ( !inlevelText.eof() && getline(inlevelText, display_LevelText) )
    {
        console.writeToBuffer(display_level_text, display_LevelText, 0x0F);
        display_level_text.Y += 1;
    }
    inlevelText.close();
}