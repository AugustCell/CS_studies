#define _CRTDBG_MAP_ALLOC
#include "DoublyLinkedList.h"
#include "SinglyLikedList.hpp"
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main() {

	cout << "Hello friends!" << endl;

	DoublyLinkedList dLl;  //This is our implemented doubly linked list
    SinglyLinkedList sLl;  //This is our implemented singly linked list
	
    // Normal element insertion (S_LL)
	sLl.insert(0);
	sLl.insert(1);
	sLl.insert(2);
	sLl.insert(3);
	sLl.insert(4);

	// Print normal insertion (S_LL)
	sLl.printList();

	// Testing reverse (S_LL)
	sLl.reverse();
	sLl.printList();

    // Testing middle element (S_LL)
    cout << endl << "This is middle element: " << sLl.getMiddle() << endl;

	// Normal element insertion (D_LL)
	dLl.insert(0);
	dLl.insert(1);
	dLl.insert(2);
	dLl.insert(3);
	dLl.insert(4);

	// Print normal insertion (D_LL)
	dLl.printList();

	// Testing reverse (D_LL)
	dLl.reverse();
	dLl.printList();

    // Testing middle element (D_LL)
    cout << endl << "This is middle element: " << sLl.getMiddle() << endl;

    // Free whole list
    dLl.destroyList();
    sLl.destroyList();

	_CrtDumpMemoryLeaks();
	return 0;
}