#include "BinaryTree.h"
#include <vector>

bool verifySequenceOfBST(const std::vector<int>& vSet, int vStart, int vLength);
void test(const char* vpTestName, const std::vector<int>& vSet, bool vExpect);

int main()
{
	{
		std::vector<int> Set = { 4, 8, 6, 12, 16, 14, 10 };
		test("Test1", Set, true);
	}

	{
		std::vector<int> Set = { 4, 6, 7, 5 };
		test("Test2", Set, true);
	}

	{
		std::vector<int> Set = { 1, 2, 3, 4, 5 };
		test("Test3", Set, true);
	}

	{
		std::vector<int> Set = { 5, 4, 3, 2, 1 };
		test("Test4", Set, true);
	}

	{
		std::vector<int> Set = { 5 };
		test("Test5", Set, true);
	}

	{
		std::vector<int> Set = { 7, 4, 6, 5 };
		test("Test6", Set, false);
	}

	{
		std::vector<int> Set = { 4, 6, 12, 8, 16, 14, 10 };
		test("Test7", Set, false);
	}

	{
		std::vector<int> Set = { };
		test("Test8", Set, false);
	}

	return 0;
}

bool verifySequenceOfBST(const std::vector<int>& vSet, int vStart, int vLength)
{
	if (vSet.empty()) return false;

	int Root = vSet[vStart + vLength];

	int i = vStart;
	for (; i < vStart + vLength; ++i)
	{
		if (vSet[i] > Root)
			break;
	}

	int k = i;
	for (; k < vStart + vLength; ++k)
	{
		if (vSet[k] < Root)
			return false;
	}

	bool Left = true;
	if (i > vStart)
		Left = verifySequenceOfBST(vSet, vStart, i - vStart - 1);

	bool Right = true;
	if (k > i)
		Right = verifySequenceOfBST(vSet, i, k - i - 1);

	return Left && Right;
}

void test(const char * vpTestName, const std::vector<int>& vSet, bool vExpect)
{
	std::cout << vpTestName << ":";
	if (vExpect == verifySequenceOfBST(vSet, 0, vSet.size() - 1))
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
