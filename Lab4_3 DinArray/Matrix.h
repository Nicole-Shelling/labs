#pragma once
class Matrix
{
public:
	Matrix(const int iDim);
	
	int size;
	void setElement(const int i, const int j, const int value);
	int element(const int i, const int j) const;
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipalDiag()const;
	int sumSecondaryDiag()const;
	int productPrinsipalDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int iRow) const;
	int minColumn(const int iCol) const;
	int maxColumn(const int iCol) const;
	void del();
private:
	int**arr;	
};

