#include <iostream>
#include <vector>
#include <algorithm>

bool isShunZi(std::vector<int>& vSet);
void test(const char* vpTestName, std::vector<int>& vSet, bool vExpect);

int main()
{
	{
		std::vector<int> Set = { 1, 3, 2, 5, 4 };
		test("Test1", Set, true);
	}

	{
		std::vector<int> Set = { 1, 3, 2, 6, 4 };
		test("Test2", Set, false);
	}

	{
		std::vector<int> Set = { 0, 3, 2, 6, 4 };
		test("Test3", Set, true);
	}

	{
		std::vector<int> Set = { 0, 3, 1, 6, 4 };
		test("Test4", Set, false);
	}

	{
		std::vector<int> Set = { 1, 3, 0, 5, 0 };
		test("Test5", Set, true);
	}

	{
		std::vector<int> Set = { 1, 3, 0, 7, 0 };
		test("Test6", Set, false);
	}

	{
		std::vector<int> Set = { 1, 0, 0, 5, 0 };
		test("Test7", Set, true);
	}

	{
		std::vector<int> Set = { 1, 0, 0, 7, 0 };
		test("Test8", Set, false);
	}

	{
		std::vector<int> Set = { 3, 0, 0, 0, 0 };
		test("Test9", Set, true);
	}

	{
		std::vector<int> Set = { 0, 0, 0, 0, 0 };
		test("Test10", Set, true);
	}

	{
		std::vector<int> Set = { 1, 0, 0, 1, 0 };
		test("Test11", Set, false);
	}

	{
		std::vector<int> Set = {  };
		test("Test12", Set, false);
	}

	return 0;
}

bool isShunZi(std::vector<int>& vSet)
{
	if (vSet.empty())
		return false;

	std::sort(vSet.begin(), vSet.end(), std::less<int>());

	int NumZero = 0;
	int NumGap = 0;
	for (int i = 0; i < vSet.size(); ++i)
	{
		if (vSet[i] == 0) ++NumZero;
	}

	int Left = NumZero;
	int Right = Left + 1;
	while (Right < vSet.size())
	{
		if (vSet[Left] == vSet[Right])
			return false;

		NumGap += vSet[Right] - vSet[Left] - 1;
		Left = Right;
		++Right;
	}

	return NumZero < NumGap ? false : true;
}

void test(const char* vpTestName, std::vector<int>& vSet, bool vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Res = isShunZi(vSet);
	if (Res == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}