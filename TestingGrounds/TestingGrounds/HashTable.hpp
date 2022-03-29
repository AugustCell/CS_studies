#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "Nodes.hpp"

class HashTable
{
private:
    HashNode** table;
    uint32_t size;
    static constexpr uint32_t capacity = 10000;

public:
    HashTable();
    ~HashTable();
	uint32_t hashFunction( uint32_t key );
    uint32_t doubleHashFunction( uint32_t key );
    uint32_t calcPrime( uint32_t key );
    bool keyExists( uint32_t key );
    uint32_t getValue( uint32_t key );
    void put( uint32_t key, uint32_t value );
    void remove( uint32_t key );
    void printTable( void );
};