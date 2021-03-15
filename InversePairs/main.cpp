#include <iostream>
#include <vector>

int inversePairs(std::vector<int>& vSet);
int inversePairsCore(std::vector<int>& vSet, std::vector<int>& vAssistSet, int vStart, int vEnd);
void test(const char* vpTestName, std::vector<int>& vSet, int vExpect);

int main()
{
	{
		std::vector<int> Set = { 1, 2, 3, 4, 7, 6, 5 };
		test("Test1", Set, 3);
	}

	{
		std::vector<int> Set = { 6, 5, 4, 3, 2, 1 };
		test("Test2", Set, 15);
	}

	{
		std::vector<int> Set = { 1, 2, 3, 4, 5, 6 };
		test("Test3", Set, 0);
	}

	{
		std::vector<int> Set = { 1 };
		test("Test4", Set, 0);
	}

	{
		std::vector<int> Set = { 1, 2 };
		test("Test5", Set, 0);
	}

	{
		std::vector<int> Set = { 3, 2 };
		test("Test6", Set, 1);
	}

	{
		std::vector<int> Set = { 1, 2, 1, 2, 1 };
		test("Test7", Set, 3);
	}

	{
		std::vector<int> Set = { };
		test("Test7", Set, 0);
	}

	return 0;
}

int inversePairs(std::vector<int>& vSet)
{
	if (vSet.empty()) return 0;

	std::vector<int> AssistSet(vSet);

	return inversePairsCore(vSet, AssistSet, 0, vSet.size() - 1);
}

int inversePairsCore(std::vector<int>& vSet, std::vector<int>& vAssistSet, int vStart, int vEnd)
{
	if (vStart == vEnd) return 0;

	int Length = (vEnd - vStart) / 2;
	int CntLeft = inversePairsCore(vAssistSet, vSet, vStart, vStart + Length);
	int CntRight = inversePairsCore(vAssistSet, vSet, vStart + Length + 1, vEnd);

	int LeftEnd = vStart + Length;
	int RightEnd = vEnd;
	int CopyIndex = vEnd;
	int Cnt = 0;

	while (LeftEnd >= vStart && RightEnd >= vStart + Length + 1)
	{
		if (vSet[LeftEnd] > vSet[RightEnd])
		{
			Cnt += RightEnd - vStart - Length;
			vAssistSet[CopyIndex--] = vSet[LeftEnd--];
		}
		else
		{
			vAssistSet[CopyIndex--] = vSet[RightEnd--];
		}
	}

	for(; LeftEnd >= vStart; )
		vAssistSet[CopyIndex--] = vSet[LeftEnd--];

	for(; RightEnd >= vStart + Length + 1; )
		vAssistSet[CopyIndex--] = vSet[RightEnd--];

	return Cnt + CntLeft + CntRight;
}

void test(const char* vpTestName, std::vector<int>& vSet, int vExpect)
{
	std::cout << vpTestName << std::endl;

	int Res = inversePairs(vSet);
	if (Res == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}