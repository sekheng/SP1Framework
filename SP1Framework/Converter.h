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

void convert(int &a);
void convert(int &y,int &x,int num,char pass);
void convertStart(int &tempY, int &tempX);
void convert(int &tempY,int &tempX, int mno);
void convert(int &y, int &x);
void convert2(int &b, string &x,int &c);
void convertbox(int &tempY, int &tempX, int bno);

#endif  // _CONVERT_H