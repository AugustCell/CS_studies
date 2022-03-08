#include "LinkedList.h"

int main() {

	cout << "Hello friends!" << endl;

	LinkedList ll;

	// Normal element insertion
	ll.insert(0);
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);

	// Print normal insertion
	ll.printList();

	// Testing reverse
	ll.reverse();
	ll.printList();
	return 0;
}