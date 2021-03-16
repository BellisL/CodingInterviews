#include <iostream>
#include <vector>

int getTimesofK(const std::vector<int>& vSet, int vNum);
//https://www.it610.com/article/1278282083898245120.htm
int lower_bound_01(const std::vector<int>& vSet, int vNum);
int lower_bound_02(const std::vector<int>& vSet, int vNum);
int upper_bound_01(const std::vector<int>& vSet, int vNum);
int upper_bound_02(const std::vector<int>& vSet, int vNum);
void test(const char* vpTestName, const std::vector<int>& vSet, int vNum, int vExpect);

int main()
{
	{
		std::vector<int> Set = { 1, 2, 3, 3, 3, 3, 4, 5 };
		test("Test1", Set, 3, 4);
	}

	{
		std::vector<int> Set = { 3, 3, 3, 3, 4, 5 };
		test("Test2", Set, 3, 4);
	}

	{
		std::vector<int> Set = { 1, 2, 3, 3, 3, 3 };
		test("Test3", Set, 3, 4);
	}

	{
		std::vector<int> Set = { 1, 3, 3, 3, 3, 4 };
		test("Test4", Set, 2, 0);
	}

	{
		std::vector<int> Set = { 1, 3, 3, 3, 3, 4 };
		test("Test5", Set, 0, 0);
	}

	{
		std::vector<int> Set = { 1, 3, 3, 3, 3, 4 };
		test("Test6", Set, 5, 0);
	}

	{
		std::vector<int> Set = { 3, 3, 3, 3 };
		test("Test7", Set, 3, 4);
	}

	{
		std::vector<int> Set = { 3, 3, 3, 3 };
		test("Test8", Set, 4, 0);
	}

	{
		std::vector<int> Set = { 1 };
		test("Test9", Set, 1, 1);
	}

	{
		std::vector<int> Set = { 1 };
		test("Test10", Set, 2, 0);
	}

	{
		std::vector<int> Set = { };
		test("Test11", Set, 1, 0);
	}

	return 0;
}

int getTimesofK(const std::vector<int>& vSet, int vNum)
{
	if(vSet.empty()) throw std::runtime_error("Invalid input!");

	int LowerBound1 = lower_bound_01(vSet, vNum);
	int UpperBound1 = upper_bound_01(vSet, vNum);
	std::cout << LowerBound1 << "\t";
	std::cout << UpperBound1 << "\t";

	int LowerBound2 = lower_bound_02(vSet, vNum);
	int UpperBound2 = upper_bound_02(vSet, vNum);
	std::cout << LowerBound2 << "\t";
	std::cout << UpperBound2 << "\t";

	std::cout << std::endl;

	return UpperBound1 - LowerBound1 + 1;
}

int lower_bound_01(const std::vector<int>& vSet, int vNum)
{
	//����ҿ��Ķ����½����
	int Low = 0;
	int High = vSet.size();
	while (Low < High)
	{
		int Mid = Low + ((High - Low) >> 1);
		vNum <= vSet[Mid] ? High = Mid : Low = Mid + 1;
	}

	//û�ҵ��Ľ����
	//1������������Ŀ��С������vNum.size()��Խ�羯��;
	//2������������Ŀ��󣬷���0��
	return Low;
}

int lower_bound_02(const std::vector<int>& vSet, int vNum)
{
	//����ұյĶ����½����
	int Low = 0;
	int High = vSet.size() - 1;//ע������
	while (Low <= High)//ע������
	{
		int Mid = Low + ((High - Low) >> 1);
		vNum <= vSet[Mid] ? High = Mid - 1 : Low = Mid + 1;//ע������
	}

	//û�ҵ��Ľ����
	//1������������Ŀ��С������vNum.size()��Խ�羯��;
	//2������������Ŀ��󣬷���0��
	return Low;
}

int upper_bound_01(const std::vector<int>& vSet, int vNum)
{
	//����ҿ��Ķ����Ͻ����
	int Low = 0;
	int High = vSet.size();
	while (Low < High)
	{
		int Mid = Low + ((High - Low) >> 1);
		vNum < vSet[Mid] ? High = Mid : Low = Mid + 1;
	}

	//û�ҵ��Ľ����
	//1������������Ŀ��С������vNum.size() - 1;
	//2������������Ŀ��󣬷���-1��Խ�羯�档
	return --Low;///ע������
}

int upper_bound_02(const std::vector<int>& vSet, int vNum)
{
	//����ұյĶ����Ͻ����
	int Low = 0;
	int High = vSet.size() - 1;//ע������
	while (Low <= High)//ע������
	{
		int Mid = Low + ((High - Low) >> 1);
		vNum < vSet[Mid] ? High = Mid - 1 : Low = Mid + 1;//ע������
	}

	//û�ҵ��Ľ����
	//1������������Ŀ��С������vNum.size() - 1;
	//2������������Ŀ��󣬷���-1��Խ�羯�档
	return --Low;///ע������
}

void test(const char * vpTestName, const std::vector<int>& vSet, int vNum, int vExpect)
{
	std::cout << vpTestName << std::endl;

	try
	{
		auto TimesK = getTimesofK(vSet, vNum);
		if (TimesK == vExpect)
			std::cout << "PASSED.\n";
		else if(vExpect == 0 && TimesK <= 0)
			std::cout << "PASSED.\n";
		else
			std::cout << "FAILED.\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}
