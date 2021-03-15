#include <iostream>
#include <vector>
#include <algorithm>

void mergeSort_Iter(std::vector<int>& vSet);
void mergeSort_Recur(std::vector<int>& vSet);
void mergeSortCore(std::vector<int>& vSet, std::vector<int>& vAssistSet, int vStart, int vEnd);
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

void mergeSort_Iter(std::vector<int>& vSet)
{
	if (vSet.empty()) return;

	std::vector<int>& Set = vSet;
	std::vector<int> AssistSet(Set);
	int Length = Set.size();

	for (int Seg = 1; Seg < Length; Seg += Seg)
	{
		for (int i = 0; i < Length; i += Seg * 2)
		{
			int Low = i;
			int Mid = std::min(i + Seg, Length);
			int High = std::min(i + Seg * 2, Length);

			int CopyIndex = Low;
			int Start1 = Low, End1 = Mid;
			int Start2 = Mid, End2 = High;

			while (Start1 < End1 && Start2 < End2)
				AssistSet[CopyIndex++] = Set[Start1] <= Set[Start2] ? vSet[Start1++] : vSet[Start2++];
			
			for (; Start1 < End1; )
				AssistSet[CopyIndex++] = Set[Start1++];

			for (; Start2 < End2; )
				AssistSet[CopyIndex++] = Set[Start2++];
		}

		Set.swap(AssistSet);
	}

	if (vSet != Set) Set.swap(AssistSet);
}

void mergeSort_Recur(std::vector<int>& vSet)
{
	if (vSet.empty()) return;

	std::vector<int> AssistSet(vSet);
	mergeSortCore(vSet, AssistSet, 0, vSet.size() - 1);
}

void mergeSortCore(std::vector<int>& vSet, std::vector<int>& vAssistSet, int vStart, int vEnd)
{
	if (vStart == vEnd) return;

	int Mid = vStart + ((vEnd - vStart) >> 1);
	mergeSortCore(vSet, vAssistSet, vStart, Mid);
	mergeSortCore(vSet, vAssistSet, Mid + 1, vEnd);

	int Start1 = vStart, End1 = Mid;
	int Start2 = Mid + 1, End2 = vEnd;
	int CopyIndex = vStart;

	while (Start1 <= End1 && Start2 <= End2)
		vAssistSet[CopyIndex++] = vSet[Start1] <= vSet[Start2] ? vSet[Start1++] : vSet[Start2++];

	while (Start1 <= End1)
		vAssistSet[CopyIndex++] = vSet[Start1++];

	while (Start2 <= End2)
		vAssistSet[CopyIndex++] = vSet[Start2++];

	for (int i = vStart; i <= vEnd; ++i)
		vSet[i] = vAssistSet[i];
}

void test(std::vector<int>& vSet)
{
	std::vector<int> CopySet(vSet);

	mergeSort_Iter(vSet);
	std::cout << "mergeSort_Iter: ";
	for (const auto Num : vSet)
	{
		std::cout << Num << " ";
	}
	std::cout << "\n";

	mergeSort_Recur(CopySet);
	std::cout << "mergeSort_Recur: ";
	for (const auto Num : CopySet)
	{
		std::cout << Num << " ";
	}
	std::cout << "\n";

	std::cout << "\n";
}