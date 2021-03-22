#pragma once
class COne2N
{
public:
	COne2N() { ++m_Index; m_Cnt += m_Index; }
	~COne2N() = default;

	static int getCnt() { return m_Cnt; }
	static void reset() { m_Index = 0; m_Cnt = 0; }

private:
	static int m_Index;
	static int m_Cnt;
};

int COne2N::m_Index = 0;
int COne2N::m_Cnt = 0;