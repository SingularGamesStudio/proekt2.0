#include <iostream>
#include<vector>
#include<windows.h>

#include "plot.h"

using namespace std;
HDC dc;
int w, h;


void set(int x, int y, COLORREF col) {
    SetPixel(dc, x, h-y, col);
}

void line(int x1, int y1, int x2, int y2, COLORREF col = RGB(0, 255, 0)) {
    if (abs(x2 - x1) > abs(y2 - y1)) {
        if (x2 < x1) {
            swap(x1, x2);
            swap(y1, y2);
        }
        for (int x = x1; x <= x2; x++) {
            set(x, y1 + (double)(x - x1) * (y2 - y1) / (x2 - x1), col);
        }
    }
    else {
        if (y2 < y1) {
            swap(x1, x2);
            swap(y1, y2);
        }
        for (int y = y1; y <= y2; y++) {
            set(x1 + (double)(y - y1) * (x2 - x1) / (y2 - y1), y, col);
        }
    }
}

void init() {
    COORD coord;
    HWND myconsole = GetConsoleWindow();
    ShowWindow(myconsole, SW_SHOWMAXIMIZED);
    dc = GetDC(myconsole);
    RECT rc;
    GetClientRect(myconsole, &rc);
    w = rc.right;
    h = rc.bottom;
}

void grid(int dx, int dy) {
    for (int i = 0; i < w / dx; i++) {
        line(i * dx, 0, i * dx, h, RGB(130, 130, 130));
    }
    for (int i = 0; i < h / dy; i++) {
        line(0, i*dy, w, i*dy, RGB(130, 130, 130));
    }
}

void plot(vector<double> dots, COLORREF col) {

    int step = w / dots.size();
	for (int i = 0; i < dots.size() -1; i++) {
        line(i * step, dots[i] + 500, i * step + step, dots[i + 1] + 500, col);
	}
}