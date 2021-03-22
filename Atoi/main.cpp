#include <iostream>

enum EStatus {EInValid = 0, EValid};
int g_Status = EStatus::EValid;

int myAtoi(const char* vStr);
long atoiCore(const char* vDigit, bool vIsMinus);
void test(const char* vpTestName, const char* vStr, bool vIsNum, int vExpect);;

int main()
{
	test("Test1", nullptr, false, 0);
	test("Test2", "", false, 0);

	test("Test3", "123", true, 123);
	test("Test4", "+123", true, 123);
	test("Test5", "-123", true, -123);

	test("Test6", "1a23", false, 0);

	test("Test7", "+0", true, 0);
	test("Test8", "-0", true, 0);

	test("Test9", "+2147483647", true, INT_MAX);
	test("Test10", "-2147483647", true, -2147483647);
	test("Test11", "+2147483648", false, 0);

	test("Test12", "-2147483648", true, INT_MIN);
	test("Test13", "+2147483649", false, 0);
	test("Test14", "-2147483649", false, 0);

	test("Test15", "+", false, 0);
	test("Test16", "-", false, 0);

	return 0;
}

int myAtoi(const char * vStr)
{
	long Res = 0;
	g_Status = EStatus::EInValid;

	if (vStr != nullptr && *vStr != '\0')
	{
		bool IsMinus = false;
		if (*vStr == '+')
			++vStr;
		else if (*vStr == '-')
		{
			++vStr;
			IsMinus = true;
		}

		if (*vStr != '\0')
			Res = atoiCore(vStr, IsMinus);
	}

	return static_cast<int>(Res);
}

long atoiCore(const char * vDigit, bool vIsMinus)
{
	long Num = 0;

	while (*vDigit != '\0')
	{
		if (*vDigit >= '0' && *vDigit <= '9')
		{
			int Flag = vIsMinus ? -1 : 1;
			Num = 10 * Num + Flag * (*vDigit - '0');

			if (!vIsMinus && Num > 0x7fffffff ||
				vIsMinus && Num < static_cast<int>(0x80000000))
			{
				Num = 0;
				break;
			}
			++vDigit;
		}
		else
		{
			Num = 0;
			break;
		}

		if (*vDigit == '\0')
			int g_Status = EStatus::EValid;
	}

	return Num;
}

void test(const char * vpTestName, const char * vStr, bool vIsNum, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Sum = myAtoi(vStr);
	if (vIsNum && Sum == vExpect || !vIsNum && !g_Status)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";
	
	std::cout << std::endl;
}
