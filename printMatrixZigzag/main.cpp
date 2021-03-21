#include <iostream>

const int ROW = 201;
const int COL = 201;
int Num[ROW][COL] = { 0 };

void printMatrixZigzag(int vMatrix[][COL], int vRows, int vCols);
void printLine(int vMatrix[][COL], int vRowStart, int vColStart, int vRowEnd, int vColEnd, bool vIs2Top);
void generateMatrix(int vMatrix[][COL], int vRows, int vCols);
void test(const char* vpTestName, int vRows, int vCols);

int main()
{
	test("Test1", 1, 1);
	test("Test2", 1, 2);
	test("Test3", 2, 2);
	test("Test4", 3, 2);
	test("Test5", 3, 3);
	test("Test6", 4, 4);

	return 0;
}

void printMatrixZigzag(int vMatrix[][COL], int vRows, int vCols)
{
	int RowStart = 0, RowEnd = 0;
	int ColStart = 0, ColEnd = 0;
	bool Is2Top = true;

	while (RowEnd < vRows && ColStart < vCols)
	{
		printLine(vMatrix, RowStart, ColStart, RowEnd, ColEnd, Is2Top);

		if (RowStart != vRows - 1) ++RowStart;
		else ++ColStart;

		if (ColEnd != vCols - 1) ++ColEnd;
		else ++RowEnd;

		Is2Top = !Is2Top;
	}
}

void printLine(int vMatrix[][COL], int vRowStart, int vColStart, int vRowEnd, int vColEnd, bool vIs2Top)
{
	if (!vRowStart && !vRowEnd && !vColStart && !vColEnd)
	{
		std::cout << vMatrix[vRowStart][vColStart] << " ";
		return;
	}

	if (vIs2Top)
	{
		while (vRowStart >= vRowEnd && vColStart <= vColStart)
			std::cout << vMatrix[vRowStart--][vColStart++] << " ";
	}
	else
	{
		while (vRowEnd <= vRowStart && vColEnd >= vColStart)
			std::cout << vMatrix[vRowEnd++][vColEnd--] << " ";
	}
}

void generateMatrix(int vMatrix[][COL], int vRows, int vCols)
{
	for (int i = 0; i < vRows; ++i)
	{
		for (int k = 0; k < vCols; ++k)
		{
			vMatrix[i][k] = i * vCols + k + 1;
		}
	}
}

void test(const char* vpTestName, int vRows, int vCols)
{
	std::cout << vpTestName << ": " << vRows << " rows, " << vCols << " cols.\n";
	generateMatrix(Num, vRows, vCols);

	for (int i = 0; i < vRows; ++i)
	{
		for (int k = 0; k < vCols; ++k)
		{
			std::cout << Num[i][k] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	printMatrixZigzag(Num, vRows, vCols);
	std::cout << "\n\n";
}