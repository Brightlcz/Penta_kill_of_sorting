//参考自https://blog.csdn.net/morewindows/article/details/6678165
#include <iostream>
using namespace std;
#define N 5
//将有二个有序数列a[first...mid]和a[mid+1...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;

    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)                     //这两个while是让没有合并完的序列合并
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}

void mergesort(int a[], int first, int last, int temp[])
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);    //左边有序
        mergesort(a, mid + 1, last, temp); //右边有序
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并
    }
}

int main()
{
   // int temp[N];
   int *p = new int[N];
   int arr[] = {5, 2, 4, 3, 8};
   mergesort(arr, 0, 4, p);
   for (int i = 0; i < 5; i++)
   {
       cout << arr[i] << " ";
    }
    delete[] p;
    return 0;
}