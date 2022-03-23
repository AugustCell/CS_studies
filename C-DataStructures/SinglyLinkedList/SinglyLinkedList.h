/**
 * @file SinglyLinkedList.h
 *
 * @brief Defines the SinglyLinkedList Structure of linked node pointers with helper functions.
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

#ifdef __cplusplus
extern "C" {
#endif

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
bool sllInit( SinglyLinkedList** sll );

/**
 * @brief Retrieves the value from the front of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param nodeValue - A pointer to an unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllGetFront( const SinglyLinkedList* sll, uint32_t* nodeValue );

/**
 * @brief Retrieves the value from the back of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param nodeValue - A pointer to an unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllGetBack( const SinglyLinkedList* sll, uint32_t* nodeValue );

/**
 * @brief Checks if the list is empty. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param isEmpty - A pointer to a Boolean variable.
 *
 * @return true if successful, false if not.
 */
bool sllCheckEmpty( const SinglyLinkedList* sll, bool* isEmpty );

/**
 * @brief Retrieves the size of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param size - A pointer to an unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllGetSize( const SinglyLinkedList* sll, uint32_t* size );

/**
 * @brief Adds a node to the front of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param value - A constant unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllAddToFront( SinglyLinkedList* sll, uint32_t value );

/**
 * @brief Inserts a node into a list in ascending order. O(n).
 *
 * @param sll - A pointer to a SLL.
 * @param value - A constant unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllInsert( SinglyLinkedList* sll, uint32_t value );

/**
 * @brief Adds a node to the back of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 * @param value - A constant unsigned integer variable.
 *
 * @return true if successful, false if not.
 */
bool sllAddToBack( SinglyLinkedList* sll, uint32_t value );

/**
 * @brief Removes the first node in the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 *
 * @return true if successful, false if not.
 */
bool sllPopFront( SinglyLinkedList* sll );

/**
 * @brief Removes a node from the tail-end of the list. O(1).
 *
 * @param sll - A pointer to a SLL.
 *
 * @return true if successful, false if not.
 */
bool sllPopBack( SinglyLinkedList* sll );

/**
 * @brief Reverses the order of the list . O(n).
 *
 * @param sll - A pointer to a SLL.
 *
 * @return true if successful, false if not.
 */
bool sllReverse( SinglyLinkedList* sll );

/**
 * @brief Merges two lists together. O(2n).
 *
 * @param lhs - A pointer to the destination list.
 * @param rhs - A pointer to the read-only source list.
 *
 * @return true if successful, false if not.
 */
bool sllMerge( SinglyLinkedList* lhs, const SinglyLinkedList* rhs );

/**
 * @brief Prints the list. O(n)
 *
 * @param sll - A pointer to a read-only SLL.
 *
 * @return true if successful, false if not.
 */
bool sllPrint( const SinglyLinkedList* sll );

#ifdef __cplusplus
    }
#endif

#endif // SINGLY_LINKED_LIST_H
