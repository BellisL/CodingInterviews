#include <iostream>
#include <vector>

void print1ToMaxNDigits(int vN);
bool increment(std::vector<char>& vNum);
void printNum(const std::vector<char>& vNum);

void print1ToMaxNDigitsEasy(int vN);
void generateNDigitsRecursively(std::vector<char>& vNum, int vIndex);

//位映射来表示大数 https://www.jianshu.com/p/6082a2f7df8e

int main()
{
	print1ToMaxNDigitsEasy(-1);
	print1ToMaxNDigitsEasy(0);
	print1ToMaxNDigitsEasy(1);
	print1ToMaxNDigitsEasy(2);

	print1ToMaxNDigits(-1);
	print1ToMaxNDigits(0);
	print1ToMaxNDigits(1);
	print1ToMaxNDigits(2);

	return 0;
}

void print1ToMaxNDigits(int vN)
{
	if (vN <= 0) return;

	std::vector<char> NumSet(vN, '0');
	while (!increment(NumSet))
		printNum(NumSet);

	std::cout << std::endl;
}

bool increment(std::vector<char>& vNum)
{
	bool IsOverFlow = false;

	int TakeOver = 0;
	int Length = vNum.size();

	for (int i = Length - 1; i >= 0; --i)
	{
		int Sum = vNum[i] - '0' + TakeOver;
		if (i == Length - 1)
			++Sum;
		if (Sum >= 10)
		{
			if (i == 0)
				IsOverFlow = true;
			else
			{
				Sum -= 10;
				TakeOver = 1;
				vNum[i] = Sum + '0';
			}
		}
		else
		{
			vNum[i] = Sum + '0';
			break;
		}
	}

	return IsOverFlow;
}

void printNum(const std::vector<char>& vNum)
{
	bool IsBeginWith0 = true;

	for (int i = 0; i < vNum.size(); ++i)
	{
		if (IsBeginWith0 && vNum[i] != '0')
			IsBeginWith0 = false;

		if (!IsBeginWith0)
			std::cout << vNum[i];
	}
	std::cout << std::endl;
}

void print1ToMaxNDigitsEasy(int vN)
{
	if (vN <= 0) return;

	std::vector<char> NumSet(vN, '0');
	generateNDigitsRecursively(NumSet, 0);

	std::cout << std::endl;
}

void generateNDigitsRecursively(std::vector<char>& vNum, int vIndex)
{
	if (vIndex == vNum.size())
	{
		printNum(vNum);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		vNum[vIndex] = i + '0';
		generateNDigitsRecursively(vNum, vIndex + 1);
	}
}
