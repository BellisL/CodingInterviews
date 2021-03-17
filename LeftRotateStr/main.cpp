#include <iostream>
#include <string>

void reverse(std::string & vStr, int vIndex);
void reverse(std::string & vStr, int vIndex, int vLength);
void test(const char* vpTestName, std::string& vStr, int vIndex, const std::string& vExpect);

int main()
{
	{
		std::string Str = std::string("abcdefg");
		test("Test1", Str, 2, "cdefgab");
	}

	{
		std::string Str = std::string("abcdefg");
		test("Test2", Str, 1, "bcdefga");
	}

	{
		std::string Str = std::string("abcdefg");
		test("Test3", Str, 6, "gabcdef");
	}

	{
		std::string Str = std::string("");
		test("Test4", Str, 0, "");
	}

	{
		std::string Str = std::string("abcdefg");
		test("Test5", Str, 0, "abcdefg");
	}

	return 0;
}

void reverse(std::string & vStr, int vIndex)
{
	if (vStr.empty() || vIndex == 0) return;
	auto Length = vStr.length();
	vIndex = vIndex % Length;

	reverse(vStr, 0, vIndex);
	reverse(vStr, vIndex, Length - vIndex);
	reverse(vStr, 0, Length);
}

void reverse(std::string & vStr, int vIndex, int vLength)
{
	int End = vIndex + vLength - 1;
	while (vIndex < End)
	{
		char Temp = vStr[vIndex];
		vStr[vIndex] = vStr[End];
		vStr[End] = Temp;
		++vIndex;
		--End;
	}
}

void test(const char * vpTestName, std::string & vStr, int vIndex, const std::string & vExpect)
{
	std::cout << vpTestName << std::endl;

	reverse(vStr, vIndex);
	if (vStr == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}