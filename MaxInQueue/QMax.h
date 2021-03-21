#pragma once
#include <deque>

class CQMax
{
public:
	CQMax() : m_CurIndex(0) {}
	~CQMax() = default;

	int max();
	void push_back(int vNum);
	void pop_front();

private:
	struct SData
	{
		int Num;
		int Index;
	};

	std::deque<SData> m_Data;
	std::deque<SData> m_Max;
	int m_CurIndex;
};
