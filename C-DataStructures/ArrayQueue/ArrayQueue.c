#include "ArrayQueue.h"

/* See header for documentation. */
bool arrayQueueInit(ArrayQueue** aq)
{
    bool status = false;

    if (*aq != NULL)
    {
        fprintf(stderr, "Already initialized!\n\r");
    }
    else if ((*aq = (ArrayQueue*)malloc(sizeof(ArrayQueue) * C_MAX_QUEUE_SIZE)) == NULL)
    {
        fprintf(stderr, "Failed to malloc memory!");
    }
    else if (arrayQueueInitArray(*aq) == false)
    {
        fprintf(stderr, "Failed to malloc array!\n\r");
    }
    else
    {
        (*aq)->m_frontIndex = 0;
        (*aq)->m_backIndex = 0;
        (*aq)->m_size = 0;

        status = true;
    }

    return status;
}

/* See header for documentation. */
bool arrayQueueInitArray(ArrayQueue* aq)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is null!\n\r");
    }
    else if ((aq->m_array = (int32_t**)malloc(sizeof(int32_t*) * C_MAX_QUEUE_SIZE)) == NULL)
    {
        fprintf(stderr, "Failed to malloc space for the array!\n\r");
    }
    else
    {
        for (uint32_t i = 0; i < C_MAX_QUEUE_SIZE; i++)
        {
            aq->m_array[i] = (int32_t*)malloc(sizeof(int32_t));

            if (aq->m_array[i] == NULL)
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
bool arrayQueuePush(ArrayQueue* aq, const int32_t value)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is not initialized!\n\r");
    }
    else if (aq->m_size + 2 > C_MAX_QUEUE_SIZE)
    {
        fprintf(stderr, "ArrayQueue size exceeded!\n\r");
    }
    else if (aq->m_array[aq->m_size] == NULL)
    {
        fprintf(stderr, "Array at %d is null!\n\r", aq->m_size);
    }
    else
    {
        aq->m_backIndex = (aq->m_backIndex + 1) % C_MAX_QUEUE_SIZE; // Update back index
        *aq->m_array[aq->m_backIndex] = value;                      // Add to the end of the array
        aq->m_size++;

        status = true;
    }

    return status;
}


/* See header for the documentation. */
bool arrayQueuePop(ArrayQueue* aq)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is null!\n\r");
    }
    else if (aq->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else if (arrayQueueIsEmpty(aq) == true)
    {
        fprintf(stderr, "The stack is empty!\n\r");
    }
    else
    {
        // Remove the oldest value from the queue
        free(aq->m_array[aq->m_frontIndex]);
        aq->m_array[aq->m_frontIndex] = NULL;
        aq->m_frontIndex = (aq->m_frontIndex + 1) % C_MAX_QUEUE_SIZE; // Update the front index
        aq->m_size--;

        status = true;
    }

    return status;
}

/* See header for the documentation. */
bool arrayQueueFront(const ArrayQueue* aq, int32_t* value)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is null!\n\r");
    }
    else if (aq->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else if (arrayQueueIsEmpty(aq) == true)
    {
        fprintf(stderr, "The queue is empty!\n\r");
    }
    else if (value == NULL)
    {
        fprintf(stderr, "Null value passed in!\n\r");
    }
    else
    {
        *value = *aq->m_array[aq->m_frontIndex];

        status = true;
    }

    return status;
}

bool arrayQueueBack(const ArrayQueue* aq, int32_t* value)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is null!\n\r");
    }
    else if (aq->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else if (arrayQueueIsEmpty(aq) == true)
    {
        fprintf(stderr, "The queue is empty!\n\r");
    }
    else if (value == NULL)
    {
        fprintf(stderr, "Null value passed in!\n\r");
    }
    else
    {
        *value = *aq->m_array[aq->m_backIndex];

        status = true;
    }

    return status;
}

/* See header for the documentation. */
bool arrayQueueIsEmpty(const ArrayQueue* aq)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is null!\n\r");
    }
    else if (aq->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else
    {
        status = aq->m_size == 0;
    }

    return status;
}

/* See header for the documentation. */
bool arrayQueueSize(const ArrayQueue* aq, uint32_t* size)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is null!\n\r");
    }
    else if (aq->m_array == NULL)
    {
        fprintf(stderr, "Array is null!\n\r");
    }
    else if (size == NULL)
    {
        fprintf(stderr, "Null size passed in!\n\r");
    }
    else
    {
        *size = aq->m_size;

        status = true;
    }

    return status;
}

/* See header for the documentation. */
bool arrayQueueFree(ArrayQueue* aq)
{
    bool status = false;

    if (aq == NULL)
    {
        fprintf(stderr, "ArrayQueue is null!\n\r");
    }
    else if (aq->m_array == NULL)
    {
        fprintf(stderr, "ArrayQueue->Array is null!\n\r");
    }
    else
    {
        for (uint32_t i = 0; i < C_MAX_QUEUE_SIZE; i++)
        {
            if (aq->m_array[i] != NULL)
            {
                free(aq->m_array[i]);
                aq->m_array[i] = NULL;
            }
        }
        aq->m_size = 0;
        aq->m_backIndex = 0;
        aq->m_frontIndex = 0;

        free(aq->m_array);
        aq->m_array = NULL;

        free(aq);
        aq = NULL;

        status = true;
    }

    return status;
}
