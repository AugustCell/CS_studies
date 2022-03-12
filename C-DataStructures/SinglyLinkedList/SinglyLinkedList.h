/**
 * @file SinglyLinkedList.h
 *
 * @brief Implements the SinglyLinkedList Structure of linked node pointers with helper functions.
 *
 * @ingroup C-DataStructure
 *
 * @author Edward Lon
 * Contact: edwardlon@outlook.com
 *
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include "Node.h"

 /**
  * @brief Contains head and tail nodes, along with a size. Nodes are singly linked.
  */
typedef struct SinglyLinkedList
{
    Node* m_head;
    Node* m_tail;
    uint32_t m_size;
} SinglyLinkedList;

/**
 * @brief Malloc a Singly Linked List.
 *
 * @param sll - A pointer with a level of indirection to an SLL.
 *
 * @return true if successful, false if not.
 */
bool sllInit( SinglyLinkedList** sll )
{
    bool status = false;

    if (*sll != NULL)
    {
        // already initialized!
    }
    else if ((*sll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList))) == NULL)
    {
        // failed to malloc!
    }
    else
    {
        (*sll)->m_head = NULL;
        (*sll)->m_tail = NULL;
        (*sll)->m_head = (*sll)->m_tail;
        (*sll)->m_size = 0;

        status = true;
    }

    return status;
}

/**
 * @brief Retrieves the value from the front of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param nodeValue - A pointer to an unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllGetFront( const SinglyLinkedList* sll, uint32_t* nodeValue )
{
    bool status = false;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!\n\r");
    }
    else if (sll->m_head == NULL)
    {
        fprintf(stderr, "Linked list head is NULL! There's nothing here!\n\r");
    }
    else if (nodeValue == NULL)
    {
        fprintf(stderr, "nodeValue is NULL!\n\r");
    }
    else
    {
        *nodeValue = sll->m_head->m_value;

        status = true;
    }

    return status;
}

/**
 * @brief Retrieves the value from the back of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param nodeValue - A pointer to an unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllGetBack( const SinglyLinkedList* sll, uint32_t* nodeValue )
{
    bool status = false;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!\n\r");
    }
    else if (sll->m_tail == NULL)
    {
        fprintf(stderr, "Linked list head is NULL! There's nothing here!\n\r");
    }
    else if (nodeValue == NULL)
    {
        fprintf(stderr, "nodeValue is NULL!\n\r");
    }
    else
    {
        *nodeValue = sll->m_tail->m_value;

        status = true;
    }

    return status;
}

/**
 * @brief Checks if the list is empty. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param isEmpty - A pointer to a Boolean variable.
 *
 * @return true if successful, false if not.
 */
bool sllCheckEmpty( const SinglyLinkedList* sll, bool* isEmpty )
{
    bool status = false;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!\n\r");
    }
    else
    {
        *isEmpty = sll->m_head == NULL && sll->m_tail == NULL;

        status = true;
    }

    return status;
}

