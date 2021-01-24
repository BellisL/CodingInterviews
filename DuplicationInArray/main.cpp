#include <iostream>

bool findDuplicates(int vArr[], size_t vLen, int* vPtr);
void test(int vArr[], size_t vLen);

int main()
{
	int* TestArr0 = nullptr;
	int TestArr1[] = { 1, 1 };
	int TestArr2[] = { 1,6,5,5,4,3,0 };
	int TestArr3[] = { 4,5,6,7,3,0,1,2 };

	test(TestArr0, sizeof(TestArr0) / sizeof(int));
	test(TestArr1, sizeof(TestArr1) / sizeof(int));
	test(TestArr2, sizeof(TestArr2) / sizeof(int));
	test(TestArr3, sizeof(TestArr3) / sizeof(int));

	return 0;
}

bool findDuplicates(int vArr[], size_t vLen, int * vPtr)
{
	if (!vArr || vLen < 2) return false;

	for (size_t i = 0; i < vLen; ++i)
	{
		if (vArr[i] < 0 || vArr[i] >= vLen) return false;
	}

	for (size_t i = 0; i < vLen; ++i)
	{
		while (vArr[i] != i)
		{
			if (vArr[vArr[i]] == vArr[i])
			{
				*vPtr = vArr[i];
				return true;
			}

			int Temp = vArr[vArr[i]];
			vArr[vArr[i]] = vArr[i];
			vArr[i] = Temp;
		}
	}


	return false;
}

void test(int vArr[], size_t vLen)
{
	int pRes;
	bool Result = false;

	Result = findDuplicates(vArr, vLen, &pRes);

	if (Result)
	{
		std::cout << "The Duplicate number is: " << pRes << std::endl;
 	}
	else{
		std::cout << "Error return or not found!" << std::endl;
	}
}
