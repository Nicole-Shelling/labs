#include "pch.h"
#include "Matrix3D.h"
#include "MatrixBase.h"

int Matrix3D::element(unsigned int i, unsigned int j) const
{
	return arr[i][j];
}
int& Matrix3D::element(unsigned int i, unsigned int j)
{
	return arr[i][j];
}