/**
 * @brief Retrieves the size of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param nodeValue - A pointer to an unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllGetSize( const SinglyLinkedList* sll, uint32_t* size )
{
    bool status = false;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!\n\r");
    }
    else
    {
        *size = sll->m_size;

        status = true;
    }

    return status;
}

/**
 * @brief Adds a node to the front of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param value - A constant unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllAddToFront( SinglyLinkedList* sll, const uint32_t value )
{
    bool status = false;
    Node* previousHead = NULL;
    Node* newHead = NULL;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!\n\r");
    }
    else if (nodeInit(&newHead, value) == false)
    {
        fprintf(stderr, "New node failed to initialize!\n\r");
    }
    else if (newHead == NULL)
    {
        fprintf(stderr, "New node is NULL!\n\r");
    }
    else
    {
        // Check if the list is empty
        if (sll->m_head == NULL)
        {
            sll->m_head = sll->m_tail = newHead;
        }
        else
        {
            previousHead = sll->m_head;
            newHead->m_next = previousHead;
            sll->m_head = newHead;
        }

        sll->m_size++;

        status = true;
    }

    return status;
}

/**
 * @brief Inserts a node into a list in ascending order. O(n).
 *
 * @param sll - A pointer to a SLL.
 * @param value - A constant unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllInsert( SinglyLinkedList* sll, const uint32_t value )
{
    bool status = false;
    Node* newNode = NULL;
    Node* currentNode = NULL;
    Node* previousNode = NULL;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!\n\r");
    }
    else if (nodeInit(&newNode, value) == false)
    {
        fprintf(stderr, "New node failed to initialize!\n\r");
    }
    else if (newNode == NULL)
    {
        fprintf(stderr, "New node is NULL!\n\r");
    }
    else
    {
        // Check if the list is empty
        if (sll->m_head == NULL)
        {
            sll->m_head = sll->m_tail = newNode;
        }
        else
        {
            currentNode = sll->m_head;

            // Find location for the node
            while (currentNode != NULL && currentNode->m_value < value)
            {
                previousNode = currentNode;
                currentNode = currentNode->m_next;
            }

            // Check if the previous node is not null, add to the front of the list
            if (previousNode == NULL)
            {
                sll->m_head = newNode;
                newNode->m_next = currentNode;
            }
            else
            {
                previousNode->m_next = newNode;
                newNode->m_next = currentNode;
            }

            // Update the tail pointer
            if (sll->m_tail->m_next != NULL)
            {
                sll->m_tail = sll->m_tail->m_next;
            }
        }

        sll->m_size++;

        status = true;
    }

    return status;
}

/**
 * @brief Adds a node to the back of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param value - A constant unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllAddToBack( SinglyLinkedList* sll, const uint32_t value )
{
    bool status = false;
    Node* newTail = NULL;
    Node* previousTail = NULL;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!\n\r");
    }
    else if (nodeInit(&newTail, value) == false)
    {
        fprintf(stderr, "New node failed to initialize!\n\r");
    }
    else if (newTail == NULL)
    {
        fprintf(stderr, "New node is NULL!\n\r");
    }
    else
    {
        // Check if the list is empty
        if (sll->m_head == NULL)
        {
            sll->m_head = sll->m_tail = newTail;
        }
        else
        {
            sll->m_tail->m_next = newTail;
        }

        // Update tail node
        if (sll->m_tail != NULL)
        {
            sll->m_tail = sll->m_tail->m_next;
        }

        sll->m_size++;

        status = true;
    }

    return status;
}

/**
 * @brief Removes the first node in the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 *
 * @return true if successful, false if not.
 */
bool sllPopFront( SinglyLinkedList* sll )
{
    bool status = false;
    Node* tempNode = NULL;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!");
    }
    else
    {
        if (sll->m_head->m_next == NULL)
        {
            freeNode(sll->m_head);
            sll->m_head = sll->m_tail = NULL;
        }
        else
        {
            tempNode = sll->m_head->m_next;
            sll->m_head->m_value = tempNode->m_value;
            sll->m_head->m_next = tempNode->m_next;

            free(tempNode);
        }

        status = true;
    }

    return status;
}

/**
 * @brief Removes a node from the tail-end of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 *
 * @return true if successful, false if not.
 */
bool sllPopBack( SinglyLinkedList* sll )
{
    bool status = false;
    Node* tempNode = NULL;
    Node* tailNode = NULL;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!");
    }
    else
    {
        if (sll->m_head->m_next == NULL)
        {
            freeNode(sll->m_head);
            sll->m_head = sll->m_tail = NULL;
        }
        else
        {
            tempNode = sll->m_head;

            for (; tempNode != NULL && tempNode->m_next != NULL; tempNode = tempNode->m_next)
            {
                tailNode = tempNode;
            }

            if (tailNode != NULL)
            {
                free(tailNode->m_next);
                tailNode->m_next = NULL;

                sll->m_tail = tailNode;
            }
        }

        status = true;
    }

    return status;
}

