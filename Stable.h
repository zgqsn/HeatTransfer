#pragma once
#include "CMatrix.h"
#include <fstream>


class Stable
{
public:
	Stable(double rambda_, double phie_, double voxSize_);
	Stable(void);
	~Stable(void);

	CMatrix getStable(CMatrix& boundary, CMatrix& label, double w, double crit);
	//void txtOut();

private:
	double rambda;
	double phie;
	double voxSize;
	CMatrix boundary;
	//CMatrix label;
};

