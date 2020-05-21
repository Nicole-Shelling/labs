#pragma once
#include "MatrixBase.h"
class Matrix3D: public MatrixBase
{
public:
	Matrix3D() : MatrixBase(siz) {}
	virtual int element(unsigned int i, unsigned int j) const override;
	virtual int& element(unsigned int i, unsigned int j)override;
private:
	static const int siz = 3;
	int arr[siz][siz];
};

