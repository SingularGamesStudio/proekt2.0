#pragma once

#include <iostream>
#include<vector>
#include<windows.h>

#include "plot.h"

using namespace std;

void init();

void grid(int dx, int dy);

void plot(vector<double> dots, COLORREF col = RGB(0, 255, 0));