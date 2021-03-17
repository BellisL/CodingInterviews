#include <iostream>

void sequenceofSum(int vSum);
void printList(int vStart, int vLength);

int main()
{
	sequenceofSum(1);
	sequenceofSum(3);
	sequenceofSum(4);
	sequenceofSum(9);
	sequenceofSum(15);
	sequenceofSum(100);

	return 0;
}

void sequenceofSum(int vSum)
{
	if (vSum < 3) return;

	int Low = 1;
	int High = 1;
	int TempSum = 0;
	while (Low <= (vSum >> 1))
	{
		if (TempSum < vSum)
			TempSum += High++;
		else if (TempSum > vSum)
			TempSum -= Low++;
		else
		{
			printList(Low, High - Low);
			TempSum += High++;
		}
	}

	std::cout << std::endl;
}

void printList(int vStart, int vLength)
{
	while (vLength--)
	{
		std::cout << vStart++ << "  ";
	}
	std::cout << std::endl;
}
