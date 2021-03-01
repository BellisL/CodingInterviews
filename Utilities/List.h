#pragma once
#include "UtilitiesExport.h"
#include <memory>

struct UTILITIES_DECLSPEC SListNode
{
	SListNode(int vValue) : Value(vValue) {}

	int Value;
	std::shared_ptr<SListNode> pListNode = nullptr;
};

class UTILITIES_DECLSPEC CList
{
public:
	CList(std::shared_ptr<SListNode> vpHead = nullptr) : m_pHead(vpHead) {}
	~CList() {}

	std::shared_ptr<SListNode> getHeadPtr() { return m_pHead; }
	bool insert(int vCurValue, int vValue);
	void insert(std::shared_ptr<SListNode> vpCur, std::shared_ptr<SListNode> vpNode);
	void add2Tail(int vValue);
	void removeNode(int vValue);
	void removeNode_O1(std::shared_ptr<SListNode> vpNode);
	void printList() const;

private:
	std::shared_ptr<SListNode> m_pHead = nullptr;
};