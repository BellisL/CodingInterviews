#include <iostream>
#include <vector>

void creatHeap(std::vector<int>& vSet);
void shiftDown(std::vector<int>& vSet, int vIndex, int vSz);
void swap(int* vNum1, int* vNum2);
void test(std::vector<int>& vSet);

int main()
{
	{
		std::vector<int> Nums = { -1, 2, 5, 3, 10, 3, 7 };
		test(Nums);
	}

	{
		std::vector<int> Nums = { 5, 9, 1, 9, 5, 3, 7, 6, 1 };
		test(Nums);
	}

	return 0;
}

void creatHeap(std::vector<int>& vSet)
{
	for (int i = (vSet.size() / 2) - 1; i >= 0; --i)
	{
		shiftDown(vSet, i, vSet.size());
	}
}

void shiftDown(std::vector<int>& vSet, int vIndex, int vSz)
{
	bool Flag = true;
	while (vIndex < vSz && Flag)
	{
		int Temp = vIndex;
		if (2 * vIndex + 1 < vSz && vSet[Temp] > vSet[2 * vIndex + 1])
			Temp = 2 * vIndex + 1;
		if (2 * vIndex + 2 < vSz && vSet[Temp] > vSet[2 * vIndex + 2])
			Temp = 2 * vIndex + 2;

		if (vIndex != Temp)
		{
			swap(&vSet[vIndex], &vSet[Temp]);
			vIndex = Temp;
		}
		else
			Flag = false;
	}
}

void swap(int * vNum1, int * vNum2)
{
	int Temp = *vNum1;
	*vNum1 = *vNum2;
	*vNum2 = Temp;
}

void test(std::vector<int>& vSet)
{
	creatHeap(vSet);
	for (int i = vSet.size() - 1; i >= 0; --i)
	{
		std::cout << vSet[0] << " ";
		swap(&vSet[0], &vSet[i]);
		shiftDown(vSet, 0, i);
	}
	std::cout << "\n\n";
}