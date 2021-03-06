#include <iostream>

using namespace std;

//交换函数
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//冒泡排序
//时间复杂度：最好：O(n) 最差：O(n^2)
//空间复杂度：O(1)

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

//插入排序
//时间复杂度：O(n^2)
//空间复杂度：O(1)

bool Insertion_Sort(int array[], int length)
{
    if (length <= 1)
        return false;
    for (int i = 1; i < length; i++)
    {
        int value = array[i];  //保存需要插入的数字
        int j = i - 1;
        for (; j >=0; j--)
        {
            if (array[j] > value)
            {
                array[j + 1] = array[j];  //进行数据搬移，直到找到数字插入的位置
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

//选择排序
//时间复杂度：O(n^2)
//空间复杂度：O(1)

bool Selection_Sort(int array[], int length)
{
    if (length <= 1)
        return false;

    for (int i = 0; i < length; i++) 
    { 
        //先找到未排序区间的最小值索引
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

//归并排序
//时间复杂度：O(nlogn)
//空间复杂度：O(n)

void Merge(int a[], int left, int mid, int right)
{
    //两段区间的长度
    int length1 = mid - left + 1;
    int length2 = right - mid;

    //分配两段新的内存空间存储原内容
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

    //存入原内容之后，比较两个序列
    int i = 0, j = 0;
    int k = length1;
    //比较两个序列的重合部分，进行排序
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
    //两序列的剩余部分分别放于结尾
    while (i < length1)
    {
        a[left++] = l1[i++];
    }

    while (j < length2)
    {
        a[left++] = l2[j++];
    }

    //分配的内存需要释放掉
    delete[]l1;
    delete[]l2;
}

bool Merge_Sort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;     //首先进行分区，然后递归操作
        Merge_Sort(array, low, mid);
        Merge_Sort(array, mid + 1, high);//第一次将其分为两个区间，进行合并操作
        Merge(array, low, mid, high);
    }

    return true;
}

//快速排序
//时间复杂度：最好：O(nlogn) 最差：O(n^2)
//空间复杂度：O(1)

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