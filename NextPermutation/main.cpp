#include <iostream>
#include <vector>

void nextPermutation(std::vector<int>& vSet);
void reverse(std::vector<int>& vSet, int vStart);
void swap(int* vNum1, int* vNum2);
void test(const char* vpTestName, std::vector<int>& vSet, std::vector<int>& vExpectSet);
bool isEqual(const std::vector<int>& vDstSet, const std::vector<int>& vExpectSet);

int main()
{
	{
		std::vector<int> Set = { 1,2,3 };
		std::vector<int> ExpectSet = { 1,3,2 };
		test("Test1", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 1,3,2 };
		std::vector<int> ExpectSet = { 2,1,3 };
		test("Test2", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 2,1,3 };
		std::vector<int> ExpectSet = { 2,3,1 };
		test("Test3", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 2,3,1 };
		std::vector<int> ExpectSet = { 3,1,2 };
		test("Test4", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 3,1,2 };
		std::vector<int> ExpectSet = { 3,2,1 };
		test("Test5", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 3,2,1 };
		std::vector<int> ExpectSet = { 1,2,3 };
		test("Test6", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 3,4,2,1 };
		std::vector<int> ExpectSet = { 4,1,2,3 };
		test("Test7", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 4,3,2,1 };
		std::vector<int> ExpectSet = { 1,2,3,4 };
		test("Test8", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 1,1,5 };
		std::vector<int> ExpectSet = { 1,5,1 };
		test("Test9", Set, ExpectSet);
	}

	{
		std::vector<int> Set = { 1 };
		std::vector<int> ExpectSet = { 1 };
		test("Test10", Set, ExpectSet);
	}

	{
		std::vector<int> Set = {  };
		std::vector<int> ExpectSet = {  };
		test("Test11", Set, ExpectSet);
	}

	return 0;
}

void nextPermutation(std::vector<int>& vSet)
{
	if (vSet.size() < 2) return;

	int i = vSet.size() - 2;
	while (i >= 0 && vSet[i + 1] <= vSet[i])
		--i;

	if (i >= 0)
	{
		int k = vSet.size() - 1;
		while (k > i && vSet[k] <= vSet[i])
			--k;

		if(i != k)
			swap(&vSet[i], &vSet[k]);
	}

	reverse(vSet, i + 1);
}

void reverse(std::vector<int>& vSet, int vStart)
{
	int i = vStart;
	int k = vSet.size() - 1;
	while (i < k)
	{
		swap(&vSet[i++], &vSet[k--]);
	}
}

void swap(int * vNum1, int * vNum2)
{
	int Temp = *vNum1;
	*vNum1 = *vNum2;
	*vNum2 = Temp;
}

void test(const char * vpTestName, std::vector<int>& vSet, std::vector<int>& vExpectSet)
{
	std::cout << vpTestName << std::endl;

	nextPermutation(vSet);
	if (isEqual(vSet, vExpectSet))
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}

bool isEqual(const std::vector<int>& vDstSet, const std::vector<int>& vExpectSet)
{
	if (vDstSet.size() != vExpectSet.size())
		return false;

	for (int i = 0; i < vDstSet.size(); ++i)
	{
		if (vDstSet[i] != vExpectSet[i])
			return false;
	}

	return true;
}