#include <iostream>

//https://leetcode-cn.com/problems/number-of-digit-one/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-50/
int numofOne_1(int vN);
int numofOne_2(int vN);
void test(const char* vpTestName, int vN, int vExpect);

int main()
{
	test("Test1", 1, 1);
	test("Test2", 5, 1);
	test("Test3", 10, 2);
	test("Test4", 55, 16);
	test("Test5", 99, 20);
	test("Test6", 10000, 4001);
	test("Test7", 21345, 18821);
	test("Test8", 0, 0);

	return 0;
}

int numofOne_1(int vN)
{
	if (vN < 0) throw std::runtime_error("Invalid input!");

	int Cnt = 0, Base = 1;

	int High = vN / 10, Cur = vN % 10, Low = 0;
	while (High || Cur)
	{
		if(Cur == 0)
			Cnt += High * Base;
		else if (Cur == 1)
			Cnt += High * Base + Low + 1;
		else
			Cnt += (High + 1) * Base;

		Low += Cur * Base;
		Cur = High % 10;
		High /= 10;
		Base *= 10;
	}
	
	return Cnt;
}

int numofOne_2(int vN)
{
	int Cnt = 0;
	for (int i = 1; i <= vN; i *= 10)
	{
		int Low = vN % i;
		int HighCur = vN / i;
		int Cur = HighCur % 10;
		int High = HighCur / 10;

		Cnt += High * i;
		if (Cur > 1)
			Cnt += i;
		if (Cur == 1)
			Cnt += Low + 1;

		if (!High) break;
	}

	return Cnt;
}

void test(const char * vpTestName, int vN, int vExpect)
{
	std::cout << vpTestName << std::endl;

	try
	{
		int Res = numofOne_1(vN);
		if (Res == vExpect)
			std::cout << "PASSED.\n";
		else
			std::cout << "FAILED.\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}
