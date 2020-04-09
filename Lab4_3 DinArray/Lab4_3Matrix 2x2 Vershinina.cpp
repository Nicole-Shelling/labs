
#include "pch.h"
#include <iostream>
#include<cstdlib>
#include "Matrix.h"


using namespace std;
int main()
{
	Matrix matr = Matrix(3);
	matr.fillRandomElements(10, 10);
	for (int i = 0; i < matr.size; i++)
	{
		for (int j = 0; j < matr.size; j++)
			cout << matr.element(i, j) << "\t";
		cout << endl;
	};
	cout << "SumPrinDiag= " << matr.sumPrincipalDiag() << " SumSideDiag= " << matr.sumSecondaryDiag() << endl << endl;
	cout << "ProdPrinDiag= " << matr.productPrinsipalDiag() << " ProdSideDiag= " << matr.productSecondaryDiag() << endl << endl;
	for (int i = 0; i < matr.size; i++)
	{
		cout << "SumRow" << i + 1 << "= " << matr.sumRow(i) << endl;
		cout << "MaxInColun" << i + 1 << " = " << matr.maxColumn(i) << "  MinInColun" << i + 1 << " = " << matr.minColumn(i) << endl << endl;
	}
	matr.del();
	system("pause");
	return 0;
}

