#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
    TreeNode(int data = 0) : m_nValue(data), m_pLeft(nullptr), m_pRight(nullptr) {}; //构造函数
};

class BinaryTree
{
public:
    BinaryTree():pRootNode(nullptr)
    {

    }
    ~BinaryTree()
    {

    }

    void createBinarySearchTree(int array[], int length)
    {
        int count = 0;
        while (count < length)
        {
            insertNode(array[count++]);
        }
    }

    bool insertNode(int data)
    {
        if (pRootNode == nullptr)
        {
            pRootNode = new TreeNode(data);
            return true;
        }

        TreeNode* pNode = pRootNode;
        while (pNode != nullptr)
        {
            if (pNode->m_nValue > data)
            {
                if (pNode->m_pLeft == nullptr)
                {
                    TreeNode* tmpNode = new TreeNode(data);
                    pNode->m_pLeft = tmpNode;
                    return true;
                }
                pNode = pNode->m_pLeft;
            }
            else
            {
                if (pNode->m_pRight == nullptr)
                {
                    TreeNode* tmpNode = new TreeNode(data);
                    pNode->m_pRight = tmpNode;
                    return true;
                }
                pNode = pNode->m_pRight;
            }
        }

        return true;
    }
    //前序遍历
    void preOrder(TreeNode* pNode)
    {
        if (pNode == nullptr)
        {
            return;
        }
        cout << pNode->m_nValue << "->";
        preOrder(pNode->m_pLeft);
        preOrder(pNode->m_pRight);
    }
    //中序遍历
    void inOrder(TreeNode* pNode)
    {
        if (pNode == nullptr)
        {
            return;
        }
        inOrder(pNode->m_pLeft);
        cout << pNode->m_nValue << "->";
        inOrder(pNode->m_pRight);
    }
    //后序遍历
    void postOrder(TreeNode* pNode)
    {
        if (pNode == nullptr)
        {
            return;
        }

        postOrder(pNode->m_pLeft);
        postOrder(pNode->m_pRight);
        cout << pNode->m_nValue << "->";
    }
    //按层遍历
    void levelOrder(TreeNode* pNode)
    {
        if (pNode == nullptr)
        {
            return;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(pNode);
        while (!nodeQueue.empty())
        {
            TreeNode* pTmpNode = nodeQueue.front();
            nodeQueue.pop();
            cout << pTmpNode->m_nValue << "->";
            if (pTmpNode->m_pLeft != nullptr)
            {
                nodeQueue.push(pTmpNode->m_pLeft);
            } 

            if(pTmpNode->m_pRight != nullptr)
            {
                nodeQueue.push(pTmpNode->m_pRight);
            }
        }
    }

    TreeNode* getRootNode()
    {
        return pRootNode;
    }
protected:
private:
    TreeNode* pRootNode;
};

//        3
//       / \
//      2   5
//     /   / \
//    1   4   6
//             \
//              9
//             / 
//            7
//             \
//              8
void test()
{
    int array[] = { 3, 2, 5, 1, 4, 6, 9, 7, 8 };
    int length = sizeof(array) / sizeof(int);
    BinaryTree binaryTree;
    binaryTree.createBinarySearchTree(array, length);
    TreeNode* root = binaryTree.getRootNode();
    cout << endl << "preOrder is:" << endl;
    binaryTree.preOrder(root);
    cout << endl << "inOrder is:" << endl;
    binaryTree.inOrder(root);
    cout << endl << "postOrder is:" << endl;
    binaryTree.postOrder(root);
    cout << endl << "levelOrder is:" << endl;
    binaryTree.levelOrder(root);
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}