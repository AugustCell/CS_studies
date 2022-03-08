#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdint>

using namespace std;

struct Node
{
    Node(uint32_t value) :
        value(value),
        next(nullptr),
        prev(nullptr)
    {
    }
    uint32_t value;
    Node* next;
    Node* prev;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    uint16_t size;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }  

    void addToFront(uint32_t value)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = tail = new Node(value);
        }
        else if (head == tail)
        {
            Node* newHead = new Node(value);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        else {
            Node* prevHead = head;
            head = new Node(value);
            head->next = prevHead;
            prevHead->prev = head;
        }
        size++;
    }

    void addToBack(uint32_t value)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = tail = new Node(value);
        }
        else if (head == tail)
        {
            Node* newTail = new Node(value);
            newTail->prev = tail;
            tail->next = newTail;
            tail = newTail;
        }
        else {
            Node* prevTail = tail;
            tail = new Node(value);
            tail->prev = prevTail;
            prevTail->next = tail;
        }
        size++;
    }

    void addAfterNode(uint32_t value, uint16_t idx)
    {
        if (size == 0)
            return;
        else if (idx > size)
            return;
        else if (idx == size)
        {
            Node* newNode = new Node(value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            Node* ptr = head;
            while (idx > 0) {
                ptr = ptr->next;
            }
            Node* newNode = new Node(value);

            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next->prev = newNode;
            ptr->next = newNode;
            
        }
    }

    void addBeforeNode(uint32_t value, uint16_t idx)
    {
        if (size == 0)
            return;
        else if (idx < 0)
            return;
        else if (idx == 0)
        {
            Node* newNode = new Node(value);
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* ptr = head;
            while (idx > 0) {
                ptr = ptr->next;
            }
            Node* newNode = new Node(value);

            newNode->next = ptr;
            newNode->prev = ptr->prev;
            ptr->prev->next = newNode;
            ptr->prev = newNode;

        }
    }

    void insert(uint32_t value) {
        if (head == nullptr && tail == nullptr) {
            addToFront(value);
        }
        else {
            addToBack(value);
        }
    }

    Node* getMiddle(void)
    {
        Node* slow = head;
        Node* fast = head;

        if (head) {
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return slow;
    }

    void reverse(void)
    {
        Node* temp = nullptr;
        Node* curr = head;

        if (head == nullptr)
            return;
        if (head == tail)
            return;

        Node* tempTail = tail;
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

    void printList(void)
    {
        Node* ptr = head;
        cout << "List of our values in the LL" << endl;
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
};