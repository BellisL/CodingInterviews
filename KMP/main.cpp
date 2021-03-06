#include <iostream>
#include <string>
#include <vector>

void generateNext(const std::string& vPattern, std::vector<int>& vNext);
int search(const std::string& vStr, const std::string& vPattern);
int search_simple(const std::string& vStr, const std::string& vPattern);
void test(const char* vpTestName, const std::string& vStr, const std::string& vPattern, int vExpect);

int main()
{
	{
		std::string Str = "aabaabaaf";
		std::string Pat = "aabaaf";
		test("Test1", Str, Pat, 3);
	}

	return 0;
}

void generateNext(const std::string & vPattern, std::vector<int>& vNext)
{
	int pre = 0;
	vNext[0] = 0;
	for (int i = 1; i < vNext.size(); ++i)
	{
		while (pre > 0 && vPattern[i] != vPattern[pre])
			pre = vNext[pre - 1];

		if (vPattern[i] == vPattern[pre])
		{
			++pre;
		}
		vNext[i] = pre;
	}
}

int search(const std::string & vStr, const std::string & vPattern)
{
	std::vector<int> NextSet(vPattern.size(), -1);
	generateNext(vPattern, NextSet);

	int Tar = 0;
	int Pos = 0;

	while (Tar < vStr.size())
	{
		if (vStr[Tar] == vPattern[Pos])
		{
			++Tar;
			++Pos;
		}
		else if (Pos != 0)
			Pos = NextSet[Pos - 1];
		else
			++Tar;

		if (Pos == vPattern.size())
			return Tar - Pos;
	}

	return -1;
}

int search_simple(const std::string & vStr, const std::string & vPattern)
{
	if (vStr.size() < vPattern.size()) return -1;

	int i = 0, k = 0;
	while (i < vStr.size() && k < vPattern.size())
	{
		if (vStr[i] == vPattern[k])
		{
			++i;
			++k;
		}
		else
		{
			i = i - k + 1;
			k = 0;
		}
	}

	if (k == vPattern.size())
		return i - k;
	else
		return -1;
}

void test(const char * vpTestName, const std::string & vStr, const std::string & vPattern, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Res1 = search(vStr, vPattern);
	auto Res2 = search_simple(vStr, vPattern);
	if (Res1 == vExpect && Res2 == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
