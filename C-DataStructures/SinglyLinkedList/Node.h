/**
 * @file Node.h
 *
 * @brief Implements the Node Structure of one auxiliary pointer with helper functions.
 *
 * @ingroup C-DataStructure
 *
 * @author Edward Lon
 * Contact: edwardlon@outlook.com
 *
 */

#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#pragma pack ( push, 4 )
typedef struct Node
{
    uint32_t m_value;
    struct Node* m_next;
} Node;
#pragma pack ( pop )

bool nodeInit(Node** pNode, const uint32_t value)
{
    bool ret = false;

    if (*pNode != NULL)
    {
        // already initialized!
    }
    else if ((*pNode = (Node*)malloc(sizeof(Node))) == NULL)
    {
        // failed to malloc!
    }
    else
    {
        (*pNode)->m_next = NULL;
        (*pNode)->m_value = value;
        ret = true;
    }

    return ret;
}

bool freeNode(Node* n)
{
    bool ret = false;

    if (n == NULL)
    {
        // node is null!
    }
    else
    {
        if (n->m_next != NULL)
        {
            freeNode(n->m_next);
        }

        free(n);

        ret = true;
    }

    return ret;
}

#endif // NODE_H
