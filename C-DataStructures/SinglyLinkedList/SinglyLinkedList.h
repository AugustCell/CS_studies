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

typedef struct SinglyLinkedList
{
    Node* m_head;
    uint32_t m_size;
} SinglyLinkedList;

bool sllInit( SinglyLinkedList** sll )
{
    bool initStatus = false;

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
        (*sll)->m_size = 0;

        initStatus = true;
    }

    return initStatus;
}

bool sllAddToFront( SinglyLinkedList* sll, const uint32_t value )
{
    bool addStatus = false;
    Node* previousHead = sll->m_head ? sll->m_head : NULL;
    Node* newHead = NULL;

    if (sll == NULL)
    {
        // sll is null!
    }
    else if (nodeInit(&newHead, value) == false)
    {
        // node failed to malloc!
    }
    else if (newHead == NULL)
    {
        // newHead is null!
    }
    else
    {
        newHead->m_next = previousHead;
        sll->m_head = newHead;
        sll->m_size++;

        addStatus = true;
    }

    return addStatus;
}

bool sllAddToBack( SinglyLinkedList* sll, const uint32_t value )
{
    bool addStatus = false;
    Node* newNode = NULL;
    Node* currentNode = NULL;

    if (sll == NULL)
    {
        // sll is null!
    }
    else if (nodeInit(&newNode, value) == false)
    {
        // node failed to malloc!
    }
    else if (newNode == NULL)
    {
        // newNode is null!
    }
    else
    {
        currentNode = sll->m_head ? sll->m_head : NULL;
        if ( currentNode == NULL )
        {
            sllAddToFront(sll, value);
        }
        else
        {
            while (currentNode->m_next != NULL)
            {
                currentNode = currentNode->m_next;
            }
            currentNode->m_next = newNode;
        }

        sll->m_size++;

        addStatus = true;
    }

    return addStatus;
}

bool sllAddAtIndex( SinglyLinkedList* sll, const uint32_t value, const uint32_t index )
{
    bool addStatus = false;
    Node* currentHead = NULL;
    Node* oldNextHead = NULL;
    Node* prevHead = NULL;
    Node* newNode = NULL;

    if (sll == NULL)
    {
        // sll is null!
    }
    else if (sll->m_size < index)
    {
        // index out-of-bounds!
    }
    else if (nodeInit(&newNode, value) == false)
    {
        // failed to malloc newNode
    }
    else if (newNode == NULL)
    {
        // newNode is null!
    }
    else
    {
        currentHead = sll->m_head;
        prevHead = sll->m_head;

        for (uint32_t i = 0; i < index; i++)
        {
            currentHead = currentHead->m_next;
        }

        if (currentHead == NULL)
        {
            sllAddToBack(sll, value);
        }
        else if (currentHead->m_next == NULL)
        {
            currentHead->m_next = newNode;
            sll->m_size++;
        }
        else if (index == 0)
        {
            sllAddToFront(sll, value);
        }
        else
        {
            for (uint32_t i = 0; i < index - 1; i++)
            {
                prevHead = prevHead->m_next;
            }

            newNode->m_next = currentHead->m_next;
            currentHead = newNode;
            prevHead->m_next = newNode;
            sll->m_size++;
        }

        addStatus = true;
    }

    return addStatus;
}

bool sllPrint( const SinglyLinkedList* sll )
{
    bool status = false;

    if (sll == NULL)
    {
        // sll is null!
    }
    else if (sll->m_size == 0)
    {
        // nothing to print!
    }
    else
    {
        for (const Node* currentNode = sll->m_head; currentNode->m_next != NULL; currentNode = currentNode->m_next)
        {
            printf("%d->", currentNode->m_value);
        }
        printf("NULL\n");

        status = true;
    }

    return status;
}

#endif // SINGLY_LINKED_LIST_H
