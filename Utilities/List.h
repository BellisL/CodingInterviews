#pragma once
#include "UtilitiesExport.h"
#include <memory>

struct UTILITIES_DECLSPEC SListNode
{
	SListNode(int vValue) : Value(vValue) {}

	int Value;
	std::shared_ptr<SListNode> pListNode = nullptr;
};

void UTILITIES_DECLSPEC printList(std::shared_ptr<SListNode> vpNode);

class UTILITIES_DECLSPEC CList
{
public:
	CList(std::shared_ptr<SListNode> vpHead = nullptr) : m_pHead(vpHead) {}
	~CList() {}

	const std::shared_ptr<SListNode> getHeadPtr() const { return m_pHead; }
	//这里的设计很垃圾
	void setHead(std::shared_ptr<SListNode> vpHead) { _ASSERTE(vpHead); m_pHead = vpHead; };
	bool insert(int vCurValue, int vValue);
	void insert(std::shared_ptr<SListNode> vpCur, std::shared_ptr<SListNode> vpNode);
	void add2Tail(int vValue);
	void removeNode(int vValue);
	void removeNode_O1(std::shared_ptr<SListNode> vpNode);
	void removeDuplicates();
	void printList() const;

private:
	std::shared_ptr<SListNode> m_pHead = nullptr;
};