#include <iostream>
#include <vector>
#include <bitset>

int movingCnt(int vThreshold, int vRows, int vCols);
int movingCntSearch(int vThreshold, int vRows, int vCols, int vRow, int vCol, bool* vIsVis);
int getDigitSum(int vNum);
void test(const std::string& vTestName, int vThre, int vRows, int vCols, int vExpect);

int main()
{
	// ������ж���
	test("Test1", 5, 10, 10, 21);

	// ������ж���
	test("Test2", 15, 20, 20, 359);

	// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
	test("Test3", 10, 1, 100, 29);

	// ����ֻ��һ�У��������ܵ������з���
	test("Test4", 10, 1, 10, 10);

	// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
	test("Test5", 15, 100, 1, 79);

	// ����ֻ��һ�У��������ܵ������з���
	test("Test6", 15, 10, 1, 10);

	// ����ֻ��һ��һ��
	test("Test7", 15, 1, 1, 1);

	// ����ֻ��һ��һ��
	test("Test8", 0, 1, 1, 1);

	// �����˲��ܽ�������һ������
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
