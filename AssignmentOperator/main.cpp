#include "TestMyString.h"

int main()
{
	CTestMyStr Test;
	Test.test_Normal();
	Test.test_SelfAssignment();
	Test.test_ContinousAssignment();

	return 0;
}