#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void ReverseList(ListNode* pHead)
{
    stack<ListNode*> nodeStack;
    ListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        nodeStack.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodeStack.empty())
    {
        pNode = nodeStack.top();
        cout << pNode->m_nValue;
        cout << " -> ";
        nodeStack.pop();
    }
    cout << endl;
}

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

void printList(ListNode* pHead)
{
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

    ReverseList(pHead);

    getchar();
    return 0;
}