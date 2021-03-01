#include "List.h"

int main()
{
	CList List1;
	List1.add2Tail(0);
	_ASSERTE(List1.insert(0, 0));
	List1.add2Tail(1);
	List1.add2Tail(2);
	_ASSERTE(List1.insert(2, 2));
	List1.add2Tail(3);
	List1.add2Tail(4);
	List1.add2Tail(5);
	_ASSERTE(List1.insert(5, 5));
	List1.printList();
	List1.removeDuplicates();
	List1.printList();

	CList List2;
	List2.add2Tail(0);
	List2.add2Tail(0);
	List2.add2Tail(0);
	List2.add2Tail(0);
	List2.removeNode_O1(List2.getHeadPtr());
	List2.printList();
	List2.removeDuplicates();
	List2.printList();

	return 0;
}