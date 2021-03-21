#include "QMax.h"

int CQMax::max()
{
	if (m_Max.empty()) throw std::runtime_error("Queue is empty!");

	return m_Max.front().Num;
}

void CQMax::push_back(int vNum)
{
	while (!m_Max.empty() && vNum >= m_Max.back().Num)
		m_Max.pop_back();

	SData Data{ vNum, m_CurIndex++ };
	m_Data.push_back(Data);
	m_Max.push_back(Data);
}

void CQMax::pop_front()
{
	if (m_Max.empty()) return;

	if (m_Max.front().Index == m_Data.front().Index)
		m_Max.pop_front();

	m_Data.pop_front();
}
