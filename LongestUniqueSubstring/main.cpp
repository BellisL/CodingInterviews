#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestUniqueSubstr_1(const std::string& vStr);
int longestUniqueSubstr_2(const std::string& vStr);
void test(const char* vpTestName, const std::string& vStr, int vExpect);

int main()
{
	{
		const char* vStr = "abcacfrar";
		test("Test1", vStr, 4);
	}

	{
		const char* vStr = "acfrarabc";
		test("Test2", vStr, 4);
	}

	{
		const char* vStr = "arabcacfr";
		test("Test3", vStr, 4);
	}

	{
		const char* vStr = "aaaa";
		test("Test4", vStr, 1);
	}

	{
		const char* vStr = "abcdefg";
		test("Test5", vStr, 7);
	}

	{
		const char* vStr = "aaabbbccc";
		test("Test6", vStr, 2);
	}

	{
		const char* vStr = "abcdcba";
		test("Test7", vStr, 4);
	}

	{
		const char* vStr = "abcdaef";
		test("Test8", vStr, 6);
	}

	{
		const char* vStr = "a";
		test("Test9", vStr, 1);
	}

	{
		const char* vStr = "";
		test("Test10", vStr, 0);
	}

	return 0;
}

int longestUniqueSubstr_1(const std::string & vStr)
{
	if(vStr.empty()) return 0;

	auto Length = vStr.length();
	//实际上只需要保存当前和前一位置的最大长度，不需要dp数组
	std::vector<int> Dp(Length, 0);

	for (int i = 0; i < Length; ++i)
	{
		if (i == 0) Dp[i] = 1;
		else
		{
			//每次都要向前扫描，效率较低，可以用数组保存元素上一次出现的位置
			bool isDup = false;
			int k = i - 1;
			for (; k >= i - Dp[i - 1]; --k)
			{
				if (vStr[i] == vStr[k])
				{
					isDup = true;
					break;
				}
			}

			if (isDup)
				Dp[i] = i - k;
			else
				Dp[i] = Dp[i - 1] + 1;
		}
	}

	return *std::max_element(Dp.begin(), Dp.end());
}

int longestUniqueSubstr_2(const std::string & vStr)
{
	if (vStr.empty()) return 0;

	std::vector<int> Pos(26, -1);
	int CurLen = 0;
	int MaxLen = 0;

	for (int i = 0; i < vStr.length(); ++i)
	{
		int PreIndex = Pos[vStr[i] - 'a'];
		if (PreIndex == -1 || i - PreIndex > CurLen)
			++CurLen;
		else
			CurLen = i - PreIndex;

		Pos[vStr[i] - 'a'] = i;
		if (CurLen > MaxLen)
			MaxLen = CurLen;
	}

	return MaxLen;
}

void test(const char * vpTestName, const std::string & vStr, int vExpect)
{
	std::cout << vpTestName << std::endl;
	int Res1 = longestUniqueSubstr_1(vStr);
	int Res2 = longestUniqueSubstr_2(vStr);
	if (Res1 == vExpect && Res2 == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
