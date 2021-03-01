#include "List.h"

int main()
{
	CList List1;
	List1.add2Tail(0);
	List1.printList();

	_ASSERTE(List1.insert(0, 1));
	_ASSERTE(List1.insert(0, -1));
	_ASSERTE(!List1.insert(2, 3));
	List1.printList();

	List1.add2Tail(2);
	List1.add2Tail(3);
	List1.add2Tail(4);
	List1.add2Tail(5);
	List1.removeNode(-1);
	List1.printList();

	auto pHead = List1.getHeadPtr();
	auto pNew6 = std::make_shared<SListNode>(6);
	List1.insert(pHead, pNew6);
	auto pNew7 = std::make_shared<SListNode>(7);
	List1.insert(pNew6, pNew7);
	List1.printList();
	List1.removeNode_O1(pNew6);
	List1.printList();

	return 0;
}