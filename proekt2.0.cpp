#define _CRT_SECURE_NO_WARNINGS

#include "FFT.h"
#include "plot.h"
#include <iostream>
#include <complex>
#include <vector>
#include <cstdio>

#define cmp complex<double>

using namespace std;
const double pi = acos(-1);



int main()
{
    freopen("input/0004.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 30000;
    cmp * F;
    double temp = 0;
    double mid = 0;
    F = new cmp[n];
    for (int i = 0; i < n; i++) {
        double d;
        cin >> temp >> d >> temp >> temp;
        mid += d;
        F[i] = d;
    }
    mid /= n;
    for (int i = 0; i < n; i++) {
        F[i] -= mid;
    }
    vector<double> ans1, ans2;
    for (double f = 0; f < 40; f+=0.05) {
        cmp A = dft1(F, n, 2.0 * pi / 250.0, f);
        ans1.push_back(abs(real(A)) *5000/n);
        ans2.push_back(abs(A) * 10);
        cout << real(A) << "\t" << abs(A) << "\n";
    }

    init();
    grid(100, 100);
    plot(ans1, RGB(0, 255, 0));
    //plot(ans2, RGB(0, 255, 255));

    string s;
    while (1) {
        cin >> s;
    }

    return 0;
}