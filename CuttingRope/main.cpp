#include <iostream>
#include <vector>
#include <string>

int cuttingRope_On2(int vLength);
int cuttingRope_O1(int vLength);
void test(const std::string& vTestName, int vLength, int vExpect);

int main()
{
	{
		int Length = 1;
		int Expect = 0;
		test("Test1", Length, Expect);
	}

	{
		int Length = 2;
		int Expect = 1;
		test("Test2", Length, Expect);
	}

	{
		int Length = 3;
		int Expect = 2;
		test("Test3", Length, Expect);
	}

	{
		int Length = 4;
		int Expect = 4;
		test("Test4", Length, Expect);
	}

	{
		int Length = 5;
		int Expect = 6;
		test("Test5", Length, Expect);
	}

	{
		int Length = 6;
		int Expect = 9;
		test("Test6", Length, Expect);
	}

	{
		int Length = 7;
		int Expect = 12;
		test("Test7", Length, Expect);
	}

	{
		int Length = 8;
		int Expect = 18;
		test("Test8", Length, Expect);
	}

	{
		int Length = 9;
		int Expect = 27;
		test("Test9", Length, Expect);
	}

	{
		int Length = 10;
		int Expect = 36;
		test("Test10", Length, Expect);
	}

	{
		int Length = 50;
		int Expect = 86093442;
		test("Test11", Length, Expect);
	}

	return 0;
}

int cuttingRope_On2(int vLength)
{
	if (vLength < 2) return 0;
	if (vLength == 2) return 1;
	if (vLength == 3) return 2;

	std::vector<int> ProductSet(vLength + 1, 0);
	ProductSet[1] = 1;
	ProductSet[2] = 2;
	ProductSet[3] = 3;	//和前面出口条件意义不同，这里是说，如果绳子长度大于3，那么尽量不切割出小于3的长度

	for (int i = 4; i <= vLength; ++i)
	{
		for (int k = 1; k <= i / 2; ++k)
		{
			int TempProduct = ProductSet[k] * ProductSet[i - k];
			if (ProductSet[i] < TempProduct)
				ProductSet[i] = TempProduct;
		}
	}

	return ProductSet[vLength];
}

int cuttingRope_O1(int vLength)
{
	if (vLength < 2) return 0;
	if (vLength == 2) return 1;
	if (vLength == 3) return 2;

	int Length3 = vLength / 3;
	if (vLength - 3 * Length3 == 1)
		Length3 -= 1;

	int Length2 = (vLength - 3 * Length3) / 2;

	return pow(3, Length3) * pow(2, Length2);
}

void test(const std::string & vTestName, int vLength, int vExpect)
{
	std::cout << vTestName << ": ";
	if (vExpect == cuttingRope_On2(vLength) && vExpect == cuttingRope_O1(vLength))
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
