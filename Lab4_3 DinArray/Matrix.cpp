#include "pch.h"
#include "Matrix.h"
#include<cstdlib>

Matrix::Matrix(const int iDim)
{
	arr = new int*[iDim];
	for (int i = 0;i < iDim;i++)
		arr[i] = new int[iDim];
	size = iDim;
}
int Matrix::element(const int i, const int j) const
{
	return arr[i][j];
};
void Matrix::setElement(const int i, const int j, const int value)
{
	arr[i][j] = value;
};
void Matrix::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			 setElement(i, j, (rand() % 21) - 10);
};
int  Matrix::sumPrincipalDiag()const
{
	int Sum = 0;
	for (int i = 0; i < size; i++)
		Sum += element(i, i);
	return Sum;
};
int Matrix::sumSecondaryDiag()const
{
	int Sum = 0;
	for (int i = 0; i < size; i++)
		Sum += element(size-1 - i, i);
	return Sum;
};
int Matrix::productPrinsipalDiag() const
{
	int Prod = 1;
	for (int i = 0; i < size; i++)
		Prod *= element(i, i);
	return Prod;
};
int Matrix::productSecondaryDiag() const
{
	int Prod = 1;
	for (int i = 0; i < size; i++)
		Prod *= element(size-1- i, i);
	return Prod;
};
int Matrix::sumRow(const int iRow) const
{
	int Sum = 0;
	for (int i = 0; i < size; i++)
		Sum += element(iRow, i);
	return Sum;
};
int Matrix::minColumn(const int iCol) const
{
	int min = element(0, iCol);
	for (int j = 1; j < size; j++)
	{
		if (element(j, iCol) < min) min = element(j, iCol);
	}
	return min;
};
int Matrix::maxColumn(const int iCol) const
{
	int max = element(0, iCol);
	for (int j = 1; j < size; j++)
	{
		if (element(j, iCol) > max) max = element(j, iCol);
	}
	return max;
};
void Matrix::del()
{
	for (int j = 0; j < size; j++)
		delete[] arr[j];
	delete[] arr;
};


