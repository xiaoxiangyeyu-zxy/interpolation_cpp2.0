#include "interpolation.h"


void interpolation(double den, double energy, double(&result)[datanumber])
{
	double lgden = log(den) / log(10);
	double lgE = log(energy) / log(10);
	int i = (lgden - lgDenmin) / dlgDen;
	int j = (lgE - lgEmin) / dlgE;
	double deltaden = lgden - lgDenmin - i * dlgDen;
	double deltaE = lgE - lgEmin - j * dlgE;
	double minus_deltaden = dlgDen - deltaden;
	double minus_deltaE = dlgE - deltaE;
	double area = dlgDen * dlgE;
	result[0] = minus_deltaden * minus_deltaE * T.p[i][j] / area + minus_deltaden * deltaE * T.p[i][j + 1] / area +
		deltaden * minus_deltaE * T.p[i + 1][j] / area + deltaden * deltaE * T.p[i + 1][j + 1] / area;
	result[0] = pow(10, result[0]);
	result[1] = minus_deltaden * minus_deltaE * P.p[i][j] / area + minus_deltaden * deltaE * P.p[i][j + 1] / area +
		deltaden * minus_deltaE * P.p[i + 1][j] / area + deltaden * deltaE * P.p[i + 1][j + 1] / area;
	result[1] = pow(10, result[1]);
}