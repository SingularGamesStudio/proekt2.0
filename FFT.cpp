#include <iostream>
#include <complex>
#include <vector>
#include "FFT.h"

#define cmp complex<double>

using namespace std;

cmp dft1(cmp* dots, int len, const double& pi2f0, double f){
	if (len == 1) {
		return dots[0];
	}
	cmp *v1, *v2;
	v1 = new cmp[len / 2];
	v2 = new cmp[len / 2];
	if (len % 2) {
		for (int i = 0; i < len - 1; i++) {
			if (i % 2) {
				v1[i/2] = dots[i];
			}
			else v2[i / 2] = dots[i];
		}
		cmp a = dft1(v1, len / 2, pi2f0, f * 2)*exp((0.0+1i)*pi2f0*f), b = dft1(v2, len / 2, pi2f0, f * 2);
		return exp((0.0 + 1i) * pi2f0*f * (double)(len - 1))*dots[len-1] + a + b;
	}
	for (int i = 0; i < len - 1; i++) {
		if (i % 2) {
			v1[i / 2] = dots[i];
		}
		else v2[i / 2] = dots[i];
	}
	cmp a = dft1(v1, len/2, pi2f0, f * 2) * exp((0.0 + 1i) * pi2f0*f), b = dft1(v2, len / 2, pi2f0, f * 2);
	return a + b;
}