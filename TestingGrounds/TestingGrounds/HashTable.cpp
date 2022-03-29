#include "HashTable.hpp"

using namespace std;

HashTable::HashTable():
    size{ 0 },
    table(new HashNode*[capacity])
{
    for(uint32_t i = 0; i < capacity; i++)
        table[i] = nullptr;
}

HashTable::~HashTable()
{
    for(uint32_t i = 0; i < capacity; i++)
    {
        if(table[i] != nullptr)
        {
            delete[] table[i];
            table[i] = nullptr;
        }
    }
    delete[] table;
    size = 0;
}

uint32_t HashTable::hashFunction( uint32_t key )
{
    return key % capacity;
}

// Double hashing is one of the best forms of probing, does not yield
// clusters, and is effective for resolving collisions. We do this 
// 
uint32_t HashTable::doubleHashFunction( uint32_t key )
{
    return calcPrime(key) - hashFunction(key);
}

/*
// This uses Sieve of Eratosthenes to calculate primes quick.
// We begin with an array that begins as false, and will only be 
// true if it is a prime. We then update all multiples of the value 
// in the for loop which are multipples of i, and less than i^2.
//
*/
uint32_t HashTable::calcPrime( uint32_t key )
{
    vector<bool> prime(key+1, true);
    uint32_t ret { 0 };
   
    for(uint32_t i = 2; i * i <= key; i++)
    {
        if(prime[i] == true)
        {
            for(uint32_t j = i * i; j <= key; j++)
            {
                ret = j;
                prime[j] = false;
            }
        }
    }
    return ret;
}

bool HashTable::keyExists( uint32_t key )
{
    if(size == 0)
        return false;

    for(uint32_t i = 0; i < size; i++)
    {
        if(table[i]->getValue() == key)
            return true;
    }
}

uint32_t HashTable::getValue( uint32_t key )
{
    uint32_t hash1 = hashFunction(key);
    uint32_t hash2 = doubleHashFunction(key);

    HashNode *entry = table[hash1];

    if(entry->getKey() == key)
        return entry->getValue();
    else
    {
        HashNode* offsetEntry = table[hash2];
        return offsetEntry->getValue();
    }

    return UINT32_MAX;
}

void HashTable::put( uint32_t key, uint32_t value )
{
    HashNode* newNode = new HashNode(key, value);

    uint32_t hash1 = hashFunction(key);
    uint32_t hash2 = doubleHashFunction(key);

    if(table[hash1] == nullptr)
        table[hash1] = newNode;
    else if(table[hash2] == nullptr)
        table[hash2] = nullptr;
    else
        return;
    size++;
}

void HashTable::remove( uint32_t key )
{
    uint32_t hash1 = hashFunction(key);
    uint32_t hash2 = doubleHashFunction(key);

    HashNode* temp = table[hash1];
    HashNode* doubleTemp = table[hash2];

    if(temp->getKey() == key)
    {
        delete temp;
        table[hash1] = nullptr;
    }
    else if(doubleTemp->getKey() == key)
    {
        delete doubleTemp;
        table[hash2] = nullptr;
    }
    else
        return;
    size--;
}

void HashTable::printTable( void )
{
    for(uint32_t i = 0; i < capacity; i++)
    {
        if(table[i] != nullptr)
            cout << "Key: " << table[i]->getKey() << " Value: " << table[i]->getValue() << endl;
    }    
}
