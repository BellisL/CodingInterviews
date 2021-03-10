#pragma once
#include <set>

typedef std::set<int, std::greater<int>> MaxHeap;
typedef std::set<int, std::less<int>> MinHeap;
typedef std::set<int, std::greater<int>>::iterator MaxHeapIter;
typedef std::set<int, std::less<int>>::iterator MinHeapIter;

class CDoubleHeap
{
public:
	void insert(int vNum);
	float getMedian() const;

private:
	MaxHeap m_MaxHeap;
	MinHeap m_MinHeap;
};