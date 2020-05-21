#pragma once
#include "MatrixBase.h"
class Matrix2D: public MatrixBase
{
public:
	Matrix2D() : MatrixBase(siz) {}
	virtual int element(unsigned int i, unsigned int j) const override;
	virtual int& element(unsigned int i, unsigned int j)override;
private:
    static const int siz = 2;
	int arr[siz][siz];
};

