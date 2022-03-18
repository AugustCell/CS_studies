#include "DoublyLinkedList.hpp"

void DoublyLinkedList::printHead(void)
{
    cout << "This is head of D_LL: " << head->value << endl;
}

void DoublyLinkedList::printTail(void)
{
    cout << "This is head of D_LL: " << tail->value << endl;
}

// O(1)
void DoublyLinkedList::addToFront(uint32_t value)
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
void DoublyLinkedList::addToBack(uint32_t value)
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
void DoublyLinkedList::addAfterNode(uint32_t value, uint16_t idx)
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
void DoublyLinkedList::addBeforeNode(uint32_t value, uint16_t idx)
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
        for (int i = 0; i < idx; i++) {
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
void DoublyLinkedList::insert(uint32_t value) {
    if (head == nullptr && tail == nullptr) {
        addToFront(value);
    }
    else {
        addToBack(value);
    }
}

// O(n/2)
uint32_t DoublyLinkedList::getMiddle(void)
{
    if (head == nullptr)
        return UINT_MAX;
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
void DoublyLinkedList::reverse(void)
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
void DoublyLinkedList::deleteNode(uint16_t value)
{
    if (value < 0)
        return;
    if (size == 0)
        return;

    DoubleNode* curr = head;
    if (curr->value == value)
    {
        head = head->next;
        curr->value = 0;
        curr->next = nullptr;
        delete curr;
    }
    else
    {
        while (curr != nullptr && curr->value != value)
            curr = curr->next;
    }
    if (curr == nullptr)
        return;

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->value = 0;
    curr->next = nullptr;
    curr->prev = nullptr;
    delete curr;
}

// O(1)
void DoublyLinkedList::removeFromFront(void)
{
    if (size == 0)
        return;
    if (head == tail)
    {
        head->value = 0;
        head->next = nullptr;
        head->prev = nullptr;
        delete head;
        delete tail;
    }
    else {
        DoubleNode* curr = head;

        head = head->next;
        curr->value = 0;
        curr->next = nullptr;
        curr->prev = nullptr;
        delete curr;
    }
    size--;
}

// O(n)
void DoublyLinkedList::removeFromBack(void)
{
    if (size == 0)
        return;
    if (head == tail)
    {
        tail->value = 0;
        tail->next = nullptr;
        delete tail;
        delete head;
    }
    else
    {
        DoubleNode* curr = head;

        while (curr->next->next != nullptr)
            curr = curr->next;

        delete curr->next;
        curr->next->value = 0;
        curr->next = nullptr;
        curr->prev = nullptr;
        tail = curr;
    }
    size--;
}

// O(n)
void DoublyLinkedList::printList(void)
{
    DoubleNode* ptr = head;
    cout << "List of our values in the Double LL" << endl;
    while (ptr != nullptr)
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
void DoublyLinkedList::destroyList(void)
{
    if (size == 0)
        return;

    DoubleNode* ptr = head;
    while (ptr != nullptr)
    {
        DoubleNode* trailing = ptr;
        ptr = ptr->next;

        trailing->value = 0;
        trailing->next = nullptr;
        trailing->prev = nullptr;
        delete trailing;

        size--;
    }
}