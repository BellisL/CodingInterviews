#include "DoubleVec.h"

void CDoubleVec::insert(int vNum)
{
	if (!((m_MinSet.size() + m_MaxSet.size()) & 1))
	{
		if (!m_MaxSet.empty() && vNum < m_MaxSet[0])
		{
			m_MaxSet.push_back(vNum);
			std::push_heap(m_MaxSet.begin(), m_MaxSet.end(), std::less<int>());

			vNum = m_MaxSet[0];

			std::pop_heap(m_MaxSet.begin(), m_MaxSet.end(), std::less<int>());
			m_MaxSet.pop_back();
		}

		m_MinSet.push_back(vNum);
		std::push_heap(m_MinSet.begin(), m_MinSet.end(), std::greater<int>());
	}
	else
	{
		if (!m_MinSet.empty() && vNum > m_MinSet[0])
		{
			m_MinSet.push_back(vNum);
			std::push_heap(m_MinSet.begin(), m_MinSet.end(), std::greater<int>());

			vNum = m_MinSet[0];

			std::pop_heap(m_MinSet.begin(), m_MinSet.end(), std::greater<int>());
			m_MinSet.pop_back();
		}

		m_MaxSet.push_back(vNum);
		std::push_heap(m_MaxSet.begin(), m_MaxSet.end(), std::less<int>());

	}
}

float CDoubleVec::getMedian() const
{
	auto Size = m_MaxSet.size() + m_MinSet.size();
	if (!Size)
		throw std::runtime_error("No medians are available!");

	float Median = 0;
	if (Size & 1)
		Median = m_MinSet[0];
	else
		Median = (static_cast<float>(m_MaxSet[0]) + m_MinSet[0]) / 2;

	return Median;

	return 0.0f;
}
