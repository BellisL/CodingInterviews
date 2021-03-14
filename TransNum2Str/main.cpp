#include <iostream>
#include <string>

int numTrans2Str_1(int vNum);
int cntNumTrans2Str(const std::string& vStr);
int numTrans2Str_2(long vNum);
int cntNumTrans2Str(const std::string& vStr, int vIndex);
void test(const char* vpTestName, long vNum, int vExpect);

int main()
{
	test("Test1", 0, 1);
	test("Test2", 10, 2);
	test("Test3", 125, 3);
	test("Test4", 126, 2);
	test("Test5", 426, 1);
	test("Test6", 100, 2);
	test("Test7", 101, 2);
	test("Test8", 12258, 5);
	test("Test9", -101, 0);

	return 0;
}

int numTrans2Str_1(int vNum)
{
	if (vNum < 0) return 0;

	return cntNumTrans2Str(std::to_string(vNum));
}

int cntNumTrans2Str(const std::string & vStr)
{
	int Length = vStr.length();
	int* Cnt = new int[Length];
	int Count = 0;

	for (int i = Length - 1; i >= 0; --i)
	{
		Count = 0;
		if (i < Length - 1)
			Count = Cnt[i + 1];
		else
			Count = 1;

		if (i < Length - 1)
		{
			int Left = vStr[i] - '0';
			int Right = vStr[i + 1] - '0';
			int Index = 10 * Left + Right;
			if (Index >= 10 && Index <= 25)
			{
				if (i < Length - 2)
					Count += Cnt[i + 2];
				else
					Count += 1;
			}
		}

		Cnt[i] = Count;
	}

	Count = Cnt[0];
	delete[] Cnt;
	return Count;
}

int numTrans2Str_2(long vNum)
{
	if (vNum < 0) return 0;

	return cntNumTrans2Str(std::to_string(vNum), 0);
}

int cntNumTrans2Str(const std::string & vStr, int vIndex)
{
	if (vIndex == vStr.length() - 1 || vIndex == vStr.length())
		return 1;

	if (vIndex <= vStr.length() - 2)
	{
		int Left = vStr[vIndex] - '0';
		int Right = vStr[vIndex + 1] - '0';

		if (Left < 1 || Left > 2 || (Left == 2 && Right >= 6))
			return cntNumTrans2Str(vStr, vIndex + 1);
		else
			return cntNumTrans2Str(vStr, vIndex + 1) + cntNumTrans2Str(vStr, vIndex + 2);
	}
	
	return cntNumTrans2Str(vStr, vIndex + 1);
}

void test(const char * vpTestName, long vNum, int vExpect)
{
	std::cout << vpTestName << std::endl;

	int Res1 = numTrans2Str_1(vNum);
	int Res2 = numTrans2Str_2(vNum);
	//std::cout << Res1 << std::endl;
	if (Res1 == vExpect && Res2 == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
