#include "Stable.h"
#include <iostream>
//#include <fstream>


Stable::Stable(double rambda_, double phie_, double voxSize_)
{
	rambda = rambda_;
	phie = phie_;
	voxSize = voxSize_;
	//boundary = boundary_;
	//label = label_;

	/*************************Test*****************************
	for (int i = 1; i<= 100; i++) {
		std::cout<< rambda.getValue(i) << " ";
	}
	std::cout<< std::endl;
	**********************************************************/
}

Stable::Stable(void) 
{
	CMatrix b(1);
	boundary = b;
}

Stable::~Stable(void)
{
	//std::cout << "stable deconstructor called! " << std::endl;
}


CMatrix Stable::getStable(CMatrix& boundary, CMatrix& label, double w, double crit)
{
	//To get the size of boundary
	int nx = boundary.getNx();
	int ny = boundary.getNy();
	int nz = boundary.getNz();
	double temp;

	CMatrix errorMap(nx, ny, nz);
	CMatrix tMap1 = boundary;
	CMatrix tMap2 = boundary;

	int n = 1;

	//set the initial value of the central vox of errorMap
	errorMap.setValue((int)(nx/2), (int)(ny/2), (int)(nz/2), 1);
	
	//iterate step: w is the SOR factor and crit is the stop criterion
	//while (errorMap.getValue((int)(nx/2), (int)(ny/2), (int)(nz/2)) >= crit) {
	while (n > 2) {
		for (int i = 1; i<= nx; i++) {
			for (int j = 1; j <= ny; j++) {
				for (int k = 1; k <= nz; k++) {
					if (label.getValue(i, j, k) == 0) {
						tMap2.setValue(i, j, k, 0);
						errorMap.setValue(i, j, k, 0);
					}
					else if (label.getValue(i, j, k) == 1) {
						temp = (1-w)*tMap1.getValue(i, j, k) + w*(1/6*(tMap2.getValue(i-1, j, k) + 
							tMap1.getValue(i+1, j, k) + tMap2.getValue(i, j-1, k) + tMap1.getValue(i, j+1, k) + 
							tMap1.getValue(i, j, k+1) + tMap2.getValue(i, j, k-1) + voxSize*voxSize*phie/rambda));
						tMap2.setValue(i, j, k, temp);

						//set the value of errorMap(i, j, k);
						temp = tMap2.getValue(i, j, k) - tMap1.getValue(i, j, k);
						errorMap.setValue(i, j, k, temp);
					}
					else {
						tMap2.setValue(i, j, k, boundary.getValue(i, j, k));
						errorMap.setValue(i, j, k, 0);
					}
				}
			}
		}
		tMap1 = tMap2;
		n = n+1;
	}


	

	// output the tMap2 to tMap.txt

	/*
	std::ofstream out("tMap.txt");
	if (out.is_open()) {
		out << nx << " " << ny << " " << nz << " " << std::endl; 
		for (int i = 1; i <= nx; i++) {
			for (int j = 1; j <= ny; j++) {
				for (int k = 1; k<= nz; k++) {
					out << tMap2.getValue(i, j, k) << " ";
				}
			}
		}
		out.close();
	}
	*/
	return tMap2;
}

