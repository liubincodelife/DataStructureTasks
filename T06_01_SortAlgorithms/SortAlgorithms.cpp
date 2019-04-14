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
bool Selection_Sort(int array[], int length)
{
    if (length <= 1)
        return;

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

bool Merge_Sort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;     //���Ƚ��з�����Ȼ��ݹ����
        Merge_Sort(array, left, mid);
        Merge_Sort(array, mid + 1, right);//��һ�ν����Ϊ�������䣬���кϲ�����
        Merge(array, left, mid, right);
    }

    return true;
}

//��������
int partition(int *arr, int p, int r)
{
    //int pivot = arr[r];
    int i, j;

    i = j = p;

    for (; j < r; j++) {
        if (arr[j] < arr[r]) {
            if (i != j)
            {
                swap(arr + i, arr + j);

            }
            i++;
        }
    }

    swap(arr + i, arr + r);
    return i;
}

void Quick_Sort(int *arr, int p, int r)
{
    int q;

    if (p >= r)
        return;

    q = partition(arr, p, r);
    Quick_Sort(arr, p, q - 1);
    Quick_Sort(arr, q + 1, r);
}

void print(int* array, int length)
{
    cout << "the array after sorted is: " <<endl;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
}

void test1()
{
    int array[10] = { 1, 3, 6, 2, 4, 9, 5, 8, 7, 0 };
    int length = sizeof(array) / sizeof(int);
    Bubble_Sort(array, length);
    print(array, length);
}

void test2()
{
    int array[10] = { 1, 3, 6, 2, 4, 9, 5, 8, 7, 0 };
    int length = sizeof(array) / sizeof(int);
    Insertion_Sort(array, length);
    print(array, length);
}

void test3()
{
    int array[10] = { 1, 3, 6, 2, 4, 9, 5, 8, 7, 0 };
    int length = sizeof(array) / sizeof(int);
    Selection_Sort(array, length);
    print(array, length);
}

int main(int argc, char** argv)
{
    test3();
    getchar();
    return 0;
}