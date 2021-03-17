#include <iostream>
#include <string>

void reverseWords(std::string& vStr);
void reverse(std::string& vStr, int vIndex, int vLength);

int main()
{
	{
		std::string Str = std::string("I am a student.");
		reverseWords(Str);
	}

	{
		std::string Str = std::string("student.");
		reverseWords(Str);
	}

	{
		std::string Str = std::string("   ");
		reverseWords(Str);
	}

	{
		std::string Str = std::string("");
		reverseWords(Str);
	}

	return 0;
}

void reverseWords(std::string & vStr)
{
	if (vStr.empty()) return;

	reverse(vStr, 0, vStr.size());

	std::cout << vStr << std::endl;

	int Low = 0;
	int Length = 0;
	while (Low < vStr.size())
	{
		while (Low + Length < vStr.size() && vStr[Low + Length] != ' ')
			++Length;

		if (Length)
			reverse(vStr, Low, Length);
		Low += Length + 1;
		Length = 0;
	}

	std::cout << vStr << std::endl;
	std::cout << std::endl;
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
