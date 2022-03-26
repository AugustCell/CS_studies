/**
 * @file ArrayStack.h
 *
 * @brief Defines the ArrayStack Structure.
 *
 * @ingroup C-DataStructure
 *
 * @author Edward Lon
 * Contact: edwardlon@outlook.com
 *
 */

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static const uint32_t C_MAX_STACK_SIZE = UINT16_MAX;

#pragma pack ( push, 4 )
typedef struct ArrayStack
{
    int32_t** m_array;
    uint32_t m_size;
} ArrayStack;
#pragma pack ( pop )

/**
* @brief Initializes the members of the ArrayStack structure.
* @param as - A pointer with a level of indirection to an ArrayStack variable.
* @return true if successful, false if not.
*/
bool arrayStackInit( ArrayStack** as );

/**
* @brief Initializes the array within an ArrayStack structure. O(n)
* @param as - Pointer to an ArrayStack variable.
* @return true if successful, false if not.
*/
bool arrayStackInitArray( ArrayStack* as );

/**
* @brief Adds to the top of the stack. O(1)
* @param as - Pointer to an ArrayStack variable.
* @param value - Read-only value containing the number to be added.
* @return true if successful, false if not.
*/
bool arrayStackPush( ArrayStack* as, const int32_t value );

/**
* @brief Pops the top of the stack. O(1)
* @param as - A pointer to an ArrayStackVariable.
* @return true if successful, false if not.
*/
bool arrayStackPop( ArrayStack* as );

/**
 * @brief Returns the number on top of the stack via indirection. O(1)
 * @param as - A pointer to the read-only data of an ArrayStack variable.
 * @param value - A pointer to the variable that will hold the value at the top of the stack.
 * @return true if successful, false if not.
 */
bool arrayStackTop( const ArrayStack* as, int32_t* value );

/**
* @brief Checks if the stack is empty. O(1)
* @param as - A pointer to the read-only data of an ArrayStack variable.
* @return true if the size is 0.
*/
bool arrayStackIsEmpty( const ArrayStack* as );

/**
 * @brief Retrieves the size of the stack via indirection. O(1)
 * @param as - The pointer to the read-only data of an ArrayStack variable.
 * @param size - The pointer to the unsigned size of the stack.
 * @return true if successful, false if not.
 */
bool arrayStackSize( const ArrayStack* as, uint32_t* size );

/**
* @brief Frees the entire stack array. O(n)
* @param as - The pointer to an ArrayStack variable.
* @return true if not null, false otherwise.
*/
bool arrayStackFree( ArrayStack* as );

#ifdef __cplusplus
}
#endif

#endif // ARRAY_STACK_H
