#include <iostream>
#include <string>
#include <vector>

#define NUM_CHAR 26

char getFirstUniqueChar(const std::string& vSet);
void test(const char* vpTestName, const std::string& vSet, char vExpect);

int main()
{
	{
		const std::string vStr = "google";
		test("Test1", vStr, 'l');
	}

	{
		const std::string vStr = "aabccdbd";
		test("Test2", vStr, '\0');
	}

	{
		const std::string vStr = "abcdefg";
		test("Test3", vStr, 'a');
	}

	{
		const std::string vStr = "";
		test("Test4", vStr, '\0');
	}

	return 0;
}

char getFirstUniqueChar(const std::string& vSet)
{
	if (vSet.empty()) throw std::runtime_error("Invalid input!");

	std::vector<int> CntSet(NUM_CHAR, 0);
	auto Length = vSet.size();
	for (int i = 0; i < Length; ++i)
		++CntSet[vSet[i] - 'a'];

	char Ch = '\0';
	for (int i = 0; i < Length; ++i)
	{
		if (CntSet[vSet[i] - 'a'] == 1)
		{
			Ch = vSet[i];
			break;
		}
	}

	return Ch;
}

void test(const char * vpTestName, const std::string& vSet, char vExpect)
{
	std::cout << vpTestName << std::endl;

	try
	{
		char Res = getFirstUniqueChar(vSet);
		if (Res == vExpect)
			std::cout << "PASSED.\n";
		else
			std::cout << "FAILED.\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}
