
#include "pch.h"
#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

void fillArr(MatrixBase& matr)
{
	int a = 1;
	for (int i = 0;i < matr.size();i++)
	{
		for (int j = 0;j < matr.size();j++)
		{
			matr.element(i,j)= a;
			a++;
		}
	}
}
int main()
{
	Matrix2D m2a, m2b;
	Matrix3D m3a, m3b;
	fillArr(m2a);
	fillArr(m2b);
	fillArr(m3a);
	fillArr(m3b);
	cout << "Matrix at begin"<< endl;
	cout << m2a << endl;
	cout << m2b << endl;
	cout << m3a << endl;
	cout << m3b << endl;
	m2b *= 6;
	m2a *= 3;
	m3a *= 7;
	m3b *= 2;
	cout <<"m2b * 6  "<< endl << m2b << endl;
	cout << "m2a * 3  "<< endl << m2a << endl;
	cout << "m3a * 7  " << endl << m3a << endl;
	cout << "m3b * 2  " << endl << m3b << endl;
	m2a += m2b;
	m3a += m3b;
	cout <<"Sum m2a and m2b"<< endl << m2a << endl;	
	cout <<"Sum m3a and m3b"<< endl << m3a << endl;	
	return 0;
}
