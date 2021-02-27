#include <iostream>
#include <vector>
#include <exception>

int min(const std::vector<int>& vSet);
void testSearchMin(const std::vector<int>& vSet);

int main()
{
	{
		std::vector<int> Nums = { 5,6,7,8,1,2,3,4 };
		testSearchMin(Nums);
	}

	{
		std::vector<int> Nums = { 5,5,7,8,1,1,2,2,3,4,5 };
		testSearchMin(Nums);
	}

	{
		std::vector<int> Nums = { 1,0,1,1,1 };
		testSearchMin(Nums);
	}

	{
		std::vector<int> Nums = { 1,1,1,0,1 };
		testSearchMin(Nums);
	}

	{
		std::vector<int> Nums = { 1,1,1,1,1 };
		testSearchMin(Nums);
	}

	{
		std::vector<int> Nums = { 1 };
		testSearchMin(Nums);
	}

	return 0;
}

int min(const std::vector<int>& vSet)
{
	if (vSet.empty()) throw std::runtime_error("There is no data in given set.");

	int Low = 0;
	int High = vSet.size() - 1;

	if (Low == High || vSet[Low] < vSet[High]) return vSet[Low];

	while (Low < High)
	{
		while (Low + 1 <= High && vSet[Low] == vSet[Low + 1]) ++Low;
		while (High - 1 >= 0 && vSet[High] == vSet[High - 1]) --High;

		if (High - Low == 1) break;

		int Mid = Low + (High - Low) / 2;
		if (vSet[Mid] > vSet[Low]) Low = Mid;
		if (vSet[Mid] < vSet[High]) High = Mid;
	}

	return vSet[High];
}

void testSearchMin(const std::vector<int>& vSet)
{
	std::cout << "Original array:\n";
	for (const auto Num : vSet)
	{
		std::cout << Num << " ";
	}
	std::cout << std::endl;

	try
	{
		int Res = min(vSet);
		std::cout << Res << std::endl;
	}
	catch (std::runtime_error E)
	{
		std::cout << E.what() << std::endl;
	}

	return;
}
