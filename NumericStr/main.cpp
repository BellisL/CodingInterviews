#include <iostream>

bool isNumeric(const char * vpStr);
bool isInteger(const char ** vppStr);
bool isUnsignedInteger(const char** vppStr);
void test(const char* vpTestName, const char* vpStr, bool vExpect);

int main()
{
	test("Test1", "100", true);
	test("Test2", "123.45e+6", true);
	test("Test3", "+500", true);
	test("Test4", "5e2", true);
	test("Test5", "3.1416", true);
	test("Test6", "600.", true);
	test("Test7", "-.123", true);
	test("Test8", "-1E-16", true);
	test("Test9", "1.79769313486232E+308", true);

	printf("\n\n");

	test("Test10", "12e", false);
	test("Test11", "1a3.14", false);
	test("Test12", "1+23", false);
	test("Test13", "1.2.3", false);
	test("Test14", "+-5", false);
	test("Test15", "12e+5.4", false);
	test("Test16", ".", false);
	test("Test17", ".e1", false);
	test("Test18", "e1", false);
	test("Test19", "+.", false);
	test("Test20", "", false);
	test("Test21", nullptr, false);

	return 0;
}

bool isNumeric(const char * vpStr)
{
	if (!vpStr) return false;

	std::cout << vpStr << std::endl;

	bool IsNumeric = isInteger(&vpStr);

	if (*vpStr == '.')
	{
		++vpStr;
		//下面的或运算要把已知的放在后面
		IsNumeric = isUnsignedInteger(&vpStr) || IsNumeric;
	}

	if (*vpStr == 'e' || *vpStr == 'E')
	{
		++vpStr;
		IsNumeric = IsNumeric && isInteger(&vpStr);
	}

	return IsNumeric && *vpStr == '\0';
}

bool isInteger(const char ** vppStr)
{
	if (**vppStr == '+' || **vppStr == '-')
		++(*vppStr);
	return isUnsignedInteger(vppStr);
}

bool isUnsignedInteger(const char ** vppStr)
{
	const char* vpStart = *vppStr;
	while (**vppStr != '\0' && **vppStr >= '0' && **vppStr <= '9')
		++(*vppStr);
	return *vppStr > vpStart;
}

void test(const char * vpTestName, const char * vpStr, bool vExpect)
{
	if (vpTestName)
		std::cout << vpTestName << ": ";

	if (isNumeric(vpStr) == vExpect)
		std::cout << "PASSED." << std::endl;
	else
		std::cout << "FAILED." << std::endl;
}
