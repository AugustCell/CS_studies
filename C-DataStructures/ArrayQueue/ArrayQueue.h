/**
 * @file ArrayQueue.h
 *
 * @brief Defines the ArrayQueue Structure.
 *
 * @ingroup C-DataStructure
 *
 * @author Edward Lon
 * Contact: edwardlon@outlook.com
 *
 */

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

static const uint32_t C_MAX_QUEUE_SIZE = UINT16_MAX;

#pragma pack ( push, 4 )
typedef struct ArrayQueue
{
    int32_t** m_array;
    uint32_t m_frontIndex;
    uint32_t m_backIndex;
    uint32_t m_size;
} ArrayQueue;
#pragma pack ( pop )

/**
* @brief Initializes the members of the ArrayStack structure.
* @param aq - A pointer with a level of indirection to an ArrayStack variable.
* @return true if successful, false if not.
*/
bool arrayQueueInit(ArrayQueue** aq);

/**
* @brief Initializes the array within an ArrayStack structure. O(n)
* @param aq - Pointer to an ArrayStack variable.
* @return true if successful, false if not.
*/
bool arrayQueueInitArray(ArrayQueue* aq);

/**
* @brief Adds to the top of the stack. O(1)
* @param aq - Pointer to an ArrayStack variable.
* @param value - Read-only value containing the number to be added.
* @return true if successful, false if not.
*/
bool arrayQueuePush(ArrayQueue* aq, const int32_t value);

/**
* @brief Pops the top of the stack. O(1)
* @param aq - A pointer to an ArrayStackVariable.
* @return true if successful, false if not.
*/
bool arrayQueuePop(ArrayQueue* aq);

/**
 * @brief Returns the number on top of the stack via indirection. O(1)
 * @param aq - A pointer to the read-only data of an ArrayStack variable.
 * @param value - A pointer to the variable that will hold the value at the top of the stack.
 * @return true if successful, false if not.
 */
bool arrayQueueFront(const ArrayQueue* aq, int32_t* value);

/**
 * @brief Something
 * @param aq Something
 * @param value Something
 * @return Something
 */
bool arrayQueueBack(const ArrayQueue* aq, int32_t* value);

/**
* @brief Checks if the stack is empty. O(1)
* @param aq - A pointer to the read-only data of an ArrayStack variable.
* @return true if the size is 0.
*/
bool arrayQueueIsEmpty(const ArrayQueue* aq);

/**
 * @brief Retrieves the size of the stack via indirection. O(1)
 * @param aq - The pointer to the read-only data of an ArrayStack variable.
 * @param size - The pointer to the unsigned size of the stack.
 * @return true if successful, false if not.
 */
bool arrayQueueSize(const ArrayQueue* aq, uint32_t* size);

/**
* @brief Frees the entire stack array. O(n)
* @param aq - The pointer to an ArrayStack variable.
* @return true if not null, false otherwise.
*/
bool arrayQueueFree(ArrayQueue* aq);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_QUEUE_H
