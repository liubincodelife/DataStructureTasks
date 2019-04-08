#pragma once

template <typename T> class ListStack
{
public:
    ListStack();
    ~ListStack();
    T top();
    void pop();
    void push(T item);
    bool isEmpty(void);
    size_t getSize(void);
private:
    struct ListNode
    {
        T value;
        ListNode* pNext;
    };
    ListNode* head;
    size_t size;
};

template <typename T>
ListStack<T>::ListStack():head(nullptr), size(0)
{

}

template <typename T>
ListStack<T>::~ListStack()
{
    ListNode *node = head;
    while (node != nullptr)
    {
        ListNode *nextNode = node->pNext;
        delete node;
        node = nextNode;
    }
    head = nullptr;
}

template <typename T>
T ListStack<T>::top()
{
    if (!isEmpty())
    {
        T item = head->value;
        return item;
    }
    else
    {
        cout << "stack is empty!!!" << endl;
        return NULL;
    }
}

template <typename T>
void ListStack<T>::pop()
{
    if (!isEmpty())
    {
        ListNode *node = head;
        head = head->pNext;
        delete node;
        size--;
    }
}

template <typename T>
void ListStack<T>::push(T item)
{
    ListNode *node = new ListNode();
    node->value = item;
    if (head == nullptr)
    {
        node->pNext = nullptr;
    }
    else
    {
        node->pNext = head;
    }

    head = node;
    size++;
}

template <typename T>
bool ListStack<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
size_t ListStack<T>::getSize()
{
    return size;
}
