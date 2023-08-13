#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;

    for (int j = s; j <= e - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[e]);

    return i + 1;
}

void QuickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int pivotIndex = Partition(arr, s, e);
        QuickSort(arr, s, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, e);
    }
}

int main()
{
    int arr[] = {8, 1, 20, 30, 6, 5, 60, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;
    QuickSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
