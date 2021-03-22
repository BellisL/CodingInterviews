#include <iostream>
#include <vector>

int maxProfit(const std::vector<int>& vSet);
void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect);

int main()
{
	{
		std::vector<int> Set = { 4, 1, 3, 2, 5 };
		test("Test1", Set, 4);
	}

	{
		std::vector<int> Set = { 1, 2, 4, 7, 11, 16 };
		test("Test2", Set, 15);
	}

	{
		std::vector<int> Set = { 16, 11, 7, 4, 2, 1 };
		test("Test3", Set, -1);
	}

	{
		std::vector<int> Set = { 16, 16, 16, 16, 16 };
		test("Test4", Set, 0);
	}

	{
		std::vector<int> Set = { 9, 11, 5, 7, 16, 1, 4, 2 };
		test("Test5", Set, 11);
	}

	{
		std::vector<int> Set = { 2, 4 };
		test("Test6", Set, 2);
	}

	{
		std::vector<int> Set = { 4, 2 };
		test("Test7", Set, -2);
	}

	{
		std::vector<int> Set = {  };
		test("Test8", Set, 0);
	}
	
	return 0;
}

int maxProfit(const std::vector<int>& vSet)
{
	if (vSet.size() < 2) return 0;

	int Min = vSet[0];
	int MaxProfit = vSet[1] - Min;
	for (int i = 2; i < vSet.size(); ++i)
	{
		if (vSet[i - 1] < Min)
			Min = vSet[i - 1];

		if (vSet[i] - Min > MaxProfit)
			MaxProfit = vSet[i] - Min;
	}

	return MaxProfit;
}


void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto MaxProfit = maxProfit(vSet);
	if (MaxProfit == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}