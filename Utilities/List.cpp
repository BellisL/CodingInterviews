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
	else if (m_pHead == vpNode)
	{
		m_pHead = nullptr;
	}
	else
	{
		auto pHead = m_pHead;
		while (pHead->pListNode != vpNode)
			pHead = pHead->pListNode;

		pHead->pListNode = nullptr;
	}
}

void CList::removeDuplicates()
{
	if (!m_pHead) return;

	auto pHead = m_pHead;
	std::shared_ptr<SListNode> pPre = nullptr;
	while (pHead)
	{
		bool Flag = false;
		while (pHead->pListNode && pHead->Value == pHead->pListNode->Value)
		{
			Flag = true;
			removeNode_O1(pHead->pListNode);
		}

		if (!Flag)
		{
			pHead = pHead->pListNode;
		}
		else
		{
			pPre = pHead;
			pHead = pHead->pListNode;
			if (pPre == m_pHead) 
				m_pHead = pPre->pListNode;
			else
				removeNode_O1(pPre);
		}
	}
}

void CList::printList() const
{
	if (!m_pHead)
	{
		std::cout << "Empty list!\n";
		return;
	}

	auto pHead = m_pHead;
	while (pHead)
	{
		std::cout << pHead->Value << "\t";
		pHead = pHead->pListNode;
	}

	std::cout << std::endl;
}

void UTILITIES_DECLSPEC printList(std::shared_ptr<SListNode> vpNode)
{
	if (!vpNode)
	{
		std::cout << "Empty list!\n";
		return;
	}

	auto pHead = vpNode;
	while (pHead)
	{
		std::cout << pHead->Value << "\t";
		pHead = pHead->pListNode;
	}

	std::cout << std::endl;
}
