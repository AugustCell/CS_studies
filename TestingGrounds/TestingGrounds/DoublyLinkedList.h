#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "Node.hpp"

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

    // O(1)
    void addToFront(uint32_t value)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = tail = new DoubleNode(value);
        }
        else if (head == tail)
        {
            DoubleNode* newHead = new DoubleNode(value);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        else {
            DoubleNode* prevHead = head;
            head = new DoubleNode(value);
            head->next = prevHead;
            prevHead->prev = head;
        }
        size++;
    }

    // O(1)
    void addToBack(uint32_t value)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = tail = new DoubleNode(value);
        }
        else if (head == tail)
        {
            DoubleNode* newTail = new DoubleNode(value);
            newTail->prev = tail;
            tail->next = newTail;
            tail = newTail;
        }
        else {
            DoubleNode* prevTail = tail;
            tail = new DoubleNode(value);
            tail->prev = prevTail;
            prevTail->next = tail;
        }
        size++;
    }

    // O(n)
    void addAfterNode(uint32_t value, uint16_t idx)
    {
        if (size == 0)
            return;
        else if (idx > size)
            return;
        else if (idx == (size - 1))
        {
            DoubleNode* newNode = new DoubleNode(value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            DoubleNode* ptr = head;
            for (uint8_t i = 0; i < idx; i++)
            {
                ptr = ptr->next;
            }
            DoubleNode* newNode = new DoubleNode(value);

            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next->prev = newNode;
            ptr->next = newNode; 
        }
        size++;
    }

    // O(n)
    void addBeforeNode(uint32_t value, uint16_t idx)
    {
        if (size == 0)
            return;
        else if (idx < 0)
            return;
        else if (idx == 0)
        {
            DoubleNode* newNode = new DoubleNode(value);
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else
        {
            DoubleNode* ptr = head;
            for(int i = 0; i < idx; i++) {
                ptr = ptr->next;
            }
            DoubleNode* newNode = new DoubleNode(value);

            newNode->next = ptr;
            newNode->prev = ptr->prev;
            ptr->prev->next = newNode;
            ptr->prev = newNode;
        }
        size++;
    }

    // O(n)
    void insert(uint32_t value) {
        if (head == nullptr && tail == nullptr) {
            addToFront(value);
        }
        else {
            addToBack(value);
        }
    }

    // O(n/2)
    uint32_t getMiddle(void)
    {
        if (head == nullptr)
            return 0;
        if (head == tail)
            return head->value;

        DoubleNode* slow = head;
        DoubleNode* fast = head;

        if (head) {
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return slow->value;
    }

    // O(n)
    void reverse(void)
    {
        if (head == nullptr)
            return;
        if (head == tail)
            return;

        DoubleNode* temp = nullptr;
        DoubleNode* curr = head;

        DoubleNode* tempTail = tail;
        tail = head;
        head = tempTail;
       
        while (curr != nullptr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
    }

    // O(n)
    void printList(void)
    {
        DoubleNode* ptr = head;
        cout << "List of our values in the Double LL" << endl;
        while(ptr != nullptr)
        {
            cout << ptr->value;
            if (ptr != tail)
            {
                cout << "->";
            }
            ptr = ptr->next;
        }
        cout << endl;
    }

    // O(n)
    void destroyList(void)
    {
        if(size == 0)
            return;

        DoubleNode* ptr = head;
        while(ptr != nullptr)
        {
            DoubleNode* trailing = ptr;
            ptr = ptr->next;
            
            trailing->value = 0;
            trailing->next = nullptr;
            trailing->prev = nullptr;
            free(trailing);

            size--;

            cout << "This is size now: " << size << endl;
        }
    }
};