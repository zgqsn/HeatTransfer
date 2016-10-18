#include "CMatrix.h"
#include <iostream>

//using namespace std;

/**************************3D Matrix****************************/
CMatrix::CMatrix(int nx, int ny, int nz)
{
	this -> nx = nx;
	this -> ny = ny;
	this -> nz = nz;
	nDims = 3;
	//double *p;
	p = new double[nx*ny*nz];
}


double CMatrix::getValue(int x, int y, int z)
{
	return p[(z-1)*nx*ny+(y-1)*nx+(x-1)];
}

void CMatrix::setValue(int x, int y, int z, double v)
{
	if (nDims != 3)
	{
		std::cout << "Input error!" << std::endl;
		system("pause");
	}
	p[(z-1)*nx*ny+(y-1)*nx+(x-1)] = v;
}


/**************************2D Matrix****************************/
CMatrix::CMatrix(int nx, int ny)
{
	this -> nx = nx;
	this -> ny = ny;
	this -> nz = 1;
	nDims = 2;
	//double *p;
	p = new double[nx*ny*nz];
}

double CMatrix::getValue(int x, int y)
{
	return p[(1-1)*nx*ny+(y-1)*nx+(x-1)];
}

void CMatrix::setValue(int x, int y, double v)
{
	if (nDims != 2)
	{
		std::cout << "Input error!" << std::endl;
		system("pause");
	}
	p[(1-1)*nx*ny+(y-1)*nx+(x-1)] = v;
}

/**************************1D Matrix****************************/
CMatrix::CMatrix(int nx)
{
	this -> nx = nx;
	this -> ny = 1;
	this -> nz = 1;
	nDims = 1;
	//double *p;
	p = new double[nx*ny*nz];
}

double CMatrix::getValue(int x)
{
	return p[(1-1)*nx*ny+(1-1)*nx+(x-1)];
}

void CMatrix::setValue(int x, double v)
{
	if (nDims != 1)
	{
		std::cout << "Input error!" << std::endl;
		system("pause");
	}
	p[(1-1)*nx*ny+(1-1)*nx+(x-1)] = v;
}



/********************************SHARED***********************************/
void CMatrix::getInfo()
{
	if (nz != 1 && ny != 1 && nx != 1)
	{
		std::cout<< "The dimension of the Matrix is: " << "nx = " << nx << ", ny = " << ny << ", nz = " << nz << "." << std::endl;
	}
	else if (nz = 1 && ny != 1)
	{
		std::cout<< "The dimension of the Matrix is: " << "nx = " << nx << ", ny = " << ny << "." << std::endl;
	}
	else
	{
		std::cout<< "The dimension of the Matrix is: " << "nx = " << nx << "." << std::endl;
	}
}

CMatrix::~CMatrix(void)
{
	delete[] p;
}

CMatrix::CMatrix(void)
{
	p = new double[1];
}

/******************************Copy Constructor**************************/
CMatrix::CMatrix(CMatrix &m)
{
	nx = m.getNx();
	ny = m.getNy();
	nz = m.getNz();
	nDims = m.nDims;
	p = new double[nx*ny*nz];
	for (int i = 1; i <= nx; i++) {
		for (int j = 1; j <= ny; j++) {
			for (int k = 1; k <= nz; k++) {
				p[(k-1)*nx*ny+(j-1)*nx+(i-1)] = m.getValue(i, j, k);
			}
		}
	}
}

inline int CMatrix::getNx()
{
	return nx;
}
inline int CMatrix::getNy()
{
	return ny;
}
inline int CMatrix::getNz()
{
	return nz;
}

//get the maxValue of CMatrix
CMatrix CMatrix::max(){
	CMatrix a(4);
	double maxValue = 0;
	int x;
	int y;
	int z;
	for (int i = 1; i <= nx; i++) {
		for (int j = 1; j <= ny; j++) {
			for (int k = 1; k <= nz; k++) {
				if (maxValue < p[(k-1)*nx*ny+(j-1)*nx+(i-1)]) {
					maxValue = p[(k-1)*nx*ny+(j-1)*nx+(i-1)];
					x = i;
					y = j;
					z = k;
				}
			}
		}
	}
	a.setValue(1, x);
	a.setValue(2, y);
	a.setValue(3, z);
	a.setValue(4, maxValue);
	return a;
}