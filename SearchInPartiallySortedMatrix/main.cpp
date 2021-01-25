#include <iostream>
#include <vector>

bool searchInMatrix(const std::vector<std::vector<int>>& vMatrix, int vTarget);
void test(const std::vector<std::vector<int>>& vMatrix, int vTarget);

int main()
{
	std::vector<std::vector<int>> testMatrix = { {1,2,8,9}, {2,4,9,12}, {6,7,10,13}, {6,8,11,15} };
	test(testMatrix, 7);
	test(testMatrix, 5);
	test(testMatrix, 1);
	test(testMatrix, 15);
	test(testMatrix, 0);
	test(testMatrix, 20);
	test({ {} }, 20);

	return 0;
}

bool searchInMatrix(const std::vector<std::vector<int>>& vMatrix, int vTarget)
{
	size_t Row = vMatrix.size();
	size_t Column = vMatrix[0].size();

	int i = 0;
	int k = Column - 1;

	while (i < Row && k >= 0)
	{
		if (vMatrix[i][k] == vTarget)
			return true;
		if (vMatrix[i][k] > vTarget)
			--k;
		else
			++i;
	}

	return false;
}

void test(const std::vector<std::vector<int>>& vMatrix, int vTarget)
{
	std::cout << std::boolalpha << searchInMatrix(vMatrix, vTarget) << std::endl;
}
