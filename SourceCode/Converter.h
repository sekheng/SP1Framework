#ifndef _CONVERT_H
#define _CONVERT_H

#include <iostream>
#include "Framework\console.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void convert(int &a, int b, int c);
void convert(int &y,int &x,int num,char pass);
void convertStart(int &tempY, int &tempX);
void convert2(int &b, string &x,int &c);

#endif  // _CONVERT_H