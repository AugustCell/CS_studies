#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "Nodes.hpp"

using namespace std;

class DoublyLinkedList
{
private:
    DoubleNode* head;
    DoubleNode* tail;
    uint16_t size;

public:
    DoublyLinkedList():
        head(nullptr),
        tail(nullptr),
        size(0)
    {
    }  

    void printHead(void);
    void printTail(void);
    void addToFront(uint32_t value);
    void addToBack(uint32_t value);
    void addAfterNode(uint32_t value, uint16_t idx);
    void addBeforeNode(uint32_t value, uint16_t idx);
    void insert(uint32_t value);
    uint32_t getMiddle(void);
    void reverse(void);
    void deleteNode(uint16_t value);
    void removeFromFront(void);
    void removeFromBack(void);
    void printList(void);
    void destroyList(void);
};