#include <iostream>

const int g_MaxValue = 6;

void printProb_1(int vNum);
void prob(int vNum, int pProbs[]);
void prob(int vNum, int vCur, int vSum, int pProbs[]);
void printProb_2(int vNum);

int main()
{
	printProb_1(2);
	printProb_2(2);
	printProb_1(3);
	printProb_2(3);
	printProb_1(4);
	printProb_2(4);

	return 0;
}

void printProb_1(int vNum)
{
	if (vNum < 1) return;

	int MaxSum = vNum * g_MaxValue;
	int* pProbs = new int[MaxSum - vNum + 1];
	memset(pProbs, 0, sizeof(int) * (MaxSum - vNum + 1));

	prob(vNum, pProbs);
	float Total = powf(g_MaxValue, vNum);
	std::cout << "Recur: " << std::endl;
	for (int i = vNum; i <= MaxSum; ++i)
	{
		float Ratio = pProbs[i - vNum] / Total;
		std::cout << i << ": " << Ratio << std::endl;
	}
	std::cout << std::endl;

	delete[] pProbs;
}

void prob(int vNum, int pProbs[])
{
	for (int i = 1; i <= g_MaxValue; ++i)
		prob(vNum, vNum, i, pProbs);
}

void prob(int vNum, int vCur, int vSum, int pProbs[])
{
	if (vCur == 1)
		pProbs[vSum - vNum]++;
	else
	{
		for (int i = 1; i <= g_MaxValue; ++i)
			prob(vNum, vCur - 1, i + vSum, pProbs);
	}
}

void printProb_2(int vNum)
{
	if (vNum < 1) return;

	int MaxSum = g_MaxValue * vNum;
	int* pProbs[2];
	for (int i = 0; i < 2; ++i)
	{
		pProbs[i] = new int[MaxSum + 1];
		memset(pProbs[i], 0, (MaxSum + 1) * sizeof(int));
	}

	int Flag = 0;
	for (int i = 1; i <= g_MaxValue; ++i)
		pProbs[Flag][i] = 1;

	for (int i = 2; i <= vNum; ++i)
	{
		for (int k = 0; k <= g_MaxValue * i; ++k)
			pProbs[1 - Flag][k] = 0;

		for (int k = i; k <= g_MaxValue * i; ++k)
		{
			for (int j = 1; j <= k && j <= g_MaxValue; ++j)
				///本轮和为n的骰子应为上一轮骰子点数n-1~n-6的次数之和
				pProbs[1 - Flag][k] += pProbs[Flag][k - j];
		}

		Flag = 1 - Flag;
	}

	float Total = powf(g_MaxValue, vNum);
	std::cout << "for-each: " << std::endl;
	for (int i = vNum; i <= MaxSum; ++i)
	{
		float Ratio = pProbs[Flag][i] / Total;
		std::cout << i << ": " << Ratio << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 2; ++i)
		delete[] pProbs[i];
}
