#include <iostream>
#include <vector>

void quickSort(std::vector<int>& vSet, int vStart, int vEnd);
void testSort(std::vector<int>& vSet);

int main()
{
	{
		std::vector<int> Nums = { -1, 2, 5, 3, 10, 3, 7 };
		testSort(Nums);
	}

	{
		std::vector<int> Nums = { 5, 9, 1, 9, 5, 3, 7, 6, 1 };
		testSort(Nums);
	}

	return 0;
}

void quickSort(std::vector<int>& vSet, int vStart, int vEnd)
{
	if (vStart >= vEnd) return;

	int Left = vStart;
	int Right = vEnd;

	int Key = vSet[Left];
	while (Left < Right)
	{
		while (Left < Right && vSet[Right] >= Key) --Right;

		if (Left < Right)
		{
			vSet[Left] = vSet[Right];
			++Left;
		}

		while (Left < Right && vSet[Left] <= Key) ++Left;

		if (Left < Right)
		{
			vSet[Right] = vSet[Left];
			--Right;
		}
	}

	vSet[Left] = Key;
	quickSort(vSet, vStart, Left - 1);
	quickSort(vSet, Left + 1, vEnd);
}

void testSort(std::vector<int>& vSet)
{
	if (vSet.size() <= 1)
	{
		std::cout << "No need to sort." << std::endl;
		return;
	}

	quickSort(vSet, 0, vSet.size() - 1);

	for (const auto Num : vSet)
	{
		std::cout << Num << " ";
	}

	std::cout << "\n";
}
