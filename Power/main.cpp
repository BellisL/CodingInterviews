#include <iostream>
#include <exception>
#include <string>

double power(double vBase, int vExp);
double powerWithUnsignedExp(double vBase, unsigned int vExp);
void test(const std::string& vName, double vBase, int vExp, double vExpect);

int main()
{
	test("Test1", 2, 3, 8);
	test("Test2", -2, 3, -8);
	test("Test3", 2, -3, 0.125);
	test("Test4", 2, 0, 1);
	test("Test5", 0, 4, 0);
	test("Test6", 0, -4, 0);
	test("Test7", 0, 0, 0);

	return 0;
}

double power(double vBase, int vExp)
{
	if (vBase - 0.0 < FLT_EPSILON && 0.0 - vBase < FLT_EPSILON)
	{
		if (vExp <= 0)
			throw std::runtime_error("Invalid input!");
		else
			return 0.0;
	}
	else
	{
		if (vExp - 0.0 < FLT_EPSILON && 0.0 - vExp < FLT_EPSILON)
			return 1.0;
	}

	bool Flag = vExp < 0 ? true : false;

	int Exp = Flag ? -vExp : vExp;

	double Res = vBase;

	int Index = 1;
	while (2 * Index <= Exp)
	{
		Res *= Res;
		++Index;
	}
	--Index;

	if (2 * Index <= Exp)
	{
		for (int i = 1 + 2 * Index; i <= Exp; ++i)
		{
			Res *= vBase;
		}
	}

	if (Flag) Res = 1 / Res;

	return Res;
}

//ตÝน้
double powerWithUnsignedExp(double vBase, unsigned int vExp)
{
	if (vExp == 0) return 1.0;
	if (vExp == 1) return vBase;

	double Res = powerWithUnsignedExp(vBase, vExp >> 1);
	Res *= Res;
	if (vExp & 0x1 == 1)
		Res *= vBase;

	return Res;
}

void test(const std::string & vName, double vBase, int vExp, double vExpect)
{
	std::cout << vName << ": ";
	double Res = 0.0;

	try
	{
		Res = power(vBase, vExp);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
		return;
	}

	if (vExpect - Res < FLT_EPSILON && Res - vExpect < FLT_EPSILON)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
