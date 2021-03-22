#include <iostream>
#include "OneN.h"
#include "BD.h"
#include "FunPtr.h"

int sum_Solution_1(int vNum);
int sum_Solution_2(int vNum);
void test(const char* vpTestName, int vNum);

int main()
{
	test("Test1", 1);
	test("Test2", 2);
	test("Test3", 3);
	test("Test4", 10);
	test("Test5", 100);

	return 0;
}

int sum_Solution_1(int vNum)
{
	COne2N::reset();
	COne2N* p = new COne2N[vNum];
	auto One2N = COne2N::getCnt();
	delete[] p;

	return One2N;
}

int sum_Solution_2(int vNum)
{
	CBase B;
	CDerive D;
	Array[0] = &B;
	Array[1] = &D;

	return Array[1]->sum(vNum);
}

void test(const char* vpTestName, int vNum)
{
	std::cout << vpTestName << std::endl;

	auto Expect = (1 + vNum) * vNum / 2;

	auto One2N_1 = sum_Solution_1(vNum);
	auto One2N_2 = sum_Solution_2(vNum);
	auto One2N_3 = sum_Solution_3(vNum);
	if (One2N_1 == Expect && One2N_2 == Expect && One2N_3 == Expect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}