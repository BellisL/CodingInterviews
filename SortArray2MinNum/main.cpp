#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct SLess
{
	bool operator()(const int vLeft, const int vRight)
	{
		std::string Str1 = std::to_string(vLeft) + std::to_string(vRight);
		std::string Str2 = std::to_string(vRight) + std::to_string(vLeft);
		return strcmp(Str1.c_str(), Str2.c_str()) < 0 ? true : false;
	}
};

std::string smallestNumFrom(std::vector<int>& vSet);
void test(const char* vpTestName, std::vector<int>& vSet, const std::string& vExpect);

int main()
{
	{
		std::vector<int> Set = { 3, 5, 1, 4, 2 };
		test("Test1", Set, "12345");
	}

	{
		std::vector<int> Set = { 3, 32, 321 };
		test("Test2", Set, "321323");
	}

	{
		std::vector<int> Set = { 3, 323, 32123 };
		test("Test3", Set, "321233233");
	}

	{
		std::vector<int> Set = { 1, 11, 111 };
		test("Test4", Set, "111111");
	}

	{
		std::vector<int> Set = { 321 };
		test("Test5", Set, "321");
	}

	{
		std::vector<int> Set = { };
		test("Test6", Set, "");
	}

	{
		std::vector<int> Set = { 1, 2, 3, 4, 0 };
		test("Test7", Set, "10234");
	}

	{
		std::vector<int> Set = { 0, 1, 2, 3, 4, 0 };
		test("Test8", Set, "100234");
	}

	{
		std::vector<int> Set = { 0, 0, 0, 0};
		test("Test9", Set, "");
	}

	return 0;
}

std::string smallestNumFrom(std::vector<int>& vSet)
{
	std::string Temp;
	if (vSet.empty()) return Temp;

	std::sort(vSet.begin(), vSet.end(), SLess());
	for (const auto Num : vSet)
		std::cout << Num << "\t";
	std::cout << "\n";

	int ZeroCnt = 0;
	for (int i = 0; i < vSet.size(); ++i)
	{
		if (!vSet[i]) 
			++ZeroCnt;
		else 
			break;
	}

	if (ZeroCnt == vSet.size()) return Temp;

	if (ZeroCnt)
	{
		Temp += std::to_string(vSet[ZeroCnt]);

		for (int i = 0; i < ZeroCnt; ++i)
			Temp += std::to_string(0);

		for (int i = ZeroCnt + 1; i < vSet.size(); ++i)
			Temp += std::to_string(vSet[i]);
	}
	else
	{
		for (int i = 0; i < vSet.size(); ++i)
			Temp += std::to_string(vSet[i]);
	}

	return Temp;
}

void test(const char * vpTestName, std::vector<int>& vSet, const std::string& vExpect)
{
	std::cout << vpTestName << std::endl;

	std::string Res = std::move(smallestNumFrom(vSet));
	if (Res == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
