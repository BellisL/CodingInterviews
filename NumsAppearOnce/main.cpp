#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> getNumsAppearOnce(const std::vector<int>& vSet);
int getFirstOne(int vNum);
bool checkBit(int vNum, int vIndex);
void test(const char* vpTestName, const std::vector<int>& vSet, const std::pair<int ,int>& vPair);

int main()
{
	{
		std::vector<int> Set = { 2, 4, 3, 6, 3, 2, 5, 5 };
		test("Test1", Set, { 4, 6 });
	}

	{
		std::vector<int> Set = { 4, 6 };
		test("Test2", Set, { 4, 6 });
	}

	{
		std::vector<int> Set = { 4, 6, 1, 1, 1, 1 };
		test("Test3", Set, { 4, 6 });
	}

	return 0;
}

std::pair<int, int> getNumsAppearOnce(const std::vector<int>& vSet)
{
	if (vSet.size() < 2) throw std::runtime_error("Invalid input!");

	int Or = 0;
	for (const auto& Num : vSet)
		Or ^= Num;

	int IndexofFirstOne = getFirstOne(Or);

	std::pair<int, int> Pairs;
	for (const auto& Num : vSet)
	{
		if (checkBit(Num, IndexofFirstOne))
			Pairs.first ^= Num;
		else
			Pairs.second ^= Num;
	}

	return Pairs;
}

int getFirstOne(int vNum)
{
	int N = 0;
	while ((vNum & 1) == 0 && N < 8 * sizeof(int))
	{
		vNum = vNum >> 1;
		++N;
	}

	return N;
}

bool checkBit(int vNum, int vIndex)
{
	vNum = vNum >> vIndex;
	return vNum & 1;
}

void test(const char * vpTestName, const std::vector<int>& vSet, const std::pair<int, int>& vPair)
{
	std::cout << vpTestName << std::endl;

	try
	{
		auto Pair = getNumsAppearOnce(vSet);
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
