/**
 * @file Node.c
 *
 * @brief Implements the Node Structure of one auxiliary pointer with helper functions.
 *
 * @ingroup C-DataStructure
 *
 * @author Edward Lon
 * Contact: edwardlon@outlook.com
 *
 */

#include "Node.h"

/* See header for documentation */
bool nodeInit(Node** pNode, const uint32_t value)
{
    bool ret = false;

    if (*pNode != NULL)
    {
        fprintf(stderr, "Node already initialized!");
    }
    else if ((*pNode = (Node*)malloc(sizeof(Node))) == NULL)
    {
        fprintf(stderr, "Node failed to malloc!");
    }
    else
    {
        (*pNode)->m_next = NULL;
        (*pNode)->m_value = value;

        ret = true;
    }

    return ret;
}

/* See header for documentation */
bool nodeInitAndLink(Node** pNode, const uint32_t value, Node* n)
{
    bool ret = false;

    if (*pNode != NULL)
    {
        fprintf(stderr, "pNode already initialized!\n\r");
    }
    else if ((*pNode = (Node*)malloc(sizeof(Node))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n\r");
    }
    else if (n == NULL)
    {
        fprintf(stderr, "Node n is null!\n\r");
    }
    else
    {
        (*pNode)->m_next = n;
        (*pNode)->m_value = value;

        ret = true;
    }

    return ret;
}

/* See header for documentation */
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
