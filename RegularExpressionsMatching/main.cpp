#include <iostream>

bool match(const char* vStr, const char* vPattern);
bool matchCore(const char* vStr, const char* vPattern);
void test(const char* vTestName, const char* vStr, const char* vPattern, bool vExpect);

int main()
{
	test("Test01", "", "", true);
	test("Test02", "", ".*", true);
	test("Test03", "", ".", false);
	test("Test04", "", "c*", true);
	test("Test05", "a", ".*", true);
	test("Test06", "a", "a.", false);
	test("Test07", "a", "", false);
	test("Test08", "a", ".", true);
	test("Test09", "a", "ab*", true);
	test("Test10", "a", "ab*a", false);
	test("Test11", "aa", "aa", true);
	test("Test12", "aa", "a*", true);
	test("Test13", "aa", ".*", true);
	test("Test14", "aa", ".", false);
	test("Test15", "ab", ".*", true);
	test("Test16", "ab", ".*", true);
	test("Test17", "aaa", "aa*", true);
	test("Test18", "aaa", "aa.a", false);
	test("Test19", "aaa", "a.a", true);
	test("Test20", "aaa", ".a", false);
	test("Test21", "aaa", "a*a", true);
	test("Test22", "aaa", "ab*a", false);
	test("Test23", "aaa", "ab*ac*a", true);
	test("Test24", "aaa", "ab*a*c*a", true);
	test("Test25", "aaa", ".*", true);
	test("Test26", "aab", "c*a*b", true);
	test("Test27", "aaca", "ab*a*c*a", true);
	test("Test28", "aaba", "ab*a*c*a", false);
	test("Test29", "bbbba", ".*a*a", true);
	test("Test30", "bcbbabab", ".*a*a", false);

	return 0;
}

bool match(const char* vStr, const char* vPattern)
{
	if(vStr == nullptr || vPattern == nullptr)
		return false;

	return matchCore(vStr, vPattern);
}

bool matchCore(const char * vStr, const char * vPattern)
{
	if (*vStr == '\0' && *vPattern == '\0')
		return true;

	if (*vStr != '\0' && *vPattern == '\0')
		return false;

	//模式未到结尾时，需要先判断模式的下一个字符
	if (*(vPattern + 1) == '*')
	{
		if (*vStr == *vPattern || (*vPattern == '.' && *vStr != '\0'))
			return matchCore(vStr + 1, vPattern + 2) || matchCore(vStr + 1, vPattern) || matchCore(vStr, vPattern + 2);
		else
			return matchCore(vStr, vPattern + 2);
	}

	if (*vStr == *vPattern || (*vPattern == '.' && *vStr != '\0'))
		return matchCore(vStr + 1, vPattern + 1);

	return false;
}

void test(const char * vTestName, const char * vStr, const char * vPattern, bool vExpect)
{
	if (vTestName)
		std::cout << vTestName << ": ";

	if (match(vStr, vPattern) == vExpect)
		std::cout << "PASSED." << std::endl;
	else
		std::cout << "FAILED." << std::endl;
}
