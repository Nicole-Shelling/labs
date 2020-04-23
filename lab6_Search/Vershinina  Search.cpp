#include "pch.h"
#include <iostream>
#include<cstdlib>
#include<tuple>
#include<vector>
#include<chrono>

using namespace std;
int Search(int *pBegin, int* pEnd,int Value)
{
	int* Begin = pBegin;
	while (*pBegin != Value && pBegin != pEnd)
	{
		pBegin++;
	}
	if ((*pBegin != Value) &&( pBegin = pEnd))
		return NULL;
	return pBegin-Begin;

};
void QuickSort(int* pBegin, int Begin,int End)
{
	int* currBeg = pBegin;
	for (int i = 0; i < Begin; i++)
	{
		currBeg++;
	}
	int* currEnd = pBegin;
	for (int i = 0; i < End; i++)
	{
		currEnd++;
	}
	int* l = currBeg;
	int* r = currEnd;
	int number = (currEnd - currBeg) / 2;
	int* current = currBeg;
	for (int i = 0; i < number; i++)
	{
		current++;
	}
	int x = *current;
	do
	{
		while (*l < x) l++;
		while (*r > x) r--;
		if (l <= r)
		{
			int o = *r;
			*r = *l;
			*l = o;
			l++;
			r--;
		}		
	} while (l <= r);

	if (l < currEnd) QuickSort(pBegin,l-pBegin,currEnd-pBegin);
	if (r > currBeg) QuickSort(pBegin, currBeg-pBegin,r-pBegin);
}
void QuickSort2(int* pBegin, int Begin, int End)
{
	int* currBeg = pBegin;
	for (int i = 0; i < Begin; i++)
	{
		currBeg++;
	}
	int* currEnd = pBegin;
	for (int i = 0; i < End; i++)
	{
		currEnd++;
	}
	vector<tuple<int*, int*>> stack;
	tuple<int*, int*> arr(currBeg, currEnd);
	stack.push_back(arr);
	while (!stack.empty())
	{
		tuple<int*, int*> arr2 = stack.back();
		int* Begin = get<0>(arr2);
		int* End = get<1>(arr2);
		int* l = Begin;
		int* r = End;
		int number = (End-Begin) / 2;
		int* current = Begin;
		for (int i = 0; i < number; i++)
		{
			current++;
		}
		int x = *current;
		do
		{
			while (*l < x) l++;
			while (*r > x) r--;
			if (l <= r)
			{
				int o = *r;
				*r = *l;
				*l = o;
				l++;
				r--;
			}
		} while (l <= r);
		stack.pop_back();
		tuple<int*, int*> right(l, End);
		tuple<int*, int*> left(Begin, r);
		if (l < End) stack.push_back(right);
		if (r > Begin) stack.push_back(left);
	}
	
}

int BSearch(int *pBegin, int* pEnd, int Value)
{
	int* Begin = pBegin;
	while (pBegin <= pEnd)
	{
		int number = (pEnd - pBegin) / 2;
		int* current = pBegin;
		for (int i = 0; i < number; i++)
		{
			current++;
		}
		if (*current < Value)  pBegin = current;
		else if (*current > Value) pEnd = current;
		else return current-Begin;		
	}
	return NULL;
}
int* BSearch2(int *pBegin, int* pEnd, int Value)
{
	int number = (pEnd - pBegin) / 2;
	int* current = pBegin;
	for (int i = 0; i < number; i++)
	{
		current++;
	}
	if (*current < Value)	return BSearch2(++current, pEnd, Value);
	else if (*current > Value) return BSearch2(pBegin, --current, Value);
	else
	{
		return current;
	}		
	return NULL;
}

int main()
{
	const int N = 100;
	int Array[N];
	cout << "Array" << endl;
	for (int i = 0;i < N;i++)
	{
		Array[i] = (rand() % 21) - 10;
		cout << Array[i]<<"  ";		
	};
	// Search
	int* pBegin = &Array[0];
	int* pEnd = &Array[N-1];
	auto t1 = chrono::steady_clock::now();
	int Result = Search(pBegin, pEnd, 1);
	auto t2 = chrono::steady_clock::now();
	auto dt = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	cout << endl << "time1  " << dt.count()<< " mcrs " << endl;
	if (Result == NULL) cout << endl << "Element not found";
	else cout << endl << Result;
	//QuickSort1
	int* pBegin2 = &Array[0];
	QuickSort(pBegin2, 0, N-1);
	cout <<endl<< "QuickSort Array" << endl;
	for (int i = 0;i < N;i++)
	{
		cout << Array[i] << "  ";
	};
	//QuickSort2
	int* pBegin3 = &Array[0];
	int* pEnd3 = &Array[N - 1];
	QuickSort2(pBegin3, 0, N-1);
	cout << endl << "QuickSort2 Array" << endl;
	for (int i = 0;i < N;i++)
	{
		cout << Array[i] << "  ";
	};
	//BSearch1
	int* pBegin4 = &Array[0];
	int* pEnd4 = &Array[N - 1];
	auto t5 = chrono::steady_clock::now();
	int Result2 = BSearch(pBegin4, pEnd4, 1);
	auto t6 = chrono::steady_clock::now();
	auto dt3 = chrono::duration_cast<chrono::microseconds>(t6 - t5);
	cout << endl << "time2  " << dt3.count() << " mcrs " << endl;
	if (Result2 == NULL) cout << endl << "Element not found";
	else cout << endl << Result2;
	//BSearch2
	int* pBegin5 = &Array[0];
	int* pEnd5 = &Array[N - 1];
	auto t3 = chrono::steady_clock::now();
	int* Result3 = BSearch2(pBegin5, pEnd5, 1);
	auto t4 = chrono::steady_clock::now();
	auto dt2 = chrono::duration_cast<chrono::microseconds>(t4 - t3);
	cout << endl << "time2  " << dt2.count() << " mcrs " << endl;
	if (Result3 == NULL) cout << endl << "Element not found";
	else cout << endl << Result3-pBegin5;

	system("pause");
	return 0;
}

