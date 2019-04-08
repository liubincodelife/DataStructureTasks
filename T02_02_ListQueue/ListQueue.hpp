#pragma once

template<typename T> class ListQueue
{
public:
    ListQueue();
    ~ListQueue();
    T front();
    void pop();
    void push(T item);
    bool isEmpty();
    int getSize();
private:
    struct ListNode
    {
        T value;
        ListNode* pNext;
    };
    ListNode* pHead;
    ListNode* pTail;
    int size;
};

template<typename T>
ListQueue<T>::ListQueue():size(0)
{
    pHead = nullptr;
    pTail = nullptr;
}

template<typename T>
ListQueue<T>::~ListQueue()
{

}

template<typename T>
T ListQueue<T>::front()
{
    if (isEmpty())
        return NULL;
    T item = pHead->value;
    return item;
}

template<typename T>
void ListQueue<T>::pop()
{
    pHead = pHead->pNext;
    size--;
}

template<typename T>
void ListQueue<T>::push(T item)
{
    ListNode* pNode = new ListNode();
    pNode->value = item;

    if (pHead == nullptr && pTail == nullptr)
    {
        pHead = pNode;
        pTail = pNode;
    }
    else
    {
        pTail->pNext = pNode;
        pTail = pTail->pNext;
    }
    size++;
}

template<typename T>
bool ListQueue<T>::isEmpty()
{
    return (pHead == nullptr);
}

template<typename T>
int ListQueue<T>::getSize()
{
    return size;
}
