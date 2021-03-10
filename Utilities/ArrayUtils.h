#pragma once
#include "UtilitiesExport.h"

int UTILITIES_DECLSPEC randomInRange(int vMin, int vMax);
int UTILITIES_DECLSPEC partition(int* vpData, int vLength, int vStart, int vEnd);
void UTILITIES_DECLSPEC swap(int* vNum1, int* vNum2);