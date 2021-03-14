#include <iostream>
#include <vector>

const int g_CharNum = 26;

class CCharStatistic
{
public:
	CCharStatistic() : m_Appear(g_CharNum, -1) {};
	~CCharStatistic() = default;

	void insert(char vCh);
	char firstAppearingOnce() const;

private:
	int m_Index = 0;
	std::vector<int> m_Appear;
};

void test(const char* vpTestName, const CCharStatistic& vCS, char vExpect);

int main()
{
	CCharStatistic CS;

	test("Test1", CS, '\0');

	CS.insert('g');
	test("Test2", CS, 'g');

	CS.insert('o');
	test("Test3", CS, 'g');

	CS.insert('o');
	test("Test4", CS, 'g');

	CS.insert('g');
	test("Test5", CS, '\0');

	CS.insert('l');
	test("Test6", CS, 'l');

	CS.insert('e');
	test("Test7", CS, 'l');

	return 0;
}

void CCharStatistic::insert(char vCh)
{
	if (m_Appear[vCh - 'a'] == -1)
		m_Appear[vCh - 'a'] = m_Index;
	else if (m_Appear[vCh - 'a'] >= 0)
		m_Appear[vCh - 'a'] = -2;

	++m_Index;
}

char CCharStatistic::firstAppearingOnce() const
{
	char FirstCh = '\0';
	int Min = INT_MAX;

	for (int i = 0; i < m_Appear.size(); ++i)
	{
		if (m_Appear[i] >= 0 && m_Appear[i] < Min)
		{
			FirstCh = i + 'a';
			Min = m_Appear[i];
		}
	}

	return FirstCh;
}

void test(const char * vpTestName, const CCharStatistic & vCS, char vExpect)
{
	std::cout << vpTestName << std::endl;

	char Res = vCS.firstAppearingOnce();
	if (Res == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
