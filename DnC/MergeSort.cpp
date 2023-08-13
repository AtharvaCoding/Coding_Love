#include <iostream>
#include <string.h>
using namespace std;
void merge(int arr[], int s, int e)
{
    //  create two arryas of length mid-s+1 & e-mid
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    // copy L element
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy R element
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge
    int Lindex = 0;
    int Rindex = 0;
    int MainArrayIndex = s;

    while (Lindex < len1 && Rindex < len2)
    {
        if (left[Lindex] < right[Rindex])
        {
            arr[MainArrayIndex] = left[Lindex];
            MainArrayIndex++;
            Lindex++;
        }
        else
        {
            arr[MainArrayIndex] = right[Rindex];
            MainArrayIndex++;
            Rindex++;
        }
    }
    // copy
    while (Lindex < len1)
    {
        arr[MainArrayIndex] = left[Lindex];
        MainArrayIndex++;
        Lindex++;
    }
    while (Rindex < len2)
    {
        arr[MainArrayIndex] = right[Rindex];
        MainArrayIndex++;
        Rindex++;
    }
}
void mergersort(int arr[], int s, int e)
{
    //  base case
    // s== e single element // s > e invalid array
    if (s >= e)
    {
        return;
    }

    //  recur
    int mid = s + (e - s) / 2;
    mergersort(arr, s, mid);     // left
    mergersort(arr, mid + 1, e); // right

    //  merge
    merge(arr, s, e);
}
int main()
{
    int arr[] = {9, 11, 7, 3, 5};
    int n = 5;
    int s = 0;
    int e = n - 1;
    mergersort(arr, s, e);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}