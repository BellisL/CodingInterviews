#include <iostream>
#include <vector>
#include <bitset>

int movingCnt(int vThreshold, int vRows, int vCols);
int movingCntSearch(int vThreshold, int vRows, int vCols, int vRow, int vCol, bool* vIsVis);
int getDigitSum(int vNum);
void test(const std::string& vTestName, int vThre, int vRows, int vCols, int vExpect);

int main()
{
	// 方格多行多列
	test("Test1", 5, 10, 10, 21);

	// 方格多行多列
	test("Test2", 15, 20, 20, 359);

	// 方格只有一行，机器人只能到达部分方格
	test("Test3", 10, 1, 100, 29);

	// 方格只有一行，机器人能到达所有方格
	test("Test4", 10, 1, 10, 10);

	// 方格只有一列，机器人只能到达部分方格
	test("Test5", 15, 100, 1, 79);

	// 方格只有一列，机器人能到达所有方格
	test("Test6", 15, 10, 1, 10);

	// 方格只有一行一列
	test("Test7", 15, 1, 1, 1);

	// 方格只有一行一列
	test("Test8", 0, 1, 1, 1);

	// 机器人不能进入任意一个方格
	test("Test9", -10, 10, 10, 0);

	return 0;
}

int movingCnt(int vThreshold, int vRows, int vCols)
{
	if (vRows <= 0 || vCols <= 0) return 0;

	bool* IsVisited = new bool[vRows * vCols];
	memset(IsVisited, 0, vRows * vCols);

	int Cnt = movingCntSearch(vThreshold, vRows, vCols, 0, 0, IsVisited);

	delete[] IsVisited;

	return Cnt;
}

int movingCntSearch(int vThreshold, int vRows, int vCols, int vRow, int vCol, bool * vIsVis)
{
	int Cnt = 0;

	if (vRow >= 0 && vRow < vRows && vCol >= 0 && vCol < vCols && getDigitSum(vRow) + getDigitSum(vCol) <= vThreshold && !vIsVis[vRow * vCols + vCol])
	{
		vIsVis[vRow * vCols + vCol] = true;

		Cnt += 1
			+ movingCntSearch(vThreshold, vRows, vCols, vRow - 1, vCol, vIsVis)
			+ movingCntSearch(vThreshold, vRows, vCols, vRow, vCol - 1, vIsVis)
			+ movingCntSearch(vThreshold, vRows, vCols, vRow + 1, vCol, vIsVis)
			+ movingCntSearch(vThreshold, vRows, vCols, vRow, vCol + 1, vIsVis);
	}

	return Cnt;
}

int getDigitSum(int vNum)
{
	int Res = 0;
	while (vNum)
	{
		Res += vNum % 10;
		vNum /= 10;
	}

	return Res;
}

void test(const std::string & vTestName, int vThre, int vRows, int vCols, int vExpect)
{
	std::cout << vTestName << ": ";
	if (movingCnt(vThre, vRows, vCols) == vExpect)
		std::cout << "PASSED!\n";
	else
		std::cout << "FAILED!\n";

	std::cout << std::endl;
}
