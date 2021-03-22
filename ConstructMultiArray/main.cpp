#include <iostream>
#include <vector>

void constructArray(const std::vector<int>& vSrcSet, std::vector<int>& vDstSet);
void test(const char* vpTestName, const std::vector<int>& vSrcSet, std::vector<int>& vDstSet, const std::vector<int>& vExpectSet);
bool isEqual(std::vector<int>& vDstSet, const std::vector<int>& vExpectSet);

int main()
{
	{
		std::vector<int> SrcSet = { 1, 2, 3, 4, 5 };
		std::vector<int> DstSet(SrcSet.size(), 0);
		std::vector<int> ExpectSet = { 120, 60, 40, 30, 24 };
		test("Test1", SrcSet, DstSet, ExpectSet);
	}

	{
		std::vector<int> SrcSet = { 1, 2, 0, 4, 5 };
		std::vector<int> DstSet(SrcSet.size(), 0);
		std::vector<int> ExpectSet = { 0, 0, 40, 0, 0 };
		test("Test2", SrcSet, DstSet, ExpectSet);
	}

	{
		std::vector<int> SrcSet = { 1, 2, 0, 4, 0 };
		std::vector<int> DstSet(SrcSet.size(), 0);
		std::vector<int> ExpectSet = { 0, 0, 0, 0, 0 };
		test("Test3", SrcSet, DstSet, ExpectSet);
	}

	{
		std::vector<int> SrcSet = { 1, -2, 3, -4, 5 };
		std::vector<int> DstSet(SrcSet.size(), 0);
		std::vector<int> ExpectSet = { 120, -60, 40, -30, 24 };
		test("Test4", SrcSet, DstSet, ExpectSet);
	}

	{
		std::vector<int> SrcSet = { 1, -2 };
		std::vector<int> DstSet(SrcSet.size(), 0);
		std::vector<int> ExpectSet = { -2, 1 };
		test("Test5", SrcSet, DstSet, ExpectSet);
	}

	return 0;
}

void constructArray(const std::vector<int>& vSrcSet, std::vector<int>& vDstSet)
{
	if (vSrcSet.size() != vDstSet.size() || vSrcSet.size() < 1) return;

	vDstSet[0] = 1;
	for (int i = 1; i < vSrcSet.size(); ++i)
	{
		vDstSet[i] = vDstSet[i - 1] * vSrcSet[i - 1];
	}

	int Temp = 1;
	for (int i = vSrcSet.size() - 2; i >= 0; --i)
	{
		Temp *= vSrcSet[i + 1];
		vDstSet[i] *= Temp;
	}
}

void test(const char * vpTestName, const std::vector<int>& vSrcSet, std::vector<int>& vDstSet, const std::vector<int>& vExpectSet)
{
	std::cout << vpTestName << std::endl;

	constructArray(vSrcSet, vDstSet);
	if (isEqual(vDstSet, vExpectSet))
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}

bool isEqual(std::vector<int>& vDstSet, const std::vector<int>& vExpectSet)
{
	if(vDstSet.size() != vExpectSet.size())
		return false;

	for (int i = 0; i < vDstSet.size(); ++i)
	{
		if (vDstSet[i] != vExpectSet[i])
			return false;
	}

	return true;
}
