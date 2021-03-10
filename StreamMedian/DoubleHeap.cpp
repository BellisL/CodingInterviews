#include "DoubleHeap.h"

void CDoubleHeap::insert(int vNum)
{
	MaxHeapIter MaxHeapIter = m_MaxHeap.begin();
	MinHeapIter MinHeapIter = m_MinHeap.begin();
	if (!((m_MinHeap.size() + m_MaxHeap.size()) & 1))
	{
		if (!m_MinHeap.empty() && vNum > *MinHeapIter)
		{
			int Temp = *MinHeapIter;
			m_MinHeap.erase(MinHeapIter);
			m_MinHeap.insert(vNum);

			m_MaxHeap.insert(Temp);
		}
		else
			m_MaxHeap.insert(vNum);		
	}
	else
	{
		if (!m_MaxHeap.empty() && vNum < *MaxHeapIter)
		{
			int Temp = *MaxHeapIter;
			m_MaxHeap.erase(MaxHeapIter);
			m_MaxHeap.insert(vNum);

			m_MinHeap.insert(Temp);
		}
		else
			m_MinHeap.insert(vNum);
	}
}

float CDoubleHeap::getMedian() const
{
	auto Size = m_MaxHeap.size() + m_MinHeap.size();
	if (!Size)
		throw std::runtime_error("No medians are available!");

	float Median = 0;
	if (Size & 1)
		Median = *m_MaxHeap.begin();
	else
		Median = (static_cast<float>(*m_MaxHeap.begin()) + *m_MinHeap.begin()) / 2;
	
	return Median;
}
