#include <iostream>
#include "ArrayUtils.h"

int moreThanHalfNum_1(int* vpNum, int vLength);
int moreThanHalfNum_2(int* vpNum, int vLength);

bool checkMoreThanHalf(int* vpNum, int vLength, int vNum);
void test(const char* vpTestName, int* vpNum, int vLength);

int main()
{
	{
		int Num[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
		test("Test1", Num, sizeof(Num) / sizeof(int));
	}

	{
		int Num[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
		test("Test2", Num, sizeof(Num) / sizeof(int));
	}

	{
		int Num[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
		test("Test3", Num, sizeof(Num) / sizeof(int));
	}

	{
		int Num[] = { 1, 3, 4, 5, 2, 2, 2, 2, 2 };
		test("Test4", Num, sizeof(Num) / sizeof(int));
	}

	{
		int Num[] = { 1 };
		test("Test5", Num, sizeof(Num) / sizeof(int));
	}

	{
		test("Test6", nullptr, 0);
	}

	return 0;
}

int moreThanHalfNum_1(int * vpNum, int vLength)
{
	if (!vpNum || vLength <= 0)
		throw std::runtime_error("Invalid input!");

	int Mid = vLength >> 1;
	int Start = 0;
	int End = vLength - 1;
	int Index = partition(vpNum, vLength, Start, End);

	while (Index != Mid)
	{
		if (Index > Mid)
			Index = partition(vpNum, vLength, Start, Index - 1);
		else
			Index = partition(vpNum, vLength, Index + 1, End);
	}

	if (!checkMoreThanHalf(vpNum, vLength, vpNum[Mid]))
		throw std::runtime_error("Invalid input!");

	return vpNum[Mid];
}

int moreThanHalfNum_2(int * vpNum, int vLength)
{
	if (!vpNum || vLength <= 0)
		throw std::runtime_error("Invalid input!");

	int Cnt = 0;
	int Res = vpNum[0];

	for (int i = 0; i < vLength; ++i)
	{
		if (!Cnt)
		{
			Res = vpNum[i];
			++Cnt;
		}
		else if (vpNum[i] == Res)
		{
			++Cnt;
		}
		else
		{
			--Cnt;
		}
	}

	if (!checkMoreThanHalf(vpNum, vLength, Res))
		throw std::runtime_error("Invalid input!");

	return Res;
}



bool checkMoreThanHalf(int * vpNum, int vLength, int vNum)
{
	int Times = 0;
	for (int i = 0; i < vLength; ++i)
	{
		if (vpNum[i] == vNum) ++Times;
	}

	if (Times * 2 < vLength)
		return false;
	else 
		return true;
}

void test(const char * vpTestName, int * vpNum, int vLength)
{
	std::cout << vpTestName << ":\n";

	for (int i = 0; i < vLength; ++i)
		std::cout << vpNum[i] << "\t";

	std::cout << std::endl;

	//注意：这里的solution1改变了原数组元素顺序
	try
	{
		int Res = moreThanHalfNum_1(vpNum, vLength);
		std::cout << "Solution 1: " << Res << std::endl;
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		int Res = moreThanHalfNum_2(vpNum, vLength);
		std::cout << "Solution 2: " << Res << std::endl;
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}
