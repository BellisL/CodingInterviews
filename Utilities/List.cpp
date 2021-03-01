#include "List.h"
#include <iostream>

bool CList::insert(int vCurValue, int vValue)
{
	auto pHead = m_pHead;
	if (!pHead) return false;
	else
	{
		while (pHead && pHead->Value != vCurValue)
			pHead = pHead->pListNode;

		if (!pHead) return false;
		else
		{
			auto p = std::make_shared<SListNode>(vValue);
			auto pTemp = pHead->pListNode;
			pHead->pListNode = p;
			p->pListNode = pTemp;
		}
	}
		
	return true;
}

void CList::insert(std::shared_ptr<SListNode> vpCur, std::shared_ptr<SListNode> vpNode)
{
	//是不是要验证一下第一个指针在链表里？
	_ASSERTE(vpCur && vpNode);

	auto Temp = vpCur->pListNode;
	vpCur->pListNode = vpNode;
	vpNode->pListNode = Temp;
}

void CList::add2Tail(int vValue)
{
	auto p = std::make_shared<SListNode>(vValue);

	if (m_pHead == nullptr)
		m_pHead = p;
	else
	{
		auto pHead = m_pHead;
		while (pHead->pListNode)
			pHead = pHead->pListNode;

		pHead->pListNode = p;
	}
}

void CList::removeNode(int vValue)
{
	if (!m_pHead) return;

	if (m_pHead->Value == vValue)
	{
		m_pHead = m_pHead->pListNode;
	}
	else
	{
		auto pHead = m_pHead;
		while (pHead->pListNode && pHead->pListNode->Value != vValue)
			pHead = pHead->pListNode;

		if (pHead->pListNode && pHead->pListNode->Value == vValue)
			pHead->pListNode = pHead->pListNode->pListNode;
	}
}

void CList::removeNode_O1(std::shared_ptr<SListNode> vpNode)
{
	if (vpNode->pListNode)
	{
		auto pTemp = vpNode->pListNode;
		vpNode->Value = pTemp->Value;
		vpNode->pListNode = pTemp->pListNode;
	}
	else
	{
		removeNode(vpNode->Value);
	}
}

void CList::printList() const
{
	auto pHead = m_pHead;
	while (pHead)
	{
		std::cout << pHead->Value << "\t";
		pHead = pHead->pListNode;
	}

	std::cout << std::endl;
}
