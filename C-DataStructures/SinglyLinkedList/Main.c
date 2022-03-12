#include "SinglyLinkedList.h"

int main( void )
{
    SinglyLinkedList* sllA = NULL;
    SinglyLinkedList* sllB = NULL;

    sllInit(&sllA);
    sllInit(&sllB);

    // Populate A
    sllAddToFront(sllA, 8);
    sllAddToFront(sllA, 6);
    sllAddToFront(sllA, 4);
    sllAddToFront(sllA, 2);

    sllAddToBack(sllA, 10);
    sllAddToBack(sllA, 12);
    sllAddToBack(sllA, 14);
    sllAddToBack(sllA, 16);

    sllInsert(sllA, 15);

    sllPrint(sllA);

    /*sllPopFront(sllA);
    sllPopBack(sllA);*/

    sllPrint(sllA);

    //sllReverse(sllA);

    sllPrint(sllA);

    // Populate B
    sllAddToFront(sllB, 12);
    sllAddToFront(sllB, 9);
    sllAddToFront(sllB, 6);
    sllAddToFront(sllB, 3);

    sllAddToBack(sllB, 15);
    sllAddToBack(sllB, 18);
    sllAddToBack(sllB, 21);
    sllAddToBack(sllB, 24);

    sllInsert(sllB, 17);

    sllPrint(sllB);

    // Merge List
    sllMerge(sllA, sllB);

    sllPrint(sllA);

    freeNode(sllA->m_head);
    free(sllA);
    sllA = NULL;

    free(sllB);
    sllB = NULL;

    return 0;
}
