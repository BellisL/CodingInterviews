#include <iostream>
#include <vector>

int missingNum(const std::vector<int>& vSet);
void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect);

int main()
{
	{
		std::vector<int> Set = { 1, 2, 3, 4, 5 };
		test("Test1", Set, 0);
	}

	{
		std::vector<int> Set = { 0, 1, 2, 3, 4 };
		test("Test2", Set, 5);
	}

	{
		std::vector<int> Set = { 0, 1, 2, 4, 5 };
		test("Test3", Set, 3);
	}

	{
		std::vector<int> Set = { 1 };
		test("Test4", Set, 0);
	}

	{
		std::vector<int> Set = { 0 };
		test("Test5", Set, 1);
	}

	return 0;
}

int missingNum(const std::vector<int>& vSet)
{
	int Low = 0;
	int High = vSet.size();
	while (Low < High)
	{
		int Mid = Low + ((High - Low) >> 1);
		Mid < vSet[Mid] ? High = Mid : Low = Mid + 1;
	}

	return Low;
}

void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto MissingNum = missingNum(vSet);
	if (MissingNum == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}