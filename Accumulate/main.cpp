#include <iostream>
#include "OneN.h"
#include "BD.h"
#include "FunPtr.h"
#include "Temp.h"

int sum_Solution_1(int vNum);
int sum_Solution_2(int vNum);
void test(const char* vpTestName, int vNum);

int main()
{
	test("Test1", 1);
	std::cout << Sum_Solution_4<1>::Sum << std::endl;
	test("Test2", 2);
	std::cout << Sum_Solution_4<2>::Sum << std::endl;
	test("Test3", 3);
	std::cout << Sum_Solution_4<3>::Sum << std::endl;
	test("Test4", 10);
	std::cout << Sum_Solution_4<10>::Sum << std::endl;
	test("Test5", 100);
	std::cout << Sum_Solution_4<100>::Sum << std::endl;

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
	std::cout << std::endl;
	std::cout << vpTestName << std::endl;

	auto Expect = (1 + vNum) * vNum / 2;

	auto One2N_1 = sum_Solution_1(vNum);
	auto One2N_2 = sum_Solution_2(vNum);
	auto One2N_3 = sum_Solution_3(vNum);
	if (One2N_1 == Expect && One2N_2 == Expect && One2N_3 == Expect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";
}