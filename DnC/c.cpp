#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int arr[], int s, int e)
{
    int count = s;
    int pivot = arr[s];
    for (int i = s + 1; i <= e; i++) // Corrected the loop starting index to s + 1
    {
        if (arr[i] > pivot)
        {
            count++;
        }
    }
    swap(arr[s], arr[count]); // Swapped arr[s] with arr[count] instead of pivot

    int i = s;
    int j = e;

    while (i <= j)
    {
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if (arr[i] <= pivot) // Changed the condition to include equal to sign
        {
            i++;
        }
        if (arr[j] >= pivot) // Changed the condition to include equal to sign
        {
            j--;
        }
    }
    return count;
}

void QuickSort(int arr[], int s, int e)
{
    if (s >= e) // Corrected the base case condition to s >= e
    {
        return;
    }

    int ans = Partition(arr, s, e);
    QuickSort(arr, s, ans - 1);
    QuickSort(arr, ans + 1, e);
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
