#ifndef _LOADLEVEL_H
#define _LOADLEVEL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

void loadlevel();
void reloadlevel();
void loadcustomlevel();
void loadcustomizedlevel();
void reloadcustomizedlevel();
void reloadcustomlevel();

void writelevel(char &a);

void renderwrittenlevel();
void savecustomlevel();


#endif  