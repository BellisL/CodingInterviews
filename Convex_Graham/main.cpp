#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct SPoint
{
	SPoint() : X(0), Y(0) {}
	SPoint(int x, int y) : X(x), Y(y) {}

	int X;
	int Y;
};

SPoint operator-(const SPoint& vL, const SPoint & vR);
bool operator==(const SPoint& vL, const SPoint& vR);
long long cross(const SPoint& vL, const SPoint& vR);
bool isRight(const SPoint& vL, const SPoint& vM, const SPoint& vR);

void convex_graham(std::vector<SPoint>& vSet, std::vector<SPoint>& vCSet);
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
		//不能处理共线情况
		std::cout << "不能处理共线情况" << std::endl;
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

SPoint operator-(const SPoint& vL, const SPoint & vR)
{
	return SPoint(vL.X - vR.X, vL.Y - vR.Y);
}

bool operator==(const SPoint& vL, const SPoint& vR)
{
	return vL.X == vR.X && vL.Y == vR.Y;
}

bool operator<(const SPoint& vL, const SPoint& vR)
{
	return vL.Y == vR.Y ? vL.X < vR.X : vL.Y < vR.Y;
}

long long cross(const SPoint & vL, const SPoint & vR)
{
	return static_cast<long long>(vL.X) * vR.Y - static_cast<long long>(vL.Y) * vR.X;
}

bool isRight(const SPoint& vL, const SPoint& vM, const SPoint& vR)
{
	if (cross(vM - vL, vR - vM) < 0) return true;
	else return false;
}

void convex_graham(std::vector<SPoint>& vSet, std::vector<SPoint>& vCSet)
{
	if (vSet.size() < 3) return;

	std::sort(vSet.begin(), vSet.end());
	//, [](const SPoint& vL, const SPoint& vR) -> bool { return vL.Y < vR.Y; }
	std::stack<SPoint> PStack;
	auto BottomPoint = vSet[0];
	vCSet.push_back(BottomPoint);
	std::sort(vSet.begin(), vSet.end(), [BottomPoint](const SPoint& vL, const SPoint& vR) 
	{ 
		return atan2(static_cast<float>(vL.Y - BottomPoint.Y), static_cast<float>(vL.X - BottomPoint.X))
			< atan2(static_cast<float>(vR.Y - BottomPoint.Y), static_cast<float>(vR.X - BottomPoint.X));
	});

	vCSet.push_back(vSet[1]);
	int TopIndex = 1;

	for (int i = 2; i < vSet.size(); ++i)
	{
		while (TopIndex && isRight(vCSet[TopIndex - 1], vCSet[TopIndex], vSet[i]))
		{
			--TopIndex;
			vCSet.pop_back();
		}
		vCSet.push_back(vSet[i]);
		++TopIndex;
	}
}

void test(const char* vpTestName, std::vector<SPoint>& vSet, std::vector<SPoint>& vExpectSet)
{
	std::cout << vpTestName << std::endl;

	std::vector<SPoint> CSet;
	convex_graham(vSet, CSet);
	std::sort(CSet.begin(), CSet.end());
	std::sort(vExpectSet.begin(), vExpectSet.end());
	if (CSet == vExpectSet)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}