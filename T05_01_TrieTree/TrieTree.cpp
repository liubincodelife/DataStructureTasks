#include <iostream>

using namespace std;

#define MAX_SIZE    26
struct TrieNode
{
    TrieNode* pNext[MAX_SIZE];
    int num;
};

TrieNode* createNode()
{
    TrieNode* pNode = new TrieNode();
    for (int i = 0; i < MAX_SIZE; i++)
    {
        pNode->pNext[i] = nullptr;
    }
    pNode->num = 0;

    return pNode;
}

void insert(TrieNode* head, string str)
{
    TrieNode* pNode = head;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if (pNode->pNext[index] == nullptr)
        {
            pNode->pNext[index] = createNode();
            pNode->num++;
        }
        pNode = pNode->pNext[index];
    }
}

int search(TrieNode* head, string str)
{
    TrieNode* pNode = head;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if (pNode->pNext[index] == nullptr)
        {
            count = 0;
            cout << "can not find this string" << endl;

            return -1;
        }
        else
        {
            pNode = pNode->pNext[index];
            count = pNode->num;
        }
    }

    return count;
}

void test()
{
    string str = "abcdefghijklmnopqrstuvwxyz";
    TrieNode* head = createNode();
    insert(head, str);
    int count = search(head, "abcdef");
    cout << "cont = "<< count << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}