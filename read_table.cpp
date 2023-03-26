#include "read_table.h"

void getdata()
{
	ifstream infile;
	infile.open("Helmholtz_29_21_den_energy.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "error" << endl;
	}
	infile >> den_index;
	infile >> energy_index;
	infile >> lgDenmin;
	infile >> lgDenmax;
	infile >> lgEmin;
	infile >> lgEmax;
	dlgDen = (lgDenmax - lgDenmin) / (den_index-1);
	dlgE = (lgEmax - lgEmin) / (energy_index - 1);
	T.def();
	P.def();
	for (int i = 0; i < den_index; i++)
	{
		for (int j = 0; j < energy_index; j++)
		{
			infile >> T.p[i][j];
			infile >> P.p[i][j];
		}
	}
	for (int i = 0; i < den_index; i++)
	{
		for (int j = 0; j < energy_index; j++)
		{
			T.p[i][j]= log(T.p[i][j])/log(10);
			P.p[i][j] = log(P.p[i][j])/log(10);
		}
	}
	infile.close();

}