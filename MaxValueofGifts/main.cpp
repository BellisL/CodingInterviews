#include <iostream>
#include <vector>
#include <algorithm>

int maxValue(const std::vector<std::vector<int>>& vSet);
void test(const char* vpTestName, const std::vector<std::vector<int>>& vSet, int vExpect);

int main()
{
	{
		std::vector<std::vector<int>> Set = {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 }
		};

		test("Test1", Set, 29);
	}

	{
		std::vector<std::vector<int>> Set = {
			{ 1, 10, 3, 8 },
			{ 12, 2, 9, 6 },
			{ 5, 7, 4, 11 },
			{ 3, 7, 16, 5 }
		};

		test("Test2", Set, 53);
	}

	{
		std::vector<std::vector<int>> Set = {
			{ 1, 10, 3, 8 }
		};

		test("Test3", Set, 22);
	}

	{
		std::vector<std::vector<int>> Set = {
			{ 1 },
			{ 12 },
			{ 5 },
			{ 3 }
		};

		test("Test4", Set, 21);
	}

	{
		std::vector<std::vector<int>> Set = {
			{ 3 }
		};

		test("Test5", Set, 3);
	}

	{
		std::vector<std::vector<int>> Set = {
			{ }
		};

		test("Test6", Set, -1);
	}

	return 0;
}

int maxValue(const std::vector<std::vector<int>>& vSet)
{
	if (vSet.size() < 1 || vSet[0].size() < 1)
		throw std::runtime_error("Invalid input!");

	auto Rows = vSet.size();
	auto Cols = vSet[0].size();
	std::vector<int> DpSet(Cols, 0);

	for (int i = 0; i < Rows; ++i)
	{
		for (int k = 0; k < Cols; ++k)
		{
			/*if (i == 0)
			{
				if (k == 0)
					DpSet[k] = vSet[i][k];
				else
					DpSet[k] = vSet[i][k] + DpSet[k - 1];
			}
			else
			{
				if (k == 0)
					DpSet[k] = DpSet[k] + vSet[i][k];
				else
					DpSet[k] = vSet[i][k] + std::max(DpSet[k - 1], DpSet[k]);
			}*/
			int Up = 0;
			int Left = 0;

			if (i > 0)
				Up = DpSet[k];

			if (k > 0)
				Left = DpSet[k - 1];

			DpSet[k] = vSet[i][k] + std::max(Left, Up);
		}
	}

	return *std::max_element(DpSet.begin(), DpSet.end());
}

void test(const char* vpTestName, const std::vector<std::vector<int>>& vSet, int vExpect)
{
	std::cout << vpTestName << std::endl;
	try
	{
		int Res = maxValue(vSet);
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