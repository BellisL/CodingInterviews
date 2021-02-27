#include <iostream>
#include <string>

int Numof1(int vNum);
int NUmof1_fast(int vNum);
void test(const std::string& vTestName, int vNum, int vExpect);

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 10, 2);
	test("Test4", 0x7FFFFFFF, 31);
	test("Test5", 0xFFFFFFFF, 32);
	test("Test6", 0x80000000, 1);

	return 0;
}

int Numof1(int vNum)
{
	int Cnt = 0;
	unsigned int Flag = 1;
	while (Flag)
	{
		if (Flag & vNum) ++Cnt;
		Flag = Flag << 1;
	}

	return Cnt;
}

int NUmof1_fast(int vNum)
{
	int Cnt = 0;
	while (vNum)
	{
		vNum &= (vNum - 1);
		++Cnt;
	}

	return Cnt;
}

void test(const std::string& vTestName, int vNum, int vExpect)
{
	std::cout << vTestName << ": ";
	if (vExpect == Numof1(vNum) && vExpect == NUmof1_fast(vNum))
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
