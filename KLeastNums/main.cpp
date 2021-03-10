#include "ArrayUtils.h"
#include <iostream>
#include <set>

typedef std::multiset<int, std::greater<int>> Set;
typedef std::multiset<int, std::greater<int>>::iterator SetIter;

void leastKNums_1(int* vpData, int vLength, int vK);
void leastKNums_2(int* vpData, int vLength, Set& vSet, int vK);
void test(const char* vpTestName, int* vpData, int vLength, int vK);

int main()
{
	{
		int pData[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
		test("Test1", pData, sizeof(pData) / sizeof(int), 4);
	}

	{
		int pData[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
		test("Test2", pData, sizeof(pData) / sizeof(int), 8);
	}

	{
		int pData[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
		test("Test3", pData, sizeof(pData) / sizeof(int), 10);
	}

	{
		int pData[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
		test("Test4", pData, sizeof(pData) / sizeof(int), 1);
	}

	{
		int pData[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
		test("Test5", pData, sizeof(pData) / sizeof(int), 0);
	}

	{
		int pData[] = { 4, 5, 1, 6, 2, 7, 2, 8 };
		test("Test6", pData, sizeof(pData) / sizeof(int), 2);
	}

	{
		test("Test7", nullptr, 0, 0);
	}

	return 0;
}

void leastKNums_1(int * vpData, int vLength, int vK)
{
	if (!vpData || vLength <= 0 || vK < 1 || vK > vLength)
		throw std::runtime_error("Invalid input!");

	int Start = 0;
	int End = vLength - 1;
	int Index = partition(vpData, vLength, Start, End);
	while (Index != vK - 1)
	{
		if (Index > vK - 1)
			Index = partition(vpData, vLength, Start, Index - 1);
		else
			Index = partition(vpData, vLength, Index + 1, End);
	}
}

void leastKNums_2(int * vpData, int vLength, Set& vSet, int vK)
{
	if (!vpData || vLength <= 0 || vK < 1 || vK > vLength)
		throw std::runtime_error("Invalid input!");

	vSet.clear();
	for (int i = 0; i < vLength; ++i)
	{
		if (vSet.size() < vK)
			vSet.insert(vpData[i]);
		else
		{
			SetIter Iter = vSet.begin();
			if (vpData[i] < *Iter)
			{
				vSet.erase(*Iter);
				vSet.insert(vpData[i]);
			}
		}
	}
}

void test(const char * vpTestName, int * vpData, int vLength, int vK)
{
	std::cout << vpTestName << ":\n";

	try
	{
		Set Set;
		leastKNums_2(vpData, vLength, Set, vK);
		for (auto Iter = Set.begin(); Iter != Set.end(); ++Iter)
			std::cout << *Iter << "\t";
		std::cout << std::endl;
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		leastKNums_1(vpData, vLength, vK);
		for (int i = 0; i < vK; ++i)
			std::cout << vpData[i] << "\t";
		std::cout << std::endl;
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}
