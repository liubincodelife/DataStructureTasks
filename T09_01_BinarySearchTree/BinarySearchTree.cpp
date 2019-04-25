#include <iostream>

using namespace std;

struct TreeNode
{
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
    TreeNode(int data) : m_nValue(data), m_pLeft(nullptr), m_pRight(nullptr) {}; //构造函数
};

class BinarySearchTree
{
public:
    BinarySearchTree():pRootNode(nullptr)
    {
        
    }

    ~BinarySearchTree()
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

    TreeNode* findNode(int data)
    {
        TreeNode* pNode = pRootNode;
        while (pNode != nullptr)
        {
            if (pNode->m_nValue > data)
            {
                pNode = pNode->m_pLeft;
            } 
            else if (pNode->m_nValue < data)
            {
                pNode = pNode->m_pRight;
            }
            else
            {
                return pNode;
            }
        }
        return nullptr;
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

    bool deleteNode(int data)
    {
        TreeNode* pNode = pRootNode;
        TreeNode* ppNode = nullptr;
        //查找二叉查找树中是都有这个节点
        while (pNode != nullptr && pNode->m_nValue != data)
        {
            ppNode = pNode;
            if (pNode->m_nValue > data)
            {
                pNode = ppNode->m_pLeft;
            } 
            else
            {
                pNode = pNode->m_pRight;
            }
        }

        if (pNode == nullptr)
            return false;

        //要删除的节点有两个子节点
        if (pNode->m_pLeft != nullptr && pNode->m_pRight != nullptr)
        {
            //查找右子树中最小的节点
            TreeNode* minPNode = pNode->m_pRight;
            TreeNode* minPPNode = pNode;
            while (minPNode->m_pLeft != nullptr)
            {
                minPPNode = minPNode;
                minPNode = minPNode->m_pLeft;
            }
            pNode->m_nValue = minPNode->m_nValue;
            pNode = minPNode;
            ppNode = minPPNode;
        }

        //要删除的节点是叶子节点或者仅有一个子节点
        TreeNode* childNode;
        if (pNode->m_pLeft != nullptr)
        {
            childNode = pNode->m_pLeft;
        }
        else if (pNode->m_pRight != nullptr)
        {
            childNode = pNode->m_pRight;
        }
        else
        {
            childNode = nullptr;
        }

        if (ppNode == nullptr) //要删除的节点是根节点
        {
            pRootNode = childNode;
        } 
        else if(ppNode->m_pLeft == pNode)
        {
            ppNode->m_pLeft = childNode;
        }
        else
        {
            ppNode->m_pRight = childNode;
        }

        return true;
    }
    //查找二叉查找树的最小节点
    TreeNode* getMinNode()
    {
        if (pRootNode == nullptr)
        {
            return nullptr;
        }
        TreeNode* pNode = pRootNode;
        while (pNode->m_pLeft != nullptr)
        {
            pNode = pNode->m_pLeft;
        }
        return pNode;
    }
    //查找二叉查找树的最大节点
    TreeNode* getMaxNode()
    {
        if (pRootNode == nullptr)
        {
            return nullptr;
        }
        TreeNode* pNode = pRootNode;
        while (pNode->m_pRight != nullptr)
        {
            pNode = pNode->m_pRight;
        }
        return pNode;
    }
    //查找某个节点的前驱节点
    TreeNode* getPreNode(int data)
    {
        if (pRootNode == nullptr || pRootNode->m_nValue == data)
        {
            return nullptr;
        }
        TreeNode* pNode = pRootNode;
        TreeNode* ppNode = nullptr;
        while (pNode->m_nValue != data && pNode != nullptr)
        {
            ppNode = pNode;
            if (pNode->m_nValue > data)
            {
                pNode = pNode->m_pLeft;
            }
            else
            {
                pNode = pNode->m_pRight;
            }
        }

        return ((pNode == nullptr) ? nullptr : ppNode);
    }

    //查找某个节点的后继节点
    TreeNode* getPostNode(int data)
    {
        if (pRootNode == nullptr)
        {
            return nullptr;
        }
        TreeNode* pNode = pRootNode;
        while (pNode->m_nValue != data && pNode != nullptr)
        {
            if (pNode->m_nValue > data)
            {
                pNode = pNode->m_pLeft;
            } 
            else
            {
                pNode = pNode->m_pRight;
            }
        }

        if (pNode == nullptr)
        {
            return nullptr;
        } 
        else if (pNode->m_pLeft != nullptr)
        {
            return pNode->m_pLeft;
        }
        else if (pNode->m_pRight != nullptr)
        {
            return pNode->m_pRight;
        }
        else
        {
            return nullptr;
        }
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
    BinarySearchTree binarySearchTree;
    binarySearchTree.createBinarySearchTree(array, length);
    TreeNode* pNode = binarySearchTree.findNode(5);
    pNode = binarySearchTree.getMinNode();
    cout << "the min node is:"<< pNode->m_nValue << endl;
    pNode = binarySearchTree.getMaxNode();
    cout << "the max node is:" << pNode->m_nValue << endl;

    pNode = binarySearchTree.getPreNode(6);
    cout << "the previous node of 6 is:" << pNode->m_nValue << endl;
    pNode = binarySearchTree.getPostNode(6);
    cout << "the post node of 6 is:" << pNode->m_nValue << endl;
    bool state = binarySearchTree.deleteNode(5);
    if (state)
    {
        cout << "delete node success......" << endl;
    }
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}