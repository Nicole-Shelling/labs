#include "pch.h"
#include "Matrix3x3.h"
#include<cstdlib>

using namespace std;
Matrix3x3::Matrix3x3()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = 0;
}
void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			setElement(i,j,(rand()%21)-10);
};
int Matrix3x3::element(const int i, const int j) const
{
	return matrix[i][j];
};
void Matrix3x3::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
};
int  Matrix3x3::sumPrincipalDiag()const
{
	int Sum = 0;
	for (int i = 0; i < 3; i++)
		Sum += element(i, i);
	return Sum;
};
int Matrix3x3::sumSecondaryDiag()const
{
	int Sum = 0;
	for (int i = 0; i < 3; i++)
		Sum += element(2-i, i);
	return Sum;
};
int Matrix3x3::productPrinsipalDiag() const
{
	int Prod = 1;
	for (int i = 0; i < 3; i++)
		Prod *= element(i, i);
	return Prod;
};
int Matrix3x3::productSecondaryDiag() const
{
	int Prod = 1;
	for (int i = 0; i < 3; i++)
		Prod *= element(2 - i, i);
	return Prod;
};
int  Matrix3x3::sumRow(const int iRow) const
{
	int Sum = 0;
	for (int i = 0; i < 3; i++)
		Sum += element(iRow, i);
	return Sum;
};
int Matrix3x3::minColumn(const int iCol) const
{
	int min = element(0, iCol);
	for (int j = 1; j < 3; j++)
	{
		if (element(j, iCol) < min) min = element(j, iCol);
	}
	return min;
};
int Matrix3x3::maxColumn(const int iCol) const
{
	int max = element(0, iCol);
	for (int j = 1; j < 3; j++)
	{
		if (element(j, iCol) > max) max = element(j, iCol);
	}
	return max;
};


