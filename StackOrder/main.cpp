#include <stack>
#include <vector>
#include <iostream>

template<typename T>
bool isPopOrder(const std::vector<T>& vPush, const std::vector<T>& vPop);

template<typename T>
void test(const char* vpTestName, const std::vector<T>& vPush, const std::vector<T>& vPop, bool vExpect);

int main()
{
	{
		std::vector<int> PushOrder = { 1, 2, 3, 4, 5 };
		std::vector<int> PopOrder = { 4, 5, 3, 2, 1 };

		test("Test1", PushOrder, PopOrder, true);
	}

	{
		std::vector<int> PushOrder = { 1, 2, 3, 4, 5 };
		std::vector<int> PopOrder = { 3, 5, 4, 2, 1 };

		test("Test2", PushOrder, PopOrder, true);
	}

	{
		std::vector<int> PushOrder = { 1, 2, 3, 4, 5 };
		std::vector<int> PopOrder = { 4, 3, 5, 1, 2 };

		test("Test3", PushOrder, PopOrder, false);
	}

	{
		std::vector<int> PushOrder = { 1, 2, 3, 4, 5 };
		std::vector<int> PopOrder = { 3, 5, 4, 1, 2 };

		test("Test4", PushOrder, PopOrder, false);
	}

	{
		std::vector<int> PushOrder = { 1 };
		std::vector<int> PopOrder = { 3 };

		test("Test5", PushOrder, PopOrder, false);
	}

	{
		std::vector<int> PushOrder = { 1 };
		std::vector<int> PopOrder = { 1 };

		test("Test6", PushOrder, PopOrder, true);
	}

	{
		std::vector<int> PushOrder = { };
		std::vector<int> PopOrder = { };

		test("Test7", PushOrder, PopOrder, false);
	}

	return 0;
}

template<typename T>
bool isPopOrder(const std::vector<T>& vPush, const std::vector<T>& vPop)
{
	if (vPush.empty() || vPop.empty()) return false;
	if (vPush.size() != vPop.size()) return false;

	bool IsPossible = false;
	std::stack<T> Stack;
	size_t PushIndex = 0;
	size_t PopIndex = 0;

	while (PopIndex != vPop.size())
	{
		if (!Stack.empty() && Stack.top() == vPop[PopIndex])
		{
			Stack.pop();
			++PopIndex;
		}
		else
		{
			if (PushIndex < vPush.size())
				Stack.push(vPush[PushIndex++]);
			else
				break;
		}
	}

	if (PopIndex == vPop.size()) IsPossible = true;

	return IsPossible;
}

template<typename T>
void test(const char * vpTestName, const std::vector<T>& vPush, const std::vector<T>& vPop, bool vExpect)
{
	std::cout << vpTestName << "\n";

	if (isPopOrder(vPush, vPop) == vExpect)
		std::cout << "PASSED.";
	else
		std::cout << "FAILED.";

	std::cout << std::endl;
}
