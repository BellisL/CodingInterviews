#include <iostream>
#include <vector>
#include <string>

void reorderOddEven(std::vector<int>& vSet);
bool isEven(int vNum);
void test(const std::string& vpTestName, std::vector<int>& vSet);

int main()
{
	{
		std::vector<int> Num = { 1, 2, 3, 4, 5, 6, 7 };
		test("Test1", Num);
	}

	{
		std::vector<int> Num = { 2, 4, 6, 1, 3, 5, 7 };
		test("Test2", Num);
	}

	{
		std::vector<int> Num = { 1, 3, 5, 7, 2, 4, 6 };
		test("Test3", Num);
	}

	{
		std::vector<int> Num = { 1 };
		test("Test4", Num);
	}

	{
		std::vector<int> Num = { 2 };
		test("Test5", Num);
	}

	{
		std::vector<int> Num = { };
		test("Test6", Num);
	}

	return 0;
}

void reorderOddEven(std::vector<int>& vSet)
{
	if (vSet.empty()) return;

	int Left = 0;
	int Right = vSet.size() - 1;
	while (Left < Right)
	{
		while (Left < Right && !isEven(vSet[Left]))
			++Left;

		while (Left < Right && isEven(vSet[Right]))
			--Right;

		if (Left < Right)
		{
			int Temp = vSet[Left];
			vSet[Left] = vSet[Right];
			vSet[Right] = Temp;
		}
	}
}

bool isEven(int vNum)
{
	//return vNum / 2 == 0;
	return (vNum & 1) == 0;
}

void test(const std::string & vpTestName, std::vector<int>& vSet)
{
	std::cout << vpTestName << ": ";
	for (const auto Num : vSet)
		std::cout << Num << "\t";
	std::cout << std::endl;

	reorderOddEven(vSet);
	std::cout << "After reorder: ";
	for (const auto Num : vSet)
		std::cout << Num << "\t";
	std::cout << std::endl << std::endl;;
}
