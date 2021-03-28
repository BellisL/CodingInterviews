#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string longestPlindrome_1(const std::string& vStr);
std::string longestPlindrome_2(const std::string& vStr);
std::string longestPlindrome_3(const std::string& vStr);
int expend(const std::string& vStr, int vLeft, int vRight);
void test(const char* vpTestName, const std::string& vStr, const std::string& vExpect);

int main()
{
	{
		std::string Str = "aabac";
		std::string ExpectStr = "aba";
		test("Test1", Str, ExpectStr);
	}

	{
		std::string Str = "";
		std::string ExpectStr = "";
		test("Test2", Str, ExpectStr);
	}

	{
		std::string Str = "aabaa";
		std::string ExpectStr = "aabaa";
		test("Test3", Str, ExpectStr);
	}

	{
		std::string Str = "a";
		std::string ExpectStr = "a";
		test("Test4", Str, ExpectStr);
	}

	{
		std::string Str = "abaaababa";
		std::string ExpectStr = "abaaaba";
		test("Test5", Str, ExpectStr);
	}

	return 0;
}

std::string longestPlindrome_1(const std::string & vStr)
{
	if (vStr.empty()) return "";

	std::string TempStr = "$#";
	for (size_t i = 0; i < vStr.size(); i++)
	{
		TempStr += vStr[i];
		TempStr += "#";
	}

	std::vector<int> Record(TempStr.size(), 0);
	size_t MaxLen = 1, MaxPoint = 0;
	size_t MidPos = 0, Right = 0;

	for (size_t i = 1; i < TempStr.size(); i++)
	{
		Record[i] = Right > i ? std::min(Record[2 * MidPos - i], static_cast<int>(Right - i)) : 1;

		while (TempStr[i + Record[i]] == TempStr[i - Record[i]])
		{
			Record[i]++;
		}

		if (Right < i + Record[i])
		{
			Right = Record[i] + i;
			MidPos = i;
		}

		if (MaxLen < Record[i])
		{
			MaxLen = Record[i];
			MaxPoint = i;
		}
	}

	return vStr.substr((MaxPoint - MaxLen) / 2, MaxLen - 1);
}

std::string longestPlindrome_2(const std::string & vStr)
{
	if (vStr.size() <= 1) return vStr;

	auto Length = vStr.size() - 1;
	bool** dp = new bool*[Length + 1];
	for (int i = 0; i <= Length; ++i)
		dp[i] = new bool[Length + 1];

	for (int i = 0; i <= Length; ++i)
		dp[i][i] = true;

	int MaxLen = 1;
	int Start = 0;
	for (int i = 1; i <= Length; ++i)
	{
		for (int k = 0; k < i; ++k)
		{
			if (vStr[i] != vStr[k])
				dp[k][i] = false;
			else
			{
				if (i - k < 3)
					dp[k][i] = true;
				else
					dp[k][i] = dp[k + 1][i - 1];
			}

			if (dp[k][i] && i - k + 1 > MaxLen)
			{
				MaxLen = i - k + 1;
				Start = k;
			}
		}
	}

	for (int i = 0; i < Length + 1; ++i)
		delete[] dp[i];

	return vStr.substr(Start, MaxLen);
}

std::string longestPlindrome_3(const std::string & vStr)
{
	if (vStr.size() <= 1) return vStr;

	int Start = 0;
	int MaxLen = 1;
	for (int i = 0; i < vStr.size(); ++i)
	{
		auto Len1 = expend(vStr, i, i);
		auto Len2 = expend(vStr, i, i + 1);

		auto TempLen = std::max(Len1, Len2);
		if (MaxLen < TempLen)
		{
			MaxLen = TempLen;
			Start = i - (MaxLen - 1) / 2;
		}
	}

	return vStr.substr(Start, MaxLen);
}

int expend(const std::string & vStr, int vLeft, int vRight)
{
	while (vLeft >= 0 && vRight < vStr.size() && vStr[vLeft] == vStr[vRight])
	{
		--vLeft;
		++vRight;
	}

	return vRight - vLeft - 1;
}

void test(const char * vpTestName, const std::string & vStr, const std::string & vExpect)
{
	std::cout << vpTestName << std::endl;

	auto LP1 = longestPlindrome_1(vStr);
	auto LP2 = longestPlindrome_2(vStr);
	auto LP3 = longestPlindrome_3(vStr);
	if (LP1 == vExpect && LP2 == vExpect && LP3 == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
