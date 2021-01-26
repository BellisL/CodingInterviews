#include <iostream>
#include <stack>

class CStackQueue
{
public:
	CStackQueue() = default;
	~CStackQueue() = default;

	void append2Tail(int vValue);

	bool deleteHead();

private:
	std::stack<int> m_Stack1;
	std::stack<int> m_Stack2;
};

int main()
{
	CStackQueue SQ;
	SQ.append2Tail(0);
	SQ.deleteHead();
	SQ.deleteHead();

	SQ.append2Tail(1);
	SQ.append2Tail(2);
	SQ.deleteHead();
	SQ.append2Tail(3);
	SQ.deleteHead();
	SQ.deleteHead();
	SQ.deleteHead();

	return 0;
}

void CStackQueue::append2Tail(int vValue)
{
	m_Stack1.push(vValue);
	std::cout << "Append: " << vValue << std::endl;
}

bool CStackQueue::deleteHead()
{
	if (m_Stack1.empty() && m_Stack2.empty())
	{
		std::cout << "Queue is empty!" << std::endl;
		return false;
	}

	int Res;
	if (m_Stack2.empty())
	{
		while (!m_Stack1.empty())
		{
			m_Stack2.push(m_Stack1.top());
			m_Stack1.pop();
		}
	}

	Res = m_Stack2.top();
	m_Stack2.pop();

	std::cout << "Delete Head: " << Res << std::endl;

	return true;
}
