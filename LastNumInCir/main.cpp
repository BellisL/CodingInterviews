#include <iostream>
#include <list>

int lastRemaining_1(int vN, int vM);
int lastRemaining_3(int vN, int vM);
void test(const char* vpTestName, int vN, int vM, int vExpect);

int main()
{
	test("Test1", 5, 3, 3);
	test("Test2", 5, 2, 2);
	test("Test3", 6, 7, 4);
	test("Test4", 6, 6, 3);
	test("Test5", 4000, 997, 1027);
	test("Test6", 0, 0, -1);

	return 0;
}

int lastRemaining_1(int vN, int vM)
{
	if (vN < 1 || vM < 1) return -1;

	std::list<int> List;
	for (int i = 0; i < vN; ++i)
		List.push_back(i);

	auto Iter = List.begin();
	while (List.size() > 1)
	{
		for (int k = 1; k < vM; ++k)
		{
			++Iter;
			if (Iter == List.end())
				Iter = List.begin();
		}

		/*auto IterCur = ++Iter;

		if (IterCur == List.end())
			IterCur = List.begin();

		--Iter;
		List.erase(Iter);
		Iter = IterCur;*/
		auto IterCur = Iter++;

		if (Iter == List.end())
			Iter = List.begin();
		List.erase(IterCur);
	}

	return *Iter;
}

int lastRemaining_3(int vN, int vM)
{
	if (vN < 1 || vM < 1) return -1;

	int Survive = 0;
	for (int i = 2; i <= vN; ++i)
		Survive = (Survive + vM) % i;

	return Survive;
}

void test(const char * vpTestName, int vN, int vM, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Res = lastRemaining_3(vN, vM);
	if (Res == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
