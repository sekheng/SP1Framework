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
extern string content;
extern int cnoR;
extern int cnoU;
extern int cnoD;
extern int cnoL;
extern int mno;
extern int bno;
extern int sno;
extern int pno;
extern int hno;
extern int change;
extern int levelno;
extern int tempEndX;
extern int tempEndY;
extern int cuscol;
extern int cusrow;
extern size_t g_map[200][200];
extern size_t g_custommap[200][200];
extern size_t g_customizemap[200][200];
extern int cuschange;

COORD display_level_text;
char leveltext_arr[200][100];
COORD purelystatic_level_text;
int leveltext_row = 0;
int leveltext_col = 0;
char *dynamic_lvlnum_text[7];
//loads the level 

void loadlevel(string &level)
{
	tempEndX = 0;
	tempEndY = 0;
	cnoR = 0;
	cnoL = 0;
	cnoD = 0;
	cnoU = 0;
	mno = 0;
	bno = 0;
	sno = 0;
	pno = 0;
	hno = 0;
    restart_level_forKeysAndGates();
    restart_keys_and_gates();
	col = 40;
	row = 1;
	ifstream inData;
	inData.open(level);
	string Data;

	while (!inData.eof())
	{
		col = 40;
		getline(inData, Data);
		for (unsigned int x = 0; x < Data.length(); x++)
		{
			if (Data[x] == 'E')
			{
				tempEndX = col;
				tempEndY = row;
			}
			change = Data[x];
			convert(change,col,row);
			g_map[row][col] = change;
			++col;
		}
		++row;
	}
	inData.close();
}
//refreshes the updates for main level
void reloadlevel()
{
	LvL.Y = 1;
	LvL.X = 40;
	for (int i = 1; i < row; ++i)
	{
		LvL.X = 40;
		for (int j = 40; j < col; ++j) {
			int write = g_map[i][j];
			convert2(write, content, color);
			console.writeToBuffer(LvL, content, colors[color]);
			LvL.X += 1;
		}
		LvL.Y += 1;
	}
}

//reading custom legend

void loadcustomlevel()
{
	cuscol = 20;
	cusrow = 1;
	ifstream incusData;
	incusData.open("CustomLevelLegend.txt");
	string cusData;
	while (!incusData.eof())
	{
		cuscol = 20;
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

//print out the whole thing

void reloadcustomlevel()
{
	string cusoutData;
	CusLvL.Y = 16;
	CusLvL.X = 20;
	int i = 0;
	for (; i < cusrow; ++i)
	{
		CusLvL.X = 20;
		for (int j = 0; j < cuscol; ++j) {
			char cuswrite = g_custommap[i][j];
			console.writeToBuffer(CusLvL, cuswrite, 0x0F);
			CusLvL.X += 1;
		}
		CusLvL.Y += 1;
	}
	
}

//custom level
//records custom level

void writelevel(char &a)
{
	g_customizemap[charCustomLocation.X][charCustomLocation.Y] = a;
}

//display what you typed onto the customize level

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
			console.writeToBuffer(levellocation, cuswrite, 0x0F);
			levellocation.X += 1;
		}
		levellocation.Y += 1;
	}
}

//save custom level

void savecustomlevel()
{
	ofstream outData;
	string Data;
	outData.open("CustomLevel.txt");
	for (int i = 1; i < 17; i++)
	{
		for (int j = 40; j < 96; ++j)
		{
			char cuswrite = g_customizemap[j][i];
			outData << cuswrite;
		}
		if (i != 16)
		{
			outData << endl;
		}
	}
	outData.close();
}

//loads custom level

void loadcustomizedlevel()
{
	string level = "customlevel.txt";
	loadlevel(level);
}

//refreshes custom level

void reloadcustomizedlevel()
{
	reloadlevel();
}

void initLevelText()
{
    ifstream instatic_level_text;
    instatic_level_text.open("Level_Text.txt");
    string purelystatic_Text;
    leveltext_row = 0;
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
    purelystatic_level_text.X = 0;
    purelystatic_level_text.Y = 1;

    string level_text;
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
    int t = 0;
    int col_for_lvltext = 13;
    while ( !inlevelText.eof() && getline(inlevelText, display_LevelText) )
    {
        dynamic_lvlnum_text[t] = new char[col_for_lvltext];
        for ( size_t i = 0; i < display_LevelText.size(); ++i)
        {
            *(dynamic_lvlnum_text[t] +i) = display_LevelText[i];
        }
        *(dynamic_lvlnum_text[t] + display_LevelText.size() ) = '\0';
        ++t;
    }
    inlevelText.close();
    display_level_text.X = 8;
    display_level_text.Y = 8;
}

void displayleveltext() 
{
    purelystatic_level_text.Y = 1;
    for ( int i = 0 ; i  < leveltext_row; ++i)
    {
        purelystatic_level_text.X = 0;
        for ( int j = 0; j < leveltext_col; ++j)
        {
            console.writeToBuffer( purelystatic_level_text, leveltext_arr[i][j], 0x0F);
            purelystatic_level_text.X += 1;
        }
        purelystatic_level_text.Y += 1;
    }

    display_level_text.Y = 8;
    for ( int i = 0; i < 7; ++i)
    {
        console.writeToBuffer(display_level_text, dynamic_lvlnum_text[i], 0x0F);
        display_level_text.Y += 1;
    }
}
