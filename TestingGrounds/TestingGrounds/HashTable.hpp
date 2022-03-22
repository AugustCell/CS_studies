#pragma once
#include <cstdint>
#include <iostream>
#include "Nodes.hpp"

template <typename K, typename V>
class HashTable
{
private:
    HashNode<K, V>** table;
    uint32_t size;
    uint32_t capacity;

public:
    HashTable();
    ~HashTable();
	uint32_t hashFunction( V value );
    uint32_t doubleHashFunction( V value );
    uint32_t calcPrime( void );
    bool keyExists( K key );
    V getValue( K key );
    void putPair( K key, V value );
    void remove( K key );
};