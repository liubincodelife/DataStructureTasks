#include <iostream>

using namespace std;

//��������
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//ð������
//ʱ�临�Ӷȣ���ã�O(n) ��O(n^2)
//�ռ临�Ӷȣ�O(1)

bool Bubble_Sort(int array[], int length)
{
    if (length <= 1)
        return false;
    for (int i = 0; i < length; i++)
    {
        bool flag = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    return true;
}

//��������
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O(1)

bool Insertion_Sort(int array[], int length)
{
    if (length <= 1)
        return false;
    for (int i = 1; i < length; i++)
    {
        int value = array[i];  //������Ҫ���������
        int j = i - 1;
        for (; j >=0; j--)
        {
            if (array[j] > value)
            {
                array[j + 1] = array[j];  //�������ݰ��ƣ�ֱ���ҵ����ֲ����λ��
            }
            else
            {
                break;
            }
        }
        array[j + 1] = value;
    }

    return true;
}

//ѡ������
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O(1)

bool Selection_Sort(int array[], int length)
{
    if (length <= 1)
        return false;

    for (int i = 0; i < length; i++) 
    { 
        //���ҵ�δ�����������Сֵ����
        int min = i;
        for (int j = i + 1; j < length; j++) 
        {
            if (array[j] < array[min]) 
            {
                min = j;
            }
        }

        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    return true;
}

//�鲢����
//ʱ�临�Ӷȣ�O(nlogn)
//�ռ临�Ӷȣ�O(n)

void Merge(int a[], int left, int mid, int right)
{
    //��������ĳ���
    int length1 = mid - left + 1;
    int length2 = right - mid;

    //���������µ��ڴ�ռ�洢ԭ����
    int *l1 = new int[length1];
    int *l2 = new int[length2];

    for (int i = 0; i < length1; ++i)
    {
        l1[i] = a[left + i];
    }
    for (int j = 0; j < length2; ++j)
    {
        l2[j] = a[j + mid + 1];
    }

    //����ԭ����֮�󣬱Ƚ���������
    int i = 0, j = 0;
    int k = length1;
    //�Ƚ��������е��غϲ��֣���������
    while (i < length1 && j < length2)
    {
        if (l1[i] < l2[j])
        {
            a[left++] = l1[i++];
        }
        else
        {
            a[left++] = l2[j++];
        }
    }
    //�����е�ʣ�ಿ�ֱַ���ڽ�β
    while (i < length1)
    {
        a[left++] = l1[i++];
    }

    while (j < length2)
    {
        a[left++] = l2[j++];
    }

    //������ڴ���Ҫ�ͷŵ�
    delete[]l1;
    delete[]l2;
}

bool Merge_Sort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;     //���Ƚ��з�����Ȼ��ݹ����
        Merge_Sort(array, low, mid);
        Merge_Sort(array, mid + 1, high);//��һ�ν����Ϊ�������䣬���кϲ�����
        Merge(array, low, mid, high);
    }

    return true;
}

//��������
//ʱ�临�Ӷȣ���ã�O(nlogn) ��O(n^2)
//�ռ临�Ӷȣ�O(1)

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            swap(array + i, array + j);
            i++;
        }
    }

    swap(array + i, array + high);

    return i;
}


void Quick_Sort(int array[], int low, int high)
{
    if (low >= high)
        return;

    int mid = partition(array, low, high);
    Quick_Sort(array, low, mid - 1);
    Quick_Sort(array, mid + 1, high);
}

void Quick_Sort(int array[], int length)
{
    Quick_Sort(array, 0, length - 1);
}

void print(int array[], int length)
{
    cout << "the array after sorted is: " <<endl;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void test1()
{
    cout << "test1 Bubble sorted running......" << endl;
    int array[10] = { 1, 3, 6, 2, 4, 9, 5, 8, 7, 0 };
    int length = sizeof(array) / sizeof(int);
    Bubble_Sort(array, length);
    print(array, length);
}

void test2()
{
    cout << "test2 Insertion sorted running......" << endl;
    int array[10] = { 1, 3, 6, 2, 4, 9, 5, 8, 7, 0 };
    int length = sizeof(array) / sizeof(int);
    Insertion_Sort(array, length);
    print(array, length);
}

void test3()
{
    cout << "test3 Selection sorted running......" << endl;
    int array[10] = { 1, 3, 6, 2, 4, 9, 5, 8, 7, 0 };
    int length = sizeof(array) / sizeof(int);
    Selection_Sort(array, length);
    print(array, length);
}

void test4()
{
    cout << "test4 Quick sorted running......" << endl;
    int array[10] = { 1, 3, 6, 2, 4, 9, 5, 8, 7, 0 };
    //int array[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array) / sizeof(int);
    Quick_Sort(array, length);
    print(array, length);
}

int main(int argc, char** argv)
{
    test3();
    test4();
    getchar();
    return 0;
}