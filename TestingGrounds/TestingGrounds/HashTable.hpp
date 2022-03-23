#pragma once
#include <cstdint>
#include <iostream>
#include "Nodes.hpp"

template <uint32_t K, uint32_t V>
class HashTable
{
private:
    HashNode<K, V>** table;
    uint32_t size;
    uint32_t capacity;

public:
    HashTable();
    ~HashTable();
	uint32_t hashFunction( void );
    uint32_t doubleHashFunction( void );
    uint32_t calcPrime( void );
    bool keyExists( void );
    uint32_t getValue( void );
    void putPair( void );
    void remove( void );
};