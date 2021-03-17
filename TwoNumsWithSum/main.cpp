#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> numsofSum(const std::vector<int>& vSet, int vSum);
void test(const char* vpTestName, const std::vector<int>& vSet, int vSum, const std::pair<int, int>& vPair);

int main()
{
	{
		std::vector<int> Set = { 1, 2, 4, 7, 11, 15 };
		test("Test1", Set, 15, { 4, 11 });
	}

	{
		std::vector<int> Set = { 1, 2, 4, 7, 11, 15, 16 };
		test("Test2", Set, 17, { 1, 16 });
	}

	{
		std::vector<int> Set = { 1, 2, 4, 7, 11, 15 };
		test("Test3", Set, 10, std::pair<int, int>());
	}

	{
		std::vector<int> Set = {  };
		test("Test4", Set, 0, std::pair<int, int>());
	}

	return 0;
}

std::pair<int, int> numsofSum(const std::vector<int>& vSet, int vSum)
{
	if (vSet.size() < 2) throw std::runtime_error("Invalid input!");

	int Low = 0;
	int High = vSet.size() - 1;
	while (Low <= High)
	{
		auto Sum = vSet[Low] + vSet[High];
		if (Sum == vSum)
			return { vSet[Low], vSet[High] };
		else if (Sum > vSum)
			--High;
		else
			++Low;
	}

	return std::pair<int, int>();
}

void test(const char * vpTestName, const std::vector<int>& vSet, int vSum, const std::pair<int, int>& vPair)
{
	std::cout << vpTestName << std::endl;

	try
	{
		auto Pair = numsofSum(vSet, vSum);
		if ((Pair.first == vPair.first && Pair.second == vPair.second)
			|| (Pair.first == vPair.second && Pair.second == vPair.first))
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
