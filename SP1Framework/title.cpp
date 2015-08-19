#include "title.h"

void titleconvert(int &g) 
{
    if ( g == ' ' ) 
    {
        g = 0;
    }
    if  ( g == 'O' )
    {
        g = 1;
    }
    if ( g == 'o' ) 
    {
        g = 2;
    }
    if ( g == '.' ) 
    {
        g = 3;
    }
    if ( g == '`' )
    {
        g = 4;
    }
    if ( g == 39 ) 
    {
        g = 5;
    }
}

void titleconvert2(int &a, string &x, int &c)
{
    if (a == 0) {
		x = " ";
		c = 0;
	}
	if (a == 1){
		x = "O";
		c = 0;
	}
	if (a == 2) {
		x = "o";
		c = 0;
	}
	if (a == 3) {
		x = ".";
		c = 0;
	}
	if (a == 4) {
		x = "`";
		c = 0;
	}
    if ( a == 5 ) 
    {
        x = "'";
        c = 0;
    }
}