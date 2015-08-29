#include "help.h"

extern Console console;
COORD helpLocation;
char helparr[50][1000];
int helprows = 0;
int helpcols = 0;

char *helpPlayerReturn;
char *Displayhelp2[10];
int Displayhelp2row;
COORD help2Location;

void helpPosition()
{
    ifstream inHelp;
    inHelp.open("displayHelp.txt");
    string Helping;
    while ( getline(inHelp, Helping) && !inHelp.eof() )
    {
        helpcols = 0;
        for ( size_t y = 0; y < Helping.size(); ++y) {
            helparr[helprows][helpcols] = Helping[y];
            ++helpcols;
        }
        ++helprows;
    }
    inHelp.close();
    helpLocation.X = 20;
    helpLocation.Y = 1;
    helpPlayerReturn = "PRESS SPACE TO RETURN";

    ifstream inHelp2;
    inHelp2.open("displayHelp2.txt");
    string help2Data;
    while ( !inHelp2.eof() && getline(inHelp2, help2Data) )
    {
        Displayhelp2[Displayhelp2row] = new char[50];
        for ( size_t u = 0; u < help2Data.size(); ++u)
        {
            char letter = help2Data[u];
            if ( letter == '#' )
            {
                letter = (char)153;
            }
            if ( letter == '@')
            {
                letter = (char)154;
            }
            *(Displayhelp2[Displayhelp2row] + u) = letter;
        }
        *(Displayhelp2[Displayhelp2row] + help2Data.size() ) = '\0';
        ++Displayhelp2row;
    }
    inHelp2.close();
}

void displayHelp()
{
    helpLocation.Y = 1;
    for ( int i = 0; i < helprows; ++i) {
        helpLocation.X = 20;
        for ( int j = 0; j < helpcols; ++j) {
            if ( i == 9 && j == 0)
            {
                console.writeToBuffer( helpLocation, ' ' , 0x6A );
                helpLocation.X += 1;
                continue;
            }
            console.writeToBuffer( helpLocation, helparr[i][j], 0x0F );
            helpLocation.X += 1;
        }
        helpLocation.Y += 1;
    }
    helpLocation.Y -= 1;
    helpLocation.X = 100;
    console.writeToBuffer( helpLocation, helpPlayerReturn, 0x0F);

    help2Location.Y = 1;
    help2Location.X = 80;
    for ( int numofrows = 0; numofrows < Displayhelp2row; ++numofrows)
    {
        console.writeToBuffer(help2Location, Displayhelp2[numofrows], 0x0F);
        help2Location.Y += 1;
    }
}