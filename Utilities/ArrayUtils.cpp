#include "ArrayUtils.h"
#include <random>

int randomInRange(int vMin, int vMax)
{
	return rand() % (vMax - vMin + 1) + vMin;
}

int partition(int * vpData, int vLength, int vStart, int vEnd)
{
	if (!vpData || vLength <= 0 || vStart < 0 || vEnd >= vLength)
		throw std::runtime_error("Invlid input!");

	int Index = randomInRange(vStart, vEnd);
	swap(&vpData[Index], &vpData[vEnd]);

	int Small = vStart - 1;
	for (Index = vStart; Index < vEnd; ++Index)
	{
		if (vpData[Index] < vpData[vEnd])
		{
			++Small;
			if (Small != Index)
				swap(&vpData[Index], &vpData[Small]);
		}
	}

	++Small;
	swap(&vpData[Small], &vpData[vEnd]);

	return Small;
}

void swap(int * vNum1, int * vNum2)
{
	int Temp = *vNum1;
	*vNum1 = *vNum2;
	*vNum2 = Temp;
}