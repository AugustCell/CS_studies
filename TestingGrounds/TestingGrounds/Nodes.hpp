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

template <uint32_t K, uint32_t V>
struct HashNode
{
    HashNode(const uint32_t &key, const uint32_t &value):
        key(K),
        value(V)
    {}
    ~HashNode()
    {
        key = NULL;
        value = NULL;
    }
    uint32_t key;
    uint32_t value;

    uint32_t getKey( void )
    {
        return key;
    }
    uint32_t getValue( void )
    {
        return value;
    }
    void setKey( uint32_t key )
    {
        this->key = key;
    }
    void setValue( uint32_t value )
    {   
        this->value = value;
    }
};