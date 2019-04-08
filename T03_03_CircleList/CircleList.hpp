#pragma once

using namespace std;

//结点类
class Node {
public:
    int data;
    Node *pNext;
};
//单向循环链表类
class CircleList {
public:
    CircleList() {
        head = new Node;
        head->data = 0;
        head->pNext = head;
    }
    ~CircleList() { delete head; }
    void CreateLinkList(int n);				//创建单向循环链表
    void InsertNode(int position, int d);	//在指定位置插入结点
    void TraverseLinkList();				//遍历链表
    bool IsEmpty();							//判断链表是否为空
    int GetLength();						//得到链表的长度
    void DeleteNode(int position);			//删除指定位置结点
    void DeleteLinkList();					//删除链表
private:
    Node *head;
};

void CircleList::CreateLinkList(int n) {
    if (n < 0) {
        cout << "输入结点个数错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        Node *pnew, *ptemp = head;
        int i = n;
        while (n-- > 0) {
            cout << "输入第" << i - n << "个结点值：";
            pnew = new Node;
            cin >> pnew->data;
            pnew->pNext = head;
            ptemp->pNext = pnew;
            ptemp = pnew;
        }
    }
}

void CircleList::InsertNode(int position, int d) {
    if (position < 0 || position > GetLength() + 1) {
        cout << "输入位置错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        Node *pnew, *ptemp = head;
        pnew = new Node;
        pnew->data = d;
        while (position-- > 1)
            ptemp = ptemp->pNext;
        pnew->pNext = ptemp->pNext;
        ptemp->pNext = pnew;
    }
}

void CircleList::TraverseLinkList() {
    Node *ptemp = head->pNext;
    while (ptemp != head) {
        cout << ptemp->data << " ";
        ptemp = ptemp->pNext;
    }
    cout << endl;
}

bool CircleList::IsEmpty() {
    if (head->pNext == head)
        return true;
    else
        return false;
}

int CircleList::GetLength() {
    int n = 0;
    Node *ptemp = head->pNext;
    while (ptemp != head) {
        n++;
        ptemp = ptemp->pNext;
    }
    return n;
}

void CircleList::DeleteNode(int position) {
    if (position < 0 || position > GetLength()) {
        cout << "输入位置错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        Node *ptemp = head, *pdelete;

        while (position-- > 1)
            ptemp = ptemp->pNext;
        pdelete = ptemp->pNext;
        ptemp->pNext = pdelete->pNext;
        delete pdelete;
        pdelete = NULL;
    }
}

void CircleList::DeleteLinkList() {
    Node *pdelete = head->pNext, *ptemp;
    while (pdelete != head) {
        ptemp = pdelete->pNext;
        head->pNext = ptemp;
        delete pdelete;
        pdelete = ptemp;
    }
}
