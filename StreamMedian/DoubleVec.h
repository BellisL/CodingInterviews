#pragma once
#include <vector>
#include <algorithm>

class CDoubleVec
{
public:
	void insert(int vNum);
	float getMedian() const;

private:
	std::vector<int> m_MinSet;
	std::vector<int> m_MaxSet;
};