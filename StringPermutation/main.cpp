#include <iostream>

void permutation(char* vpStr, int vLength, int vIndex);
void swap(char * vCh1, char * vCh2);
void test(const char* vpTestName, char* vpStr);

int main()
{
	{
		char pStr[] = "";
		test("Test1", pStr);
	}

	{
		char pStr[] = "a";
		test("Test2", pStr);
	}

	{
		char pStr[] = "ab";
		test("Test3", pStr);
	}

	{
		char pStr[] = "abc";
		test("Test4", pStr);
	}

	return 0;
}

void permutation(char * vpStr, int vLength, int vIndex)
{
	if (vIndex + 1 == vLength)
	{
		std::cout << vpStr << std::endl;
		return;
	}

	for (int i = vIndex; i < vLength; ++i)
	{
		swap(&vpStr[vIndex], &vpStr[i]);
		permutation(vpStr, vLength, vIndex + 1);
		swap(&vpStr[vIndex], &vpStr[i]);
	}
}

void swap(char * vCh1, char * vCh2)
{
	char Temp = *vCh1;
	*vCh1 = *vCh2;
	*vCh2 = Temp;
}

void test(const char* vpTestName, char * vpStr)
{
	std::cout << vpTestName << ":\n";
	int Len = strlen(vpStr);
	permutation(vpStr, Len, 0);

	std::cout << std::endl;
}
