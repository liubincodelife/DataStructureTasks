#pragma once


/*����ڵ����ݽṹ*/
template <typename T> 
struct node 
{
    T m_nValue;
    node<T> *prior, *next;
};

template <typename T> class DoubleList
{
private:
    node<T> *head;
public:
    DoubleList()
    {
        head = new node<T>;
        head->next = head->prior = NULL;
    }
    ~DoubleList()
    {
        DestoryLink();
    }
    //���˫����
    void ClearLink()
    {
        node<T> *p = head->next, *q = NULL;
        while (p) {
            q = p->next;
            delete p;
            p = q;
        }
        head->next = NULL;
    }
    //����˫����
    void DestoryLink()
    {
        ClearLink();
        if (head) {
            delete head;
            head = NULL;
        }
    }
    //��ӡ˫����
    void PrintLink()
    {
        node<T> *p = head->next;
        while (p) {
            cout << p->m_nValue << " ";
            p = p->next;
        }
        cout << endl;
    }
    //��˫����ĩβ��ӽڵ�
    bool AppendLink(T e)
    {
        node<T> *p = head, *s = NULL;
        s = new node<T>;
        if (s == NULL)
            return false;
        s->m_nValue = e;
        s->next = s->prior = NULL;
        while (p->next) {
            p = p->next;
        }
        p->next = s;
        s->prior = p;
        return true;
    }
    //��ȡ˫����ĳ���
    int Length()
    {
        int i = 0;
        node<T> *p = head->next;
        while (p)
        {
            ++i;
            p = p->next;
        }
        return i;
    }
    //�ڵ�pos��λ�ò����½ڵ�
    bool InsertLink(int pos, T e)
    {
        node<T> *p = head, *s = NULL;
        int j = 0;
        s = new node<T>;
        if (s == NULL)
            return false;
        s->m_nValue = e;
        s->prior = s->next = NULL;
        while (p && j < pos - 1)
        {
            ++j;
            p = p->next;
        }
        if (p == NULL || j > pos - 1)
        {
            return false;
        }
        s->next = p->next;
        if (p->next != NULL) { //��p�����һ���ڵ�ʱ��p->next == NULL
            p->next->prior = s;
        }
        p->next = s;
        s->prior = p;
        return true;
    }
    //ɾ����i�����ϵĽڵ�
    bool DeleteNode(int pos)
    {
        if (pos < 1 || pos > Length())
        {
            return false;
        }
        node<T> *p = head;    //p ΪҪɾ���Ľڵ�
        int j = 0;
        while (p && j < pos)
        {
            ++j;
            p = p->next;
        }
        //Ҫע��ɾ�����ǲ���β�ڵ�
        if (p && p->next == NULL) {
            p->prior->next = NULL;
            delete p;
            p = NULL;
        }
        else {
            p->prior->next = p->next;
            p->next->prior = p->prior;
            delete p;
            p = NULL;
        }
        return true;
    }

    //ɾ��ָ��Ԫ�صĽڵ�
    bool DeleteNode(T e)
    {
        node<T> *p = head->next;
        while (p) {
            if (p->m_nValue == e) {
                break;
            }
            p = p->next;
        }
        if (p == NULL) {
            cout << "not found the elem :" << e << endl;
            return false;
        }
        //�ж�Ҫɾ�����ǲ���β�ڵ�
        if (p->next == NULL) {
            p->prior->next = NULL;
        }
        else {
            p->prior->next = p->next;
            p->next->prior = p->prior;
        }
        delete p;
        p = NULL;
        return true;
    }

};
