#include <iostream>
#include <vector>

int numEqual2Index(const std::vector<int>& vSet);
void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect);

int main()
{
	{
		std::vector<int> Set = { -3, -1, 1, 3, 5 };
		test("Test1", Set, 3);
	}

	{
		//有多个解
		std::vector<int> Set = { 0, 1, 3, 5, 6 };
		test("Test2", Set, 1);
	}

	{
		std::vector<int> Set = { -1, 0, 1, 2, 4 };
		test("Test3", Set, 4);
	}

	{
		std::vector<int> Set = { -1, 0, 1, 2, 5 };
		test("Test4", Set, -1);
	}

	{
		std::vector<int> Set = { 0 };
		test("Test5", Set, 0);
	}

	{
		std::vector<int> Set = { 10 };
		test("Test6", Set, -1);
	}

	{
		std::vector<int> Set = {  };
		test("Test7", Set, -1);
	}

	return 0;
}

int numEqual2Index(const std::vector<int>& vSet)
{
	if (vSet.empty()) return -1;

	int Low = 0;
	int High = vSet.size();
	while (Low < High)
	{
		int Mid = Low + ((High - Low) >> 1);
		if (vSet[Mid] == Mid)
			return Mid;
		else if (vSet[Mid] > Mid)
			High = Mid;
		else
			Low = Mid + 1;
	}

	return -1;
}

void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto MissingNum = numEqual2Index(vSet);
	if (MissingNum == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}