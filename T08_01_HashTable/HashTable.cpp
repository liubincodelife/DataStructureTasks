#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *name;//�ֶ���
    char *desc;//����
    struct node *next;
}node;

#define HASHSIZE 100 //hash����
static node* hashtable[HASHSIZE];//����һ��hash���飬�������ÿ��Ԫ����һ��hash���ָ��,����������ȫ�־�̬����,Ĭ�ϳ�ʼ��ΪNULL

unsigned int hash(char *s)
{//��ϣ����
    unsigned int h = 0;
    for (; *s; s++)
        h = *s + h * 31;//�������ַ��������ض���ϵת��Ϊһ��������Ȼ���hash����ȡ��
    return h%HASHSIZE;
}

node* lookup(char *str)
{
    unsigned int hashvalue = hash(str);
    node* np = hashtable[hashvalue];
    for (; np != NULL; np = np->next)
    {//����������ַ������ĳ�ͻ,���ص��ǵ�һ��������
        if (!strcmp(np->name, str))//strcmp��ȵ�ʱ��ŷ���0
            return np;
    }
    return NULL;
}

char* search(char* name)
{//��hash������ض�Ԫ��(Ԫ�����ַ�����
    node* np = lookup(name);
    if (np == NULL)
        return NULL;
    else
        return np->desc;
}

node* malloc_node(char* name, char* desc)
{//�ڶ���Ϊ�������ڴ棬�������
    node *np = (node*)malloc(sizeof(node));
    if (np == NULL)
        return NULL;
    np->name = name;
    np->desc = desc;
    np->next = NULL;
    return np;
}

int insert(char* name, char* desc)
{
    unsigned int hashvalue;
    hashvalue = hash(name);
    //ͷ�巨�����ܸ�hashλ����û��������㣬ֱ�Ӳ�����
    node* np = malloc_node(name, desc);
    if (np == NULL) return 0;//������û�гɹ�����ֱ�ӷ���
    np->next = hashtable[hashvalue];
    hashtable[hashvalue] = np;
    return 1;
}

/* A pretty useless but good debugging function,
which simply displays the hashtable in (key.value) pairs
*/
void displayHashTable()
{//��ʾhash��Ԫ�أ��������գ�
    node *np;
    unsigned int hashvalue;
    for (int i = 0; i < HASHSIZE; ++i)
    {
        if (hashtable[i] != NULL)
        {
            np = hashtable[i];
            printf("\nhashvalue: %d (", i);
            for (; np != NULL; np = np->next)
                printf(" (%s.%s) ", np->name, np->desc);
            printf(")\n");
        }
    }
}

void cleanUp()
{//���hash��
    node *np, *tmp;
    for (int i = 0; i < HASHSIZE; ++i)
    {
        if (hashtable[i] != NULL)
        {
            np = hashtable[i];
            while (np != NULL)
            {
                tmp = np->next;
                //free(np->name);
                //free(np->desc);
                free(np);
                np = tmp;
            }
        }
    }
}

int main()
{
    char* names[] = { "First Name","Last Name","address","phone","k101","k110" };
    char* descs[] = { "Kobe","Bryant","USA","26300788","Value1","Value2" };

    for (int i = 0; i < 6; ++i)
        insert(names[i], descs[i]);
    printf("we should see %s\n", search("k110"));
    insert("phone", "9433120451");//��������hash�ǳ�ͻ�ģ�Ϊ�˲��Գ�ͻ����µĲ���
    printf("we have %s and %s\n", search("k101"), search("phone"));
    displayHashTable();
    cleanUp();
    return 0;
}