#include <iostream>
#include <vector>
#include <algorithm>

int leastSteps2One_1(int vNum);
int leastSteps2One_2(int vNum);
void leastStepsCore(int vNum, int vTimes, int& vMin);
void test(const char* vpTestName, int vNum, int vExpect);

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 2, 2);
	test("Test4", 3, 2);
	test("Test5", 4, 3);
	test("Test6", 5, 4);
	test("Test7", 6, 3);
	test("Test8", 7, 4);
	test("Test9", 8, 4);
	test("Test10", 9, 3);
	test("Test11", 10, 4);

	return 0;
}

int leastSteps2One_1(int vNum)
{
	if (vNum < 1) return 0;

	int Min = INT_MAX;
	leastStepsCore(vNum, 0, Min);

	return Min;
}

int leastSteps2One_2(int vNum)
{
	if (vNum < 1) return 0;

	std::vector<int> Set(vNum + 1, 0);
	Set[1] = 1;
	for (int i = 2; i <= vNum; ++i)
	{
		Set[i] = 1 + Set[i - 1];
		if (i % 3 == 0)
			Set[i] = std::min(Set[i / 3] + 1, Set[i]);
		if (i % 2 == 0)
			Set[i] = std::min(Set[i / 2] + 1, Set[i]);
	}

	return Set[vNum];
}

void leastStepsCore(int vNum, int vTimes, int& vMin)
{
	if (vNum == 0)
	{
		if (vTimes < vMin)
			vMin = vTimes;
		return;
	}

	if (vTimes < vMin && vNum % 3 == 0)
		leastStepsCore(vNum / 3, vTimes + 1, vMin);
	if (vTimes < vMin && vNum % 2 == 0)
		leastStepsCore(vNum / 2, vTimes + 1, vMin);
	if (vTimes < vMin && vNum > 0)
		leastStepsCore(vNum - 1, vTimes + 1, vMin);
}

void test(const char* vpTestName, int vNum, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Steps_1 = leastSteps2One_1(vNum);
	auto Steps_2 = leastSteps2One_2(vNum);
	if (Steps_1 == vExpect && Steps_2 == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}