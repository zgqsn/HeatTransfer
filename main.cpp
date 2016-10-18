#include <iostream>

#include "CMatrix.h"
#include "Stable.h"

using namespace std;

int main()
{
	/*
	CMatrix rambda(100);
	CMatrix r(1);*/

	//CMatrix r2(200);
	//ofstream out("matrix.txt");
	//CMatrix r3(1);

	/*
	CMatrix ram(100);
	CMatrix c(a);
	*/

	/*for (int i = 1; i <= 200; i++) {
		r2.setValue(i, 4+i);
	}
	r2.setValue(100, 2000);
	*/
	//CMatrix b = r2.max();

	//cout<< b.getValue(1) << " " << b.getValue(4) << endl;
	//Stable s(0.5, 1000, 1.1, r2, r3);

	/*
	CMatrix &b = a;
	for (int i = 1; i <= 4; i++) {
		a.setValue(i, 4*i);
	}
	CMatrix c(a);
	for (int i = 1; i <= 4; i++) {
		cout << c.getValue(i) << " ";
	}
	cout << endl;
	*/
	/*
	if (out.is_open()) {
		for (int i = 1; i <= 200; i++) {
			out << r2.getValue(i) << " ";
		}
	}
	*/
	/************************set boundary and label*********************************
	
	*******************************************************************************/
	CMatrix bound(200, 200, 100);
	CMatrix labell(200, 200, 100);
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			for (int k = 1; k <= 100; k++) {
				bound.setValue(i, j, k, 37);
				labell.setValue(i, j, k, 2);
			}
		}
	}
	for (int i = 2; i <= 199; i++) {
		for (int j = 2; j <= 199; j++) {
			for (int k = 2; k <= 99; k++) {
				bound.setValue(i, j, k, 30);
				labell.setValue(i, j, k, 1);
			}
		}
	}
	bound.setValue(100, 100, 20, 100);
	labell.setValue(100, 100, 20, 2);
	double rambda = 0.5;
	double phie = 0;
	double voxSize = 0.001;
	double crit = 1e-8;
	double w = 1.5;
	//Stable s;
	Stable sample(rambda, phie, voxSize);
	CMatrix tMap = sample.getStable(bound, labell, w, crit);
	system("pause");
	return 0;
}