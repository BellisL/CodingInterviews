#include <iostream>

bool replaceSpace(char vpStr[], size_t vLength);
void test(char vpStr[], size_t vLength);

int main()
{
	char* Str = nullptr;
	char Str1[20] = "Hello World.";
	char Str2[20] = " Hello World.";
	char Str3[30] = " Hello World. ";
	char Str4[13] = "Hello World.";

	test(Str, 10);
	test(Str1, 20);
	test(Str2, 20);
	test(Str3, 30);
	test(Str4, 13);

	return 0;
}

bool replaceSpace(char vpStr[], size_t vLength)
{
	if (!vpStr) return false;

	auto Length = strlen(vpStr);
	size_t NumSpace = 0;
	for (size_t i = 0; i < Length; ++i)
	{
		if (vpStr[i] == ' ') ++NumSpace;
	}

	size_t BackPtr = Length + NumSpace * 2 + 1;
	if (NumSpace == 0 || BackPtr > vLength) return false;

	size_t FrontPtr = Length + 1;
	while (NumSpace > 0)
	{
		if (vpStr[FrontPtr] == ' ')
		{
			--NumSpace;
			vpStr[BackPtr--] = '0';
			vpStr[BackPtr--] = '2';
			vpStr[BackPtr--] = '%';
			--FrontPtr;
		}
		else
			vpStr[BackPtr--] = vpStr[FrontPtr--];
	}

	return true;
}

void test(char vpStr[], size_t vLength)
{
	if (vpStr)
		std::cout << "Original String: " << vpStr << std::endl;
	else
	{
		std::cout << "Empty String!\n" << std::endl;
		return;
	}

	if (replaceSpace(vpStr, vLength))
		std::cout << "Replaced String: " << vpStr << std::endl;
	else
		std::cout << "Can not replace!" << std::endl;

	std::cout << std::endl;
}
