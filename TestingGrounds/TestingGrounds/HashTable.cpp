#include "HashTable.hpp"

template <uint32_t K, uint32_t V>
HashTable<K, V>::HashTable():
    capacity{ 20 },
    size{ 0 },
    table(new HashNode<K, V>*[capacity])
{
    for(int i = 0; i < capacity; i++)
        table[i] = nullptr;
}

template<uint32_t K, uint32_t V>
HashTable<K, V>::~HashTable()
{
    // We may not have reached full capacity by the time we delete
    // the Hash Table
    uint32_t cap = capacity > size? capacity : size;
    for(uint8_t i = 0; i < cap; i++)
    {
        delete table[i];
        table[i] = nullptr;   
    }
    delete table;
}

template<uint32_t K, uint32_t V>
uint32_t HashTable<K, V>::hashFunction( void )
{
    return V % size;
}

// Double hashing is one of the best forms of probing, does not yield
// clusters, and is effective for resolving collisions. We do this 
// 
template<uint32_t K, uint32_t V>
uint32_t HashTable<K, V>::doubleHashFunction( void )
{
    return calcPrime() - hashFunction(V);
}

/*
// This uses Sieve of Eratosthenes to calculate primes quick.
// We begin with an array that begins as false, and will only be 
// true if it is a prime. We then update all multiples of the value 
// in the for loop which are multipples of i, and less than i^2.
//
*/
template<uint32_t K, uint32_t V>
uint32_t HashTable<K, V>::calcPrime( void )
{
    bool prime[size+1] {false};
    uint32_t ret { 0 };
   
    for(int i = 2; i * i <= size; i++)
    {
        if(prime[i] == true)
        {
            for(int j = i * i; j <= size; j++)
                ret = j;
        }
    }
    return ret;
}

template<uint32_t K, uint32_t V>
bool HashTable<K, V>::keyExists( void )
{

}

template<uint32_t K, uint32_t V>
uint32_t HashTable<K, V>::getValue(void)
{

}

template<uint32_t K, uint32_t V>
void HashTable<K, V>::putPair( void )
{

}

template<uint32_t K, uint32_t V>
void HashTable<K, V>::remove( void )
{

}
