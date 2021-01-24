#include <iostream>
#include <vector>

bool findDuplicates(const std::vector<int>& vSet, size_t& voIndex);
void test(const std::vector<int>& vSet);

int main()
{
	std::vector<int> TestArr = { 1 };
	std::vector<int> TestArr1 = { 1, 2, 3, 5, 4 };
	std::vector<int> TestArr2 = { 1, 2, 3, 4, 4 };
	std::vector<int> TestArr3 = { 1, 1, 2, 4, 4 };
	std::vector<int> TestArr4 = { 1, 2, 2, 4, 4, 5 };

	test(TestArr);
	test(TestArr1);
	test(TestArr2);
	test(TestArr3);
	test(TestArr4);

	return 0;
}

bool findDuplicates(const std::vector<int>& vSet, size_t & voIndex)
{
	if (vSet.empty() || vSet.size() < 2) return false;

	for (const auto& Num : vSet)
	{
		if (Num < 1 || Num > vSet.size() - 1) return false;
	}

	size_t Left = 1;
	size_t Right = vSet.size() - 1;
	size_t Count;

	while (Left < Right)
	{
		size_t Mid = Left + (Right - Left) / 2;
		Count = 0;
		for (size_t i = 0; i < vSet.size(); ++i)
		{
			if (Left <= vSet[i] && vSet[i] <= Mid)
				++Count;
		}

		if (Count > Mid - Left + 1)
			Right = Mid;
		else
			Left = Mid + 1;
	}
	voIndex = Right;

	return true;
}

void test(const std::vector<int>& vSet)
{
	size_t Index;
	if (findDuplicates(vSet, Index))
		std::cout << "One of the duplicates is: " << Index << std::endl;
	else
		std::cout << "Input error!" << std::endl;
}
