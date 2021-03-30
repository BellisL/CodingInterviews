#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

class CLFUCache
{
public:
	/**
	 * lfu design
	 * @param operators int整型vector<vector<>> ops
	 * @param k int整型 the k
	 * @return int整型vector
	 */
	std::vector<int> LFU(std::vector<std::vector<int>>& operators, int k)
	{
		// write code here
		if (k <= 0 || operators.empty()) return {};
		m_Capacity = k;

		std::vector<int> AnsSet;
		for (const auto& Input : operators)
		{
			if (Input[0] == 1)
				set(Input[1], Input[2]);
			else
				AnsSet.push_back(get(Input[1]));
		}

		return std::move(AnsSet);
	}

	void set(int vKey, int vVal)
	{
		if (m_Capacity == 0) return;

		auto KeyTableIter = m_KeyTable.find(vKey);
		if (KeyTableIter == m_KeyTable.end())
		{
			//缓存满，需要删除
			if (m_KeyTable.size() == m_Capacity)
			{
				auto FreqTableIter = m_FreqTable[m_MinFreq].back();
				m_KeyTable.erase(FreqTableIter.Key);
				m_FreqTable[m_MinFreq].pop_back();
				if (m_FreqTable[m_MinFreq].empty())
				{
					m_FreqTable.erase(m_MinFreq);
				}
			}
			
			m_FreqTable[1].push_front(SNode(vKey, vVal, 1));
			m_KeyTable[vKey] = m_FreqTable[1].begin();
			m_MinFreq = 1;
		}
		else
		{
			//会覆盖原键所对应的值，所以使用频率对应的是键
			__update(vKey, vVal, KeyTableIter->second);
		}
	}

	int get(int vKey)
	{
		int Val = -1;
		if (m_Capacity == 0) return Val;
		auto KeyTableIter = m_KeyTable.find(vKey);
		if (KeyTableIter == m_KeyTable.end())
			return Val;

		Val = __update(vKey, KeyTableIter->second);

		return Val;
	}

private:
	struct SNode
	{
		SNode(int vKey, int vVal, int vFreq) 
			: Key(vKey), Value(vVal), Freq(vFreq) {}

		int Key;
		int Value;
		int Freq;
	};

	typedef std::list<SNode>::iterator NodeIter;

	int m_Capacity = 0;
	int m_MinFreq = 0;
	std::unordered_map<int, std::list<SNode>> m_FreqTable;
	std::unordered_map<int, NodeIter> m_KeyTable;

	int __update(int vKey, NodeIter& vNodeIter)
	{
		int Val = vNodeIter->Value;
		__update(vKey, Val, vNodeIter);

		return Val;
	}

	void __update(int vKey, int vVal, NodeIter& vNodeIter)
	{
		int Freq = vNodeIter->Freq;

		m_FreqTable[Freq].erase(vNodeIter);
		if (m_FreqTable[Freq].empty())
		{
			m_FreqTable.erase(Freq);
			if (m_MinFreq == Freq)
				++m_MinFreq;
		}
		m_FreqTable[Freq + 1].push_front(SNode(vKey, vVal, Freq + 1));
		m_KeyTable[vKey] = m_FreqTable[Freq + 1].begin();
	}
};

void test(const char* vpTestName, std::vector<std::vector<int>>& vSet, int vCap, std::vector<int>& vExpectSet);

int main()
{
	std::vector<std::vector<int>> OperatopnSet = {
		{1,1,1}, {1,2,2}, {1,3,2}, {1,2,4}, {1,3,5}, {2,2}, {1,4,4}, {2,1}
	};
	int Cap = 3;
	std::vector<int> ExpectSet = { 4, -1 };
	test("Test1", OperatopnSet, Cap, ExpectSet);

	return 0;
}

void test(const char* vpTestName, std::vector<std::vector<int>>& vSet, int vCap, std::vector<int>& vExpectSet)
{
	std::cout << vpTestName << std::endl;

	CLFUCache LFUCache;
	auto Set = LFUCache.LFU(vSet, vCap);
	if (Set == vExpectSet)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}