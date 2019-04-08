#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void addDataToTail(ListNode** pHead, int value)
{
    ListNode* pNewNode = new ListNode();
    pNewNode->m_nValue = value;
    if (*pHead == nullptr)
    {
        *pHead = pNewNode;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != nullptr)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNewNode;
    }
}

void deleteNode(ListNode** pHead, int value)
{
    if (pHead == nullptr || *pHead == nullptr)
        return;
    ListNode* pNodeToDelete = nullptr;
    if ((*pHead)->m_nValue == value)
    {
        pNodeToDelete = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
        {
            pNode = pNode->m_pNext;
        }

        if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pNodeToDelete = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if (pNodeToDelete != nullptr)
    {
        delete pNodeToDelete;
        pNodeToDelete = nullptr;
    }
}

void releaseList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void printList(ListNode* pHead)
{
    cout << endl << "link list in order:" << endl;
    ListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        cout << pNode->m_nValue;
        pNode = pNode->m_pNext;
        if (pNode != nullptr)
        {
            cout << " -> ";
        }
        else
        {
            cout << " -> null" << endl;
        }
    }
}

ListNode* createSingleList(int number[], int length)
{
    ListNode* pNode = nullptr;
    for (int i = 0; i < length; i++)
    {
        addDataToTail(&pNode, number[i]);
    }

    return pNode;
}


int main(int argc, char** argv)
{
    int numbers[] = { 1, 2, 3, 4, 5, 6 };
    int length = sizeof(numbers) / sizeof(int);
    ListNode* pHead = createSingleList(numbers, length);
    cout << "src list data is: ";
    printList(pHead);
    
    deleteNode(&pHead, 4);
    cout << "list data after delete item is: ";
    printList(pHead);
    getchar();
    return 0;
}