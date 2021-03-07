#include <iostream>

void printMatrixCW(int** vppNum, unsigned int vRows, unsigned int vCols);
void printMatrixCircle(int** vppNum, unsigned int vRows, unsigned int vCols, int vCircles);
void generateMatrix(int ** vppNums, unsigned int vRows, unsigned int vCols);
void test(const char* vpTestName, unsigned int vRows, unsigned int vCols);

int main()
{
	test("Test1", 1, 1);
	test("Test2", 2, 2);
	test("Test3", 3, 3);
	test("Test4", 4, 4);
	test("Test5", 5, 5);
	test("Test6", 1, 5);
	test("Test7", 2, 5);
	test("Test8", 3, 5);
	test("Test9", 4, 5);
	test("Test10", 5, 1);
	test("Test11", 5, 2);
	test("Test12", 5, 3);
	test("Test13", 5, 4);

	return 0;
}

void printMatrixCW(int ** vppNum, unsigned int vRows, unsigned int vCols)
{
	if (!vppNum || vRows <= 0 || vCols <= 0) return;

	int Times = vRows <= vCols ? vRows : vCols;
	if (Times % 2)
		Times = 1 + Times / 2;
	else
		Times = Times / 2;

	for (int i = 0; i < Times; ++i)
		printMatrixCircle(vppNum, vRows, vCols, i);

	std::cout << "\n";
}

void printMatrixCircle(int ** vppNum, unsigned int vRows, unsigned int vCols, int vCircles)
{
	int EndX = vCols - 1 - vCircles;
	int EndY = vRows - 1 - vCircles;

	for (int i = vCircles; i <= EndX; ++i)
		std::cout << vppNum[vCircles][i] << "\t";

	if (EndY > vCircles)
	{
		for (int i = vCircles + 1; i <= EndY; ++i)
			std::cout << vppNum[i][EndX] << "\t";
	}

	if (EndX > vCircles && EndY > vCircles)
	{
		for (int i = EndX - 1; i >= vCircles; --i)
			std::cout << vppNum[EndY][i] << "\t";
	}

	if (EndX > vCircles && EndY - 1 > vCircles)
	{
		for (int i = EndY - 1; i >= vCircles + 1; --i)
			std::cout << vppNum[i][vCircles] << "\t";
	}
}

void generateMatrix(int ** vppNums, unsigned int vRows, unsigned int vCols)
{
	for (unsigned int i = 0; i < vRows; ++i)
	{
		vppNums[i] = new int[vCols];
		for (unsigned int k = 0; k < vCols; ++k)
		{
			vppNums[i][k] = i * vCols + k + 1;
		}
	}
}

void test(const char * vpTestName, unsigned int vRows, unsigned int vCols)
{
	std::cout << vpTestName << ": " << vRows << " rows, " << vCols << " cols.\n";
	int** ppNums = new int*[vRows];
	generateMatrix(ppNums, vRows, vCols);
	printMatrixCW(ppNums, vRows, vCols);
	
	for (int i = 0; i < vRows; --i)
		delete[] ppNums[i];

	delete[] ppNums;
}
