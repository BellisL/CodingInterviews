#include "TestMyString.h"

//*****************************************************************************************
//FUNCTION:
void CTestMyStr::test_Normal()
{
	std::cout << "test_Normal: " << std::endl;

	const char* Text = "Hello HR";
	CMyString Str1(Text);
	CMyString Str2;
	Str2 = Str1;

	std::cout << "Text: " << Text << std::endl;
	std::cout << "Str1: ";
	Str1.printStr();
	std::cout << "Str2: ";
	Str2.printStr();

	std::cout << "\n";
}

//*****************************************************************************************
//FUNCTION:
void CTestMyStr::test_SelfAssignment()
{
	std::cout << "test_SelfAssignment: " << std::endl;

	const char* Text = "Hello HR";
	CMyString Str1(Text);
	Str1 = Str1;

	std::cout << "Text: " << Text << std::endl;
	std::cout << "Str1: ";
	Str1.printStr();

	std::cout << "\n";
}

//*****************************************************************************************
//FUNCTION:
void CTestMyStr::test_ContinousAssignment()
{
	std::cout << "test_ContinousAssignment: " << std::endl;

	const char* Text = "Hello HR";
	CMyString Str1(Text);
	CMyString Str2;
	CMyString Str3;
	Str3 = Str2 = Str1;

	std::cout << "Text: " << Text << std::endl;
	std::cout << "Str1: ";
	Str1.printStr();
	std::cout << "Str2: ";
	Str2.printStr();
	std::cout << "Str3: ";
	Str3.printStr();

	std::cout << "\n";
}
