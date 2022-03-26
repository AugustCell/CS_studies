/**
 * @file ArrayStack.c
 *
 * @brief Implements the functions of the ArrayStack Structure.
 *
 * @ingroup C-DataStructure
 *
 * @author Edward Lon
 * Contact: edwardlon@outlook.com
 *
 */

#include "ArrayStack.h"

/* See header for documentation. */
bool arrayStackInit( ArrayStack** as )
{
    bool status = false;

    if (*as != NULL)
    {
        fprintf(stderr, "Already initialized!\n\r");
    }
    else if ((*as = (ArrayStack*)malloc(sizeof(ArrayStack) * C_MAX_STACK_SIZE)) == NULL)
    {
        fprintf(stderr, "Failed to malloc memory!");
    }
    else if (arrayStackInitArray(*as) == false)
    {
        fprintf(stderr, "Failed to malloc array!\n\r");
    }
    else
    {
        (*as)->m_size = 0;

        status = true;
    }

    return status;
}

/* See header for documentation. */
bool arrayStackInitArray( ArrayStack* as )
{
    bool status = false;

    if (as == NULL)
    {
        fprintf(stderr, "ArrayStack is null!\n\r");
    }
    else if ((as->m_array = (int32_t**)malloc(sizeof(int32_t*) * C_MAX_STACK_SIZE)) == NULL)
    {
        fprintf(stderr, "Failed to malloc space for the array!\n\r");
    }
    else
    {
        for (uint32_t i = 0; i < C_MAX_STACK_SIZE; i++)
        {
            as->m_array[i] = (int32_t*)malloc(sizeof(int32_t));

            if (as->m_array[i] == NULL)
            {
                fprintf(stderr, "Out of memory!\n\r");
                status = false;
                break;
            }
        }
        status = true;
    }

    return status;
}

/* See header for documentation. */
bool arrayStackPush( ArrayStack* as, const int32_t value )
{
    bool status = false;

    if (as == NULL)
    {
        fprintf(stderr, "ArrayStack is not initialized!\n\r");
    }
    else if (as->m_size + 2 > C_MAX_STACK_SIZE)
    {
        fprintf(stderr, "ArrayStack stack size exceeded!\n\r");
    }
    else if (as->m_array[as->m_size] == NULL)
    {
        fprintf(stderr, "Array at %d is null!\n\r", as->m_size);
    }
    else
    {
        *as->m_array[++as->m_size] = value;

        status = true;
    }

    return status;
}


/* See header for the documentation. */
bool arrayStackPop( ArrayStack* as )
{
    bool status = false;

    if (as == NULL)
    {
        fprintf(stderr, "ArrayStack is null!\n\r");
    }
    else if (as->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else if (arrayStackIsEmpty(as) == true)
    {
        fprintf(stderr, "The stack is empty!\n\r");
    }
    else
    {
        free(as->m_array[as->m_size]);
        as->m_array[as->m_size--] = NULL;

        status = true;
    }

    return status;
}

/* See header for the documentation. */
bool arrayStackTop( const ArrayStack* as, int32_t* value )
{
    bool status = false;

    if (as == NULL)
    {
        fprintf(stderr, "ArrayStack is null!\n\r");
    }
    else if (as->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else if (arrayStackIsEmpty(as) == true)
    {
        fprintf(stderr, "The stack is empty!\n\r");
    }
    else if (value == NULL)
    {
        fprintf(stderr, "Null value passed in!\n\r");
    }
    else
    {
        *value = *as->m_array[as->m_size];

        status = true;
    }

    return status;
}

/* See header for the documentation. */
bool arrayStackIsEmpty( const ArrayStack* as )
{
    bool status = false;

    if (as == NULL)
    {
        fprintf(stderr, "ArrayStack is null!\n\r");
    }
    else if (as->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else
    {
        status = as->m_size == 0;
    }

    return status;
}

/* See header for the documentation. */
bool arrayStackSize( const ArrayStack* as, uint32_t* size )
{
    bool status = false;

    if (as == NULL)
    {
        fprintf(stderr, "ArrayStack is null!\n\r");
    }
    else if (as->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else if (size == NULL)
    {
        fprintf(stderr, "Null size passed in!\n\r");
    }
    else
    {
        *size = as->m_size;

        status = true;
    }

    return status;
}

/* See header for the documentation. */
bool arrayStackFree( ArrayStack* as )
{
    bool status = false;

    if (as == NULL)
    {
        fprintf(stderr, "ArrayStack is null!\n\r");
    }
    else if (as->m_array == NULL)
    {
        fprintf(stderr, "ArrayStack->Array is null!\n\r");
    }
    else
    {
        for (uint32_t i = 0; i < C_MAX_STACK_SIZE; i++)
        {
            if (as->m_array[i] != NULL)
            {
                free(as->m_array[i]);
                as->m_array[i] = NULL;
            }
        }

        as->m_size = 0;

        free(as->m_array);
        as->m_array = NULL;

        free(as);
        as = NULL;

        status = true;
    }

    return status;
}