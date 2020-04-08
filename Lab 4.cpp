

#include "pch.h"
#include <iostream>
#include "Matrix3x3.h"
using namespace std;


int main()
{
	Matrix3x3 matr= Matrix3x3::Matrix3x3();
	matr.fillRandomElements(-10, 10);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<matr.element(i,j)<<"\t";
		}
		cout << endl;
	}
	cout << "SumPrinDiag= " << matr.sumPrincipalDiag() << " SumSideDiag= " << matr.sumSecondaryDiag() << endl << endl;
	cout << "ProdPrinDiag= " << matr.productPrinsipalDiag() << " ProdSideDiag= " << matr.productSecondaryDiag() << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		cout<<"SumRow" << i + 1 << "= " <<matr.sumRow(i)<<endl;
		cout << "MaxInColun" << i + 1 << " = " << matr.maxColumn(i) << "  MinInColun" << i + 1 << " = " << matr.minColumn(i) << endl << endl;
	}
	system("pause");
	return 0;
}
















/*int arr[4][4] = { {4,6,7,3},
					  {3,4,6,2},
					  {4,1,8,9},
					  {3,5,2,1} };
	int sizeOfArr = size(arr);
	int SumMain = 0;
	int SumSide = 0;
	for (int i = 0; i < sizeOfArr;i++)
	{
		SumMain += arr[i][i];
		SumSide += arr[sizeOfArr - i - 1][i];
	}
	cout << "SumMain= " << SumMain << " SumSide= " << SumSide << endl<<endl;
	int SumInRow;
	int Max;
	int Min;
	for (int i = 0; i < sizeOfArr; i++)
	{
		SumInRow = 0;
		Max = arr[i][0];
		Min = arr[i][0];
		for (int j = 0; j < sizeOfArr; j++)
		{
			if (arr[j][i] > Max)Max = arr[j][i];
			if (arr[j][i] < Min)Min = arr[j][i];
			SumInRow += arr[i][j];
		}
		cout << "SumInRow" << i + 1 << "= " << SumInRow << endl;
		cout << "MaxInColun" << i + 1 << " = " << Max << "  MinInColun" << i + 1 << " = " << Min << endl<<endl;
	}*/

