#include <iostream>
#include <vector>
#include <algorithm>

struct SPoint
{
	SPoint() : X(0), Y(0) {}
	SPoint(int x, int y) : X(x), Y(y) {}

	int X;
	int Y;
};

SPoint operator-(const SPoint& vL, const SPoint& vR);
long long operator^(const SPoint& vL, const SPoint& vR);
bool operator<(const SPoint& vL, const SPoint& vR);

SPoint operator-(const SPoint& vL, const SPoint & vR)
{
	return SPoint(vL.X - vR.X, vL.Y - vR.Y);
}

long long operator^(const SPoint& vL, const SPoint& vR)
{
	return static_cast<long long>(vL.X) * vR.Y - static_cast<long long>(vL.Y) * vR.X;
}

bool operator<(const SPoint& vL, const SPoint& vR)
{
	return vL.X == vR.X ? vL.Y < vR.Y : vL.X < vR.X;
}

bool operator==(const SPoint& vL, const SPoint& vR)
{
	return vL.X == vR.X && vL.Y == vR.Y;
}

void convex(std::vector<SPoint>& vSet, std::vector<SPoint>& vCSet);
void test(const char* vpTestName, std::vector<SPoint>& vSet, std::vector<SPoint>& vExpectSet);

int main()
{
	{
		std::vector<SPoint> Set;
		Set.emplace_back(7, 9);
		Set.emplace_back(-8, -1);
		Set.emplace_back(-3, -1);
		Set.emplace_back(1, 4);
		Set.emplace_back(-3, 9);
		Set.emplace_back(6, -4);
		Set.emplace_back(7, 5);
		Set.emplace_back(6, 6);
		Set.emplace_back(-6, 10);
		Set.emplace_back(0, 8);

		std::vector<SPoint> ExpectSet;
		ExpectSet.emplace_back(-8, -1);
		ExpectSet.emplace_back(-6, 10);
		ExpectSet.emplace_back(7, 9);
		ExpectSet.emplace_back(7, 5);
		ExpectSet.emplace_back(6, -4);
		test("Test1", Set, ExpectSet);
	}

	{
		std::vector<SPoint> Set;
		Set.emplace_back(7, 9);
		Set.emplace_back(-3, -1);
		Set.emplace_back(1, 4);
		Set.emplace_back(-3, 9);
		Set.emplace_back(6, -4);
		Set.emplace_back(7, 5);
		Set.emplace_back(6, 6);
		Set.emplace_back(-6, 10);
		Set.emplace_back(0, 8);

		std::vector<SPoint> ExpectSet;
		ExpectSet.emplace_back(-3, -1);
		ExpectSet.emplace_back(-6, 10);
		ExpectSet.emplace_back(7, 9);
		ExpectSet.emplace_back(7, 5);
		ExpectSet.emplace_back(6, -4);
		test("Test2", Set, ExpectSet);
	}

	{
		std::vector<SPoint> Set;
		Set.emplace_back(7, 9);
		Set.emplace_back(-8, -1);
		Set.emplace_back(-3, -1);
		Set.emplace_back(1, 4);
		Set.emplace_back(-3, 9);
		Set.emplace_back(6, -4);
		Set.emplace_back(7, 5);
		Set.emplace_back(6, 6);
		Set.emplace_back(0, 8);

		std::vector<SPoint> ExpectSet;
		ExpectSet.emplace_back(-8, -1);
		ExpectSet.emplace_back(-3, 9);
		ExpectSet.emplace_back(7, 9);
		ExpectSet.emplace_back(7, 5);
		ExpectSet.emplace_back(6, -4);
		test("Test3", Set, ExpectSet);
	}

	{
		std::vector<SPoint> Set;
		Set.emplace_back(-3, 9);
		Set.emplace_back(-6, 10);
		Set.emplace_back(0, 8);

		std::vector<SPoint> ExpectSet;
		test("Test4", Set, ExpectSet);
	}

	{
		std::vector<SPoint> Set;
		Set.emplace_back(-3, 9);
		Set.emplace_back(-6, 10);

		std::vector<SPoint> ExpectSet;
		test("Test5", Set, ExpectSet);
	}

	return 0;
}

void convex(std::vector<SPoint>& vSet, std::vector<SPoint>& vCSet)
{
	if (vSet.size() < 3) return;

	std::sort(vSet.begin(), vSet.end());
	vSet.erase(std::unique(vSet.begin(), vSet.end()), vSet.end());

	//求下凸壳
	int CIndex = 0;
 	for (int i = 0; i < vSet.size(); ++i)
	{
		while (CIndex > 1 && ((vCSet[CIndex - 1] - vCSet[CIndex - 2]) ^ (vSet[i] - vCSet[CIndex - 2])) < 0)
		{
			--CIndex;
		}
		vCSet[CIndex++] = vSet[i];
	}

	//求上凸壳
	for (int i = vSet.size() - 2, T = CIndex; i >= 0; --i)
	{
		while (CIndex > T && ((vCSet[CIndex - 1] - vCSet[CIndex - 2]) ^ (vSet[i] - vCSet[CIndex - 2])) < 0)
		{
			--CIndex;
		}
		if (CIndex < vCSet.size())
			vCSet[CIndex++] = vSet[i];
		else
			break;
	}
}

void test(const char* vpTestName, std::vector<SPoint>& vSet, std::vector<SPoint>& vExpectSet)
{
	std::cout << vpTestName << std::endl;

	std::vector<SPoint> CSet(vSet.size());
	convex(vSet, CSet);
	CSet.resize(vExpectSet.size());
	std::sort(CSet.begin(), CSet.end());
	std::sort(vExpectSet.begin(), vExpectSet.end());
	if (CSet == vExpectSet)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}