#pragma once

template<typename T> class MergeTwoSortedArray
{
public:
    MergeTwoSortedArray();
    ~MergeTwoSortedArray();
    T* mergeArrays(T* array1, int m, T* array2, int n);
private:
};

template<typename T>
MergeTwoSortedArray<T>::MergeTwoSortedArray()
{

}

template<typename T>
MergeTwoSortedArray<T>::~MergeTwoSortedArray()
{

}

template<typename T>
T* MergeTwoSortedArray<T>::mergeArrays(T* array1, int m, T* array2, int n)
{
    T* newArray = new T[m + n]();
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (array1[i] < array2[j])
        {
            newArray[k++] = array1[i++];
        }
        else
        {
            newArray[k++] = array2[j++];
        }
    }

    while (i < m)
    {
        newArray[k++] = array1[i++];
    }

    while (j < n)
    {
        newArray[k++] = array2[j++];
    }

    return newArray;

}
