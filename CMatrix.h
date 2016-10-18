#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H

class CMatrix
{
public:
	/*****************Constructor and destructor********************************
	nx, ny and nz is the length of x, y, z dimension.
	
	*************Copyright all Reserved @ WUJINCHAO****************************/

	/*******************************3D Matrix**********************************/
	CMatrix(int nx, int ny, int nz);
	void setValue(int x, int y, int z, double v);
	double getValue(int x, int y, int z);


	/*******************************2D Matrix*********************************/
	CMatrix(int nx, int ny);
	void setValue(int x, int y, double v);
	double getValue(int x, int y);


	/*******************************1D Matrix*********************************/
	CMatrix(int nx);
	void setValue(int x, double v);
	double getValue(int x);


	/********************************SHARED***********************************/
	~CMatrix(void);
	CMatrix(void);
    CMatrix(CMatrix &m);
	void getInfo();
	int getNx();
	int getNy();
	int getNz();
	CMatrix max();
private:
	int nx;
	int ny;
	int nz;
	int nDims;
	double* p;
};

#endif // !CMATRIX_H



