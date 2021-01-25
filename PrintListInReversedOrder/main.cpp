#include <iostream>
#include <stack>

struct SListNode
{
	SListNode(int vValue) : Value(vValue) {}

	int Value;
	std::shared_ptr<SListNode> pNext = nullptr;
};

class CLinkedList
{
public:
	CLinkedList() = default;
	~CLinkedList() { m_pHead = nullptr; };

	bool add2Tail(int value);
	void printListInReversedOrder();

private:
	std::shared_ptr<SListNode> m_pHead = nullptr;
};

int main()
{
	CLinkedList List1;
	List1.add2Tail(0);
	List1.add2Tail(1);
	List1.add2Tail(2);
	List1.add2Tail(3);
	List1.add2Tail(4);

	List1.printListInReversedOrder();

	CLinkedList List2;

	List2.printListInReversedOrder();

	CLinkedList List3;
	List3.add2Tail(0);

	List3.printListInReversedOrder();

	return 0;
}

bool CLinkedList::add2Tail(int value)
{
	std::shared_ptr<SListNode> pNode = std::make_shared<SListNode>(value);

	if (!m_pHead)
	{
		m_pHead = pNode;
	}
	else
	{
		auto pTemp = m_pHead;
		while (pTemp->pNext)
		{
			pTemp = pTemp->pNext;
		}

		pTemp->pNext = pNode;
	}

	return true;
}

void CLinkedList::printListInReversedOrder()
{
	if (!m_pHead)
	{
		std::cout << "Empty List!" << std::endl;
		return;
	}

	auto pTemp = m_pHead;
	std::stack<int> ListValueStack;

	while (pTemp)
	{
		ListValueStack.push(pTemp->Value);
		pTemp = pTemp->pNext;
	}

	while (!ListValueStack.empty())
	{
		std::cout << ListValueStack.top() << " ";
		ListValueStack.pop();
	}

	std::cout << std::endl;
}
