#include <iostream>

int add(int vA, int vB);
void test(const char* vpTestName, int vA, int vB, int vExpect);

int main()
{
	test("Test1", 1, 2, 3);
	test("Test2", 111, 899, 1010);
	test("Test3", -1, 2, 1);
	test("Test4", 1, -2, -1);
	test("Test5", 3, 0, 3);
	test("Test6", 0, -4, -4);
	test("Test7", -2, -8, -10);

	return 0;
}

int add(int vA, int vB)
{
	int Sum = 0;
	int Carry = 0;

	do
	{
		Sum = vA ^ vB;
		Carry = (vA & vB) << 1;
		vA = Sum;
		vB = Carry;
	} while (vB);

	return Sum;
}

void test(const char* vpTestName, int vA, int vB, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Sum = add(vA, vB);
	if (Sum == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}