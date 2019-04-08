#pragma once

using namespace std;

//�����
class Node {
public:
    int data;
    Node *pNext;
};
//����ѭ��������
class CircleList {
public:
    CircleList() {
        head = new Node;
        head->data = 0;
        head->pNext = head;
    }
    ~CircleList() { delete head; }
    void CreateLinkList(int n);				//��������ѭ������
    void InsertNode(int position, int d);	//��ָ��λ�ò�����
    void TraverseLinkList();				//��������
    bool IsEmpty();							//�ж������Ƿ�Ϊ��
    int GetLength();						//�õ�����ĳ���
    void DeleteNode(int position);			//ɾ��ָ��λ�ý��
    void DeleteLinkList();					//ɾ������
private:
    Node *head;
};

void CircleList::CreateLinkList(int n) {
    if (n < 0) {
        cout << "�������������" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        Node *pnew, *ptemp = head;
        int i = n;
        while (n-- > 0) {
            cout << "�����" << i - n << "�����ֵ��";
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
        cout << "����λ�ô���" << endl;
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
        cout << "����λ�ô���" << endl;
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
