#include <iostream>

int digitInSequence(int vIndex);
int getNumBase(int vBase);
int digitAt(int vIndex, int vBase);
void test(const char* vpTestName, int vIndex, int vExpect);

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);
	test("Test6", 190, 1);//100
	test("Test7", 1000, 3);//370
	test("Test8", 1001, 7);
	test("Test9", 1002, 0);

	return 0;
}

int digitInSequence(int vIndex)
{
	if (vIndex < 0) return -1;

	int Base = 1;
	while (vIndex >= Base * getNumBase(Base))
	{
		vIndex -= Base * getNumBase(Base);
		++Base;
	}

	return digitAt(vIndex, Base);
}

int getNumBase(int vBase)
{
	if (vBase <= 0) return 0;
	if (vBase == 1)
		return 10;
	return 9 * pow(10, vBase - 1);
}

int digitAt(int vIndex, int vBase)
{
	int Index = vIndex / vBase;
	int Num = Index;
	if (vBase == 1)
		Num += 0;
	else
		Num += pow(10, vBase - 1);

	int IndexInDigit = vBase - vIndex % vBase;

	while (--IndexInDigit)
		Num /= 10;

	return Num % 10;
}

void test(const char* vpTestName, int vIndex, int vExpect)
{
	std::cout << vpTestName << std::endl;
	if (digitInSequence(vIndex) == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << "\n";
}
