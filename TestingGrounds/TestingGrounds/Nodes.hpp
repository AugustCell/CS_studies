#pragma once
#include <iostream>
#include <cstring>

struct DoubleNode
{
    // We set intiializer list for our values
    // More information in notes.txt
    DoubleNode(uint32_t value) :
        value(value),
        next(nullptr),
        prev(nullptr)
    {
    }
    uint32_t value;
    DoubleNode* next;
    DoubleNode* prev;
};

struct SingleNode
{
    // We set intiializer list for our values
    // More information in notes.txt
    SingleNode(uint32_t value) :
        value(value),
        next(nullptr)
    {
    }
    uint32_t value;
    SingleNode* next;
};