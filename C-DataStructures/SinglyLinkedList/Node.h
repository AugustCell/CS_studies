/**
 * @file Node.h
 *
 * @brief Defines the Node Structure of one auxiliary pointer with helper functions.
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
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
    extern "C" {
#endif

#pragma pack ( push, 4 )
/**
 * @brief A node containing a value and a next pointer to a node. Struct is 4-byte aligned.
 */
typedef struct Node
{
    uint32_t m_value;
    struct Node* m_next;
} Node;
#pragma pack ( pop )

/**
 * @brief Initializes a node with a value.
 * @param pNode - A pointer to a Node with a level of indirection.
 * @param value - A read-only unsigned integer.
 * @return true if successful, false if not
 */
bool nodeInit(Node** pNode, const uint32_t value);

/**
 * @brief Initializes a node with a value and a next node.
 * @param pNode - A pointer to a Node with a level of indirection.
 * @param value - A read-only unsigned integer.
 * @param n - A pointer to another node.
 * @return true if successful, false if not
 */
bool nodeInitAndLink(Node** pNode, const uint32_t value, Node* n);

/**
 * @brief Recursively frees linked nodes.
 * @param n - A Pointer a node.
 * @return true if successful, false if not
 */
bool freeNode(Node* n);

#ifdef __cplusplus
    }
#endif

#endif // NODE_H
