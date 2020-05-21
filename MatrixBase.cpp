#include "pch.h"
#include "MatrixBase.h"
#include <iostream>

unsigned int MatrixBase::size() const
{
	return m_size;
}

MatrixBase::MatrixBase(unsigned int iSize) : m_size(iSize) {}

void MatrixBase::operator *=(int iMult)
{
	for (int i = 0;i < m_size;i++)
	{
		for (int j = 0;j < m_size;j++)
		{
			element(i, j) = element(i, j)*iMult;
		}
	}
}
void MatrixBase::operator  += (MatrixBase& iAdd)
{
	for (int i = 0;i < m_size;i++)
	{
		for (int j = 0;j < m_size;j++)
		{
			element(i, j) = element(i, j)+iAdd.element(i,j);
		}
	}
}

std::ostream&operator <<(std::ostream&stream, const MatrixBase&iMatrix)
{
	for (int i = 0; i < iMatrix.size(); i++)
	{
		for (int j = 0; j < iMatrix.size(); j++)
			std::cout << iMatrix.element(i, j) << "\t";
		std::cout << std::endl;
	}
	return stream;
}
