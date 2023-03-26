#include<iostream>
#include<cmath>
#include "constant.h"
#include "read_table.h"
#include "table.h"
#include "interpolation.h"
using namespace std;

int main()
{
	getdata();

	double Den = pow(10,2.3);
	double Energy = pow(10,20.4);
	double inter_result[datanumber];
	interpolation(Den, Energy, inter_result);

	cout << inter_result[0]<<"  " <<inter_result[1] ;

	system("pause");
	return 0; 
}