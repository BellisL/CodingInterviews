#include <iostream>
#include <vector>
#include <algorithm>

int leastSteps2Zero_1(int vNum);
int leastSteps2Zero_2(int vNum);
void test(const char* vpTestName, int vNum, int vExpect);

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 0);
	test("Test3", 2, 1);
	test("Test4", 3, 2);
	test("Test5", 4, 2);
	test("Test6", 5, 3);
	test("Test7", 6, 3);
	test("Test8", 7, 4);
	test("Test9", 8, 3);
	test("Test10", 9, 4);

	return 0;
}

int leastSteps2Zero_1(int vNum)
{
	if (vNum <= 1) return 0;

	if ((vNum & 1) == 0)
		return 1 + leastSteps2Zero_1(vNum >> 1);
	else
		return 2 + std::min(leastSteps2Zero_1(vNum >> 1), leastSteps2Zero_1((vNum + 1) >> 1));
}

int leastSteps2Zero_2(int vNum)
{
	if (vNum < 1) return 0;

	std::vector<int> Set(vNum + 1, 0);
	Set[0] = 0;
	Set[1] = 0;
	for (int i = 2; i <= vNum; ++i)
	{
		if ((i & 1) == 0)
			Set[i] = Set[i >> 1] + 1;
		else
			Set[i] = 2 + std::min(Set[i >> 1], Set[(i + 1) >> 1]);
	}

	return Set[vNum];
}

void test(const char* vpTestName, int vNum, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Steps_1 = leastSteps2Zero_1(vNum);
	auto Steps_2 = leastSteps2Zero_2(vNum);
	if (Steps_1 == vExpect && Steps_2 == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}