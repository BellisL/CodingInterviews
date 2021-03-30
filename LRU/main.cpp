#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

class CSolution
{
public:
	/**
	 * lru design
	 * @param operators int整型vector<vector<>> the ops
	 * @param k int整型 the k
	 * @return int整型vector
	 */
	std::vector<int> LRU(std::vector<std::vector<int>>& operators, int k)
	{
		// write code here
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
		auto Iter = m_Map.find(vKey);

		if (Iter != m_Map.end())
			__remove(Iter->second);
		__add(vKey, vVal);
	}

	int get(int vKey)
	{
		int Val = -1;
		auto Iter = m_Map.find(vKey);
		if (Iter != m_Map.end())
		{
			Val = __remove(Iter->second);
			__add(vKey, Val);
		}

		return Val;
	}

private:
	struct SNode
	{
		SNode(int vKey, int vVal) : Key(vKey), Value(vVal) {}

		int Key;
		int Value;
	};

	std::list<SNode> m_List;
	typedef std::list<SNode>::iterator NodeIter;
	std::unordered_map<int, NodeIter> m_Map;
	int m_Capacity = 0;

	int __remove(NodeIter& vIter)
	{
		int Key = vIter->Key;
		int Val = vIter->Value;
		m_List.erase(vIter);
		m_Map.erase(Key);

		return Val;
	}

	void __add(int vKey, int vVal)
	{
		m_List.push_front(SNode(vKey, vVal));
		m_Map[vKey] = m_List.begin();

		if (m_List.size() > m_Capacity)
		{
			auto IterLast = m_List.end();
			__remove(--IterLast);
		}
	}
};

void test(const char* vpTestName, std::vector<std::vector<int>>& vSet, int vCap, std::vector<int>& vExpectSet);

int main()
{
	std::vector<std::vector<int>> OperatopnSet = {
		{1,1,1}, {1,2,2}, {1,3,2}, {2,1}, {1,4,4}, {2,2}
	};
	int Cap = 3;
	std::vector<int> ExpectSet = { 1, -1 };
	test("Test1", OperatopnSet, Cap, ExpectSet);

	return 0;
}

void test(const char* vpTestName, std::vector<std::vector<int>>& vSet, int vCap, std::vector<int>& vExpectSet)
{
	std::cout << vpTestName << std::endl;

	CSolution Sol;
	auto Set = Sol.LRU(vSet, vCap);
	if (Set == vExpectSet)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}