/**
 * @brief Reverses the order of the list . O(n).
 *
 * @param sll - A pointer to a SLL.
 *
 * @return true if successful, false if not.
 */
bool sllReverse( SinglyLinkedList* sll )
{
    bool status = false;
    Node* currentNode = NULL;
    Node* previousNode = NULL;
    Node* nextNode = NULL;
    Node* newTail = NULL;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!");
    }
    else if (sll->m_head == NULL)
    {
        fprintf(stderr, "List is empty. Cannot reverse an empty list.\n\r");
    }
    else if (sll->m_head->m_next == NULL)
    {
        fprintf(stderr, "List only has only element. Will not reverse.\n\r");
    }
    else if (nodeInit(&newTail, sll->m_head->m_value) == false)
    {
        fprintf(stderr, "Failed to initialize new tail node!\n\r");
    }
    else if (newTail == NULL)
    {
        fprintf(stderr, "newTail is NULL\n\r");
    }
    else
    {
        currentNode = sll->m_head;

        while (currentNode != NULL)
        {
            // Store the node
            nextNode = currentNode->m_next;

            // Reverse the node
            currentNode->m_next = previousNode;

            previousNode = currentNode;
            currentNode = nextNode;
        }

        sll->m_head = previousNode;
        sll->m_tail = newTail;

        status = true;
    }

    return status;
}

/**
 * @brief Merges two lists together. O(2n).
 *
 * @param lhs - A pointer to the destination list.
 * @param rhs - A pointer to the read-only source list.
 *
 * @return true if successful, false if not.
 */
bool sllMerge( SinglyLinkedList* lhs, const SinglyLinkedList* rhs )
{
    bool status = false;
    Node* leftNode = NULL;
    Node* rightNode = NULL;
    Node* sorted = NULL;
    Node* tempNode = NULL;
    Node* tailNode = NULL;

    if (lhs == NULL)
    {
        fprintf(stderr, "Left list is NULL!\n\r");
    }
    else if (rhs == NULL)
    {
        fprintf(stderr, "Right list is NULL!\n\r");
    }
    else if ((leftNode = lhs->m_head) == NULL)
    {
        fprintf(stderr, "Left list head is NULL!\n\r");
    }
    else if ((rightNode = rhs->m_head) == NULL)
    {
        fprintf(stderr, "Right list head is NULL!\n\r");
    }
    else
    {
        // Init sorted node
        if (leftNode->m_value < rightNode->m_value)
        {
            sorted = leftNode;
        }
        else
        {
            sorted = leftNode;  /// @todo Double check this!

            // Advance pointers
            rightNode = leftNode;
            leftNode = sorted;
        }

        // Compare values from each list
        while (leftNode->m_next != NULL)
        {
            // Move the greater value to the next node
            if (leftNode->m_next->m_value > rightNode->m_value)
            {
                tempNode = leftNode->m_next;
                leftNode->m_next = rightNode;
                rightNode = tempNode;
            }
            leftNode = leftNode->m_next;
        }

        if (leftNode != NULL)
        {
            leftNode->m_next = rightNode;
        }

        tempNode = sorted;

        while (tempNode != NULL)
        {
            tailNode = tempNode;
            tempNode = tempNode->m_next;
        }

        lhs->m_tail = tailNode;
        lhs->m_head = sorted;

        lhs->m_size += rhs->m_size;

        status = true;
    }

    return status;
}

/**
 * @brief Prints the list. O(n)
 *
 * @param sll - A pointer to a read-only SLL.
 *
 * @return true if successful, false if not.
 */
bool sllPrint( const SinglyLinkedList* sll )
{
    bool status = false;

    if (sll == NULL)
    {
        fprintf(stderr, "Linked list is not initialized!");
    }
    else
    {
        for (const Node* currentNode = sll->m_head; currentNode != NULL; currentNode = currentNode->m_next)
        {
            printf("%d->", currentNode->m_value);
        }
        printf("NULL\n");

        status = true;
    }

    return status;
}

#endif // SINGLY_LINKED_LIST_H
