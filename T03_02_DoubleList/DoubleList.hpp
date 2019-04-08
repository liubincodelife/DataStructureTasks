#pragma once


/*定义节点数据结构*/
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
    //清空双链表
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
    //销毁双链表
    void DestoryLink()
    {
        ClearLink();
        if (head) {
            delete head;
            head = NULL;
        }
    }
    //打印双链表
    void PrintLink()
    {
        node<T> *p = head->next;
        while (p) {
            cout << p->m_nValue << " ";
            p = p->next;
        }
        cout << endl;
    }
    //在双链表末尾添加节点
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
    //获取双链表的长度
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
    //在第pos个位置插入新节点
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
        if (p->next != NULL) { //当p是最后一个节点时，p->next == NULL
            p->next->prior = s;
        }
        p->next = s;
        s->prior = p;
        return true;
    }
    //删除第i个置上的节点
    bool DeleteNode(int pos)
    {
        if (pos < 1 || pos > Length())
        {
            return false;
        }
        node<T> *p = head;    //p 为要删除的节点
        int j = 0;
        while (p && j < pos)
        {
            ++j;
            p = p->next;
        }
        //要注意删除的是不是尾节点
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

    //删除指定元素的节点
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
        //判读要删除的是不是尾节点
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
