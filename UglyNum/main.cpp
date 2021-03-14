#include <iostream>
#include <vector>
#include <algorithm>

int getKthUglyNum(int vKth);
void test(const char* vpTestName, int vKth, int vExpect);

int main()
{
	test("Test1", 1, 1);
	test("Test2", 2, 2);
	test("Test3", 3, 3);
	test("Test4", 4, 4);
	test("Test5", 5, 5);
	test("Test6", 6, 6);
	test("Test7", 7, 8);
	test("Test8", 8, 9);
	test("Test9", 9, 10);
	test("Test10", 10, 12);
	test("Test11", 11, 15);
	test("Test12", 1500, 859963392);

	return 0;
}

int getKthUglyNum(int vKth)
{
	if (vKth < 1) throw std::runtime_error("Invalid input!");

	std::vector<int> UglySet(vKth + 1, 1);
	int T2 = 1;
	int T3 = 1;
	int T5 = 1;

	for (int i = 2; i <= vKth; ++i)
	{
		UglySet[i] = std::min(UglySet[T2] * 2, std::min(UglySet[T3] * 3, UglySet[T5] * 5));
		if (UglySet[T2] * 2 == UglySet[i]) ++T2;
		if (UglySet[T3] * 3 == UglySet[i]) ++T3;
		if (UglySet[T5] * 5 == UglySet[i]) ++T5;
	}

	return UglySet[vKth];
}

void test(const char * vpTestName, int vKth, int vExpect)
{
	std::cout << vpTestName << std::endl;

	try
	{
		int Res = getKthUglyNum(vKth);
		if (Res == vExpect)
			std::cout << "PASSED.\n";
		else
			std::cout << "FAILED.\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}