#pragma once
typedef int(*pFun)(int);

int solution_3_Helper(int vNum) { return 0; }

int sum_Solution_3(int vNum)
{
	static pFun pF[2] = { solution_3_Helper, sum_Solution_3 };
	return vNum + pF[!!vNum](vNum - 1);
}