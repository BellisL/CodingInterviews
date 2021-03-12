#include <iostream>
#include <vector>

int findGreatest(const std::vector<int>& vSet);
void test(const char* vpTestName, const std::vector<int>& vSet, int vExpect);

int main()
{
	{
		std::vector<int> Set = { 1, -2, 3, 10, -4, 7, 2, -5 };
		test("Test1", Set, 18);
	}

	{
		std::vector<int> Set = { -2, -8, -1, -5, -9 };
		test("Test2", Set, -1);
	}

	{
		std::vector<int> Set = { 2, 8, 1, 5, 9 };
		test("Test3", Set, 25);
	}

	{
		std::vector<int> Set = { };
		test("Test4", Set, 0);
	}

	return 0;
}

int findGreatest(const std::vector<int>& vSet)
{
	if (vSet.empty()) throw std::runtime_error("Invalid input!");

	int CurSum = 0;
	int GreatestSum = INT_MIN;

	for (int i = 0; i < vSet.size(); ++i)
	{
		if (CurSum <= 0)
			CurSum = vSet[i];
		else
			CurSum += vSet[i];

		if (CurSum > GreatestSum)
			GreatestSum = CurSum;
	}

	return GreatestSum;
}

void test(const char * vpTestName, const std::vector<int>& vSet, int vExpect)
{
	std::cout << vpTestName << std::endl;

	try
	{
		int Res = findGreatest(vSet);
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
