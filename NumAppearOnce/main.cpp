#include <iostream>
#include <vector>

int getNumAppearOnce(const std::vector<int>& vSet);
void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect);

int main()
{
	{
		std::vector<int> Set = { 1, 1, 2, 2, 2, 1, 3 };
		test("Test1", Set, 3);
	}

	{
		std::vector<int> Set = { 4, 3, 3, 2, 2, 2, 3 };
		test("Test2", Set, 4);
	}

	{
		std::vector<int> Set = { 4, 4, 1, 1, 1, 7, 4 };
		test("Test3", Set, 7);
	}

	{
		std::vector<int> Set = { -10, 214, 214, 214 };
		test("Test4", Set, -10);
	}

	{
		std::vector<int> Set = { -209, 3467, -209, -209 };
		test("Test5", Set, 3467);
	}

	{
		std::vector<int> Set = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
		test("Test6", Set, 1023);
	}

	{
		std::vector<int> Set = { -1024, -1024, -1024, -1023 };
		test("Test7", Set, -1023);
	}

	{
		std::vector<int> Set = { -23, 0, 214, -23, 214, -23, 214 };
		test("Test8", Set, 0);
	}

	{
		std::vector<int> Set = { 0, 3467, 0, 0, 0, 0, 0, 0 };
		test("Test1", Set, 3467);
	}

	return 0;
}

int getNumAppearOnce(const std::vector<int>& vSet)
{
	if (vSet.empty()) throw std::runtime_error("Invalid input!");

	std::vector<int> BitSum(8 * sizeof(int), 0);
	for (const auto& Num : vSet)
	{
		int BitMask = 1;
		for (int i = BitSum.size() - 1; i >= 0; --i)
		{
			if (BitMask & Num) ++BitSum[i];
			BitMask = BitMask << 1;
		}
	}

	int Res = 0;
	for (int i = 0; i < BitSum.size(); ++i)
	{
		Res = Res << 1;
		Res |= BitSum[i] % 3;
	}

	return Res;
}

void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect)
{
	std::cout << vpTestName << std::endl;

	try
	{
		auto Res = getNumAppearOnce(vSet);
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