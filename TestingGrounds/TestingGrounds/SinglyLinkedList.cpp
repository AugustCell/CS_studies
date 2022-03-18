#include "SinglyLikedList.hpp"

void SinglyLinkedList::printHead(void)
{
	cout << "This is head of S_LL: " << head->value << endl;
}

void SinglyLinkedList::printTail(void)
{
	cout << "This is head of S_LL: " << tail->value << endl;
}

// O(1)
void SinglyLinkedList::addToFront(uint32_t value)
{
    if (head == nullptr && tail == nullptr)
    {
        head = tail = new SingleNode(value);
    }
    else if (head == tail)
    {
        SingleNode* newHead = new SingleNode(value);
        newHead->next = head;
        head = newHead;
    }
    else {
        SingleNode* prevHead = head;
        head = new SingleNode(value);
        head->next = prevHead;
    }
    size++;
}

// O(1)
void SinglyLinkedList::addToBack(uint32_t value)
{
    if (head == nullptr && tail == nullptr)
    {
        head = tail = new SingleNode(value);
    }
    else if (head == tail)
    {
        SingleNode* newTail = new SingleNode(value);
        tail->next = newTail;
        tail = newTail;
    }
    else {
        SingleNode* prevTail = tail;
        tail = new SingleNode(value);
        prevTail->next = tail;
    }
    size++;
}

// O(n)
void SinglyLinkedList::addAfterNode(uint32_t value, uint16_t idx)
{
    if (size == 0)
        return;
    else if (idx > size)
        return;
    else if (idx == (size - 1))
    {
        SingleNode* newNode = new SingleNode(value);
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        SingleNode* ptr = head;
        for (int i = 0; i < idx; i++) {
            ptr = ptr->next;
        }
        SingleNode* newNode = new SingleNode(value);

        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    size++;
}

// O(n)
void SinglyLinkedList::addBeforeNode(uint32_t value, uint16_t idx)
{
    if (size == 0)
        return;
    else if (idx < 0)
        return;
    else if (idx == 0)
    {
        SingleNode* newNode = new SingleNode(value);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        SingleNode* ptr = head;
        SingleNode* trailing = head;
        for (int i = 0; i < idx; i++)
        {
            if (i == 1)
                trailing = head;
            ptr = ptr->next;
        }
        SingleNode* newNode = new SingleNode(value);

        newNode->next = ptr;
        trailing->next = newNode;
    }
    size++;
}

// O(n)
void SinglyLinkedList::insert(uint32_t value)
{
    if (head == nullptr && tail == nullptr) {
        addToFront(value);
    }
    else {
        addToBack(value);
    }
}

// O(n/2)
uint32_t SinglyLinkedList::getMiddle(void)
{
    if (head == nullptr)
        return UINT_MAX;
    if (head == tail)
        return head->value;

    SingleNode* slow = head;
    SingleNode* fast = head;

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
void SinglyLinkedList::reverse(void)
{
    if (head == nullptr)
        return;
    if (head == tail)
        return;

    SingleNode* prev = nullptr;
    SingleNode* curr = nullptr;
    SingleNode* ptr = head;

    SingleNode* tempTail = tail;
    tail = head;
    head = tempTail;

    while (ptr != nullptr)
    {
        curr = ptr;
        ptr = ptr->next;

        curr->next = prev;
        prev = curr;
    }
}

// O(n)
void SinglyLinkedList::deleteNode(uint16_t value)
{
    if (value < 0)
        return;
    if (size == 0)
        return;

    SingleNode* curr = head;
    SingleNode* trailing = nullptr;
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
        {
            trailing = curr;
            curr = curr->next;
        }
    }
    if (curr == nullptr)
        return;

    trailing->next = curr->next;

    curr->value = 0;
    curr->next = nullptr;
    delete curr;
}

// O(1) 
void SinglyLinkedList::removeFromFront(void)
{
    if (size == 0)
        return;
    if (head == tail)
    {
        head->value = 0;
        head->next = nullptr;
        delete head;
        delete tail;
    }
    else {
        SingleNode* curr = head;

        head = head->next;
        curr->value = 0;
        curr->next = nullptr;
        delete curr;
    }
    size--;
}

// O(n)
void SinglyLinkedList::removeFromBack(void)
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
        SingleNode* curr = head;

        while (curr->next->next != nullptr)
            curr = curr->next;

        delete curr->next;
        curr->next->value = 0;
        curr->next = nullptr;
        tail = curr;

    }
    size--;
}

// O(n)
void SinglyLinkedList::printList(void)
{
    SingleNode* ptr = head;
    cout << "List of our values in the Single LL" << endl;
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

void SinglyLinkedList::destroyList(void)
{
    if (size == 0)
        return;

    SingleNode* ptr = head;
    while (ptr != nullptr)
    {
        SingleNode* trailing = ptr;
        ptr = ptr->next;

        trailing->value = 0;
        trailing->next = nullptr;
        delete trailing;

        size--;
    }
}