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
	sLl.insert(1);
	sLl.insert(2);
	sLl.insert(3);
	sLl.insert(4);
	sLl.insert(5);

	// Print normal insertion (S_LL)
	sLl.printList();

	// Testing reverse (S_LL)
	sLl.reverse();
	sLl.printList();

    // Testing middle element (S_LL)
    cout << endl << "This is middle element: " << sLl.getMiddle() << endl;

    // Testing deleting of element from the lists (S_LL)
    sLl.deleteNode(3);
    cout << "After deleting node with value 3" << endl;
    sLl.printList();

	// Testing deleting front and back elements (S_LL)
	sLl.removeFromFront();
	sLl.removeFromBack();
	cout << "After deleting nodes at front and back" << endl;
	sLl.printList();

	// Normal element insertion (D_LL)
	dLl.insert(1);
	dLl.insert(2);
	dLl.insert(3);
	dLl.insert(4);
	dLl.insert(5);

	// Print normal insertion (D_LL)
	dLl.printList();

	// Testing reverse (D_LL)
	dLl.reverse();
	dLl.printList();

    // Testing middle element (D_LL)
    cout << endl << "This is middle element: " << sLl.getMiddle() << endl;

    // Testing deleting of element from the lists
    dLl.deleteNode(3);
    cout << "After deleting node with value 3" << endl;
    dLl.printList();

	// Testing deleting front and back elements (S_LL)
	dLl.removeFromFront();
	dLl.removeFromBack();
	cout << "After deleting nodes at front and back" << endl;
	dLl.printList();

    // Free both lists for no memory leaks.
    dLl.destroyList();
    sLl.destroyList();

	// Dump memory to check for leaks.
	_CrtDumpMemoryLeaks();
	return 0;
}