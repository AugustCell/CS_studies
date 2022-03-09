#include "SinglyLinkedList.h"

int main( void )
{
    static SinglyLinkedList sll;

    sllInit((SinglyLinkedList**) & sll);

    sllAddToFront(&sll, 4);
    sllAddToFront(&sll, 3);
    sllAddToFront(&sll, 2);
    sllAddToFront(&sll, 1);

    sllAddToBack(&sll, 5);

    sllAddAtIndex(&sll, 6, 0);
    sllAddAtIndex(&sll, 7, 5);

    sllPrint(&sll);

    freeNode(sll.m_head);

    return 0;
}
