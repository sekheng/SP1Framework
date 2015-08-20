#include "Gameover.h"

extern Console console;
COORD gameoverLocation;
char gameoverarr[50][1000];
int over_rows = 0;
int over_cols = 0;
extern COORD gameoverptr;
char *restart2 = "RESTART";
char *quit2 = "QUIT GAME?";
COORD rtrt;
COORD qt;

void gameoverPosition()
{
    ifstream inGameOver;
    inGameOver.open("displayGameOver.txt");
    string gameover;
    while ( getline(inGameOver, gameover) && !inGameOver.eof() )
    {
        over_cols = 0;
        for ( size_t y = 0; y < gameover.size(); ++y) {
            gameoverarr[over_rows][over_cols] = gameover[y];
            ++over_cols;
        }
        ++over_rows;
    }
    inGameOver.close();
    gameoverLocation.X = 30;
    gameoverLocation.Y = 1;
    rtrt.X = 56;
    rtrt.Y = 8;
    qt.X = 55;
    qt.Y = 9;
    gameoverptr.X = 65;
    gameoverptr.Y = 8;
}

void displayGameOver()
{
    gameoverLocation.Y = 1;
    for ( int i = 0; i < over_rows; ++i) {
        gameoverLocation.X = 30;
        for ( int j = 0; j < over_cols; ++j) {
            console.writeToBuffer( gameoverLocation, gameoverarr[i][j], 0x1A );
            gameoverLocation.X += 1;
        }
        gameoverLocation.Y += 1;
    }
    console.writeToBuffer( rtrt, restart2, 0x1A );
    console.writeToBuffer ( qt, quit2, 0x1A);
}