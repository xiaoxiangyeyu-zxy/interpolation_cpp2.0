#include "class_table.h"

void tabledata::def()
{
	p = new double* [den_index];
	for (int i = 0; i < den_index; i++)
		p[i] = new double[energy_index];
}

tabledata::~tabledata()
{
	for (int i = 0; i < den_index; i++)
		if (p[i] != NULL)
		{
			delete[] p[i];
			p[i] = NULL;
			cout << "destruction1" << endl;
		}
	if (p != NULL)
	{
		delete[] p;
		p = NULL;
		cout << "destruction2" << endl;
	}
	
}