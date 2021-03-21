#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxInSlidingWnd(const std::vector<int>& vSet, int vWndSz);
void test(const char* vpTestName, const std::vector<int>& vSet, int vWndSz, const std::vector<int>& vExpectSet);

int main()
{
	{
		std::vector<int> Set = { 1, 3, -1, -3, 5, 3, 6, 7 };
		std::vector<int> MaxSet = { 3, 3, 5, 5, 6, 7 };
		test("Test1", Set, 3, MaxSet);
	}

	{
		std::vector<int> Set = { 1, 3, 5, 7, 9, 11, 13, 15 };
		std::vector<int> MaxSet = { 7, 9, 11, 13, 15 };
		test("Test2", Set, 4, MaxSet);
	}

	{
		std::vector<int> Set = { 2, 3, 4, 2, 6, 2, 5, 1 };
		std::vector<int> MaxSet = { 4, 4, 6, 6, 6, 5 };
		test("Test3", Set, 3, MaxSet);
	}

	{
		std::vector<int> Set = { 16, 14, 12, 10, 8, 6, 4 };
		std::vector<int> MaxSet = { 16, 14, 12 };
		test("Test4", Set, 5, MaxSet);
	}

	{
		std::vector<int> Set = { 10, 14, 12, 11 };
		std::vector<int> MaxSet = { 10, 14, 12, 11 };
		test("Test5", Set, 1, MaxSet);
	}

	{
		std::vector<int> Set = { 10, 14, 12, 11 };
		std::vector<int> MaxSet = { 14 };
		test("Test6", Set, 4, MaxSet);
	}

	{
		std::vector<int> Set = { 10, 14, 12, 11 };
		std::vector<int> MaxSet = {  };
		test("Test7", Set, 0, MaxSet);
	}

	{
		std::vector<int> Set = { 10, 14, 12, 11 };
		std::vector<int> MaxSet = {  };
		test("Test8", Set, 5, MaxSet);
	}

	{
		std::vector<int> Set = {  };
		std::vector<int> MaxSet = {  };
		test("Test8", Set, 5, MaxSet);
	}

	return 0;
}

std::vector<int> maxInSlidingWnd(const std::vector<int>& vSet, int vWndSz)
{
	if(vSet.empty() || vWndSz == 0 || vSet.size() < vWndSz)
		return std::vector<int>();

	std::deque<int> IndexQ;
	std::vector<int> MaxSet;
	for (int i = 0; i < vWndSz; ++i)
	{
		if (!IndexQ.empty() && vSet[i] >= vSet[IndexQ.back()])
			IndexQ.pop_back();
		IndexQ.push_back(i);///注意这里IndexQ中一开始就可能有多个元素
	}

	for (int i = vWndSz; i < vSet.size(); ++i)
	{
		MaxSet.push_back(vSet[IndexQ.front()]);

		while (!IndexQ.empty() && vSet[i] >= vSet[IndexQ.back()])
			IndexQ.pop_back();

		//这里判断队列最前端元素是否滑出窗口
		if (!IndexQ.empty() && IndexQ.front() <= i - vWndSz)
			IndexQ.pop_front();

		IndexQ.push_back(i);
	}
	MaxSet.push_back(vSet[IndexQ.front()]);

	return MaxSet;
}

void test(const char * vpTestName, const std::vector<int>& vSet, int vWndSz, const std::vector<int>& vExpectSet)
{
	std::cout << vpTestName << std::endl;

	auto MaxSet = maxInSlidingWnd(vSet, vWndSz);
	auto Iter1 = MaxSet.begin();
	auto Iter2 = vExpectSet.begin();
	while (Iter1 < MaxSet.end() && Iter2 < vExpectSet.end())
	{
		if (*Iter1 != *Iter2) break;
		++Iter1;
		++Iter2;
	}

	if (Iter1 == MaxSet.end() && Iter2 == vExpectSet.end())
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
