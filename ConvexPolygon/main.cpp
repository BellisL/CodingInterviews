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
bool operator==(const SPoint& vL, const SPoint& vR);
long long cross(const SPoint & vL, const SPoint & vR);
long long dir(const SPoint & vL, const SPoint & vM, const SPoint & vR);

bool isConvexPolygon(const std::vector<SPoint>& vSet);
void test(const char* vpTestName, const std::vector<SPoint>& vSet, bool vExpect);

int main()
{
	{
		std::vector<SPoint> Set;
		Set.emplace_back(7, 9);
		Set.emplace_back(-6, 10);
		Set.emplace_back(-8, -1);
		Set.emplace_back(6, -4);
		Set.emplace_back(7, 5);

		test("Test1", Set, true);
	}

	{
		std::vector<SPoint> Set;
		Set.emplace_back(7, 9);
		Set.emplace_back(-6, 10);
		Set.emplace_back(-8, -1);
		Set.emplace_back(1, 4);
		Set.emplace_back(6, 6);

		test("Test2", Set, false);
	}

	return 0;
}

SPoint operator-(const SPoint& vL, const SPoint & vR)
{
	return SPoint(vL.X - vR.X, vL.Y - vR.Y);
}

bool operator==(const SPoint& vL, const SPoint& vR)
{
	return vL.X == vR.X && vL.Y == vR.Y;
}

long long cross(const SPoint & vL, const SPoint & vR)
{
	return static_cast<long long>(vL.X) * vR.Y - static_cast<long long>(vL.Y) * vR.X;
}

long long dir(const SPoint & vL, const SPoint & vM, const SPoint & vR)
{
	return cross(vM - vL, vR - vM);
}

bool isConvexPolygon(const std::vector<SPoint>& vSet)
{
	if (vSet.size() < 3) return false;

	long long Flag = 0;
	for (int i = 0; i <= vSet.size() - 3; ++i)
	{
		long long CurDir = dir(vSet[i], vSet[i + 1], vSet[i + 2]);
		if (CurDir != 0)
		{
			if (CurDir * Flag < 0)
				return false;
			else
				Flag = CurDir;
		}
	}

	return true;
}

void test(const char * vpTestName, const std::vector<SPoint>& vSet, bool vExpect)
{
	std::cout << vpTestName << std::endl;
	if (vExpect == isConvexPolygon(vSet))
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
