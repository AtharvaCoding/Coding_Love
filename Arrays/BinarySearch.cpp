#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int BinarySearch(int arr[], int key ,int start , int end)
// {

//     int mid = start  + (end - start)/2;
//     if (arr[mid] == key)
//     {
//         return mid + 1;
//     }
//     else if (key > arr[mid])
//     {
//         start = mid+1;
//         BinarySearch(arr , key , start , end);
//     }
//     else{
//         end = mid-1 ;
//         BinarySearch(arr , key , start , end);

//     }

// }
int BinarySearch(int arr[], int key, int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid + 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
            return BinarySearch(arr, key, start, end); // Add return before the recursive call
        }
        else
        {
            end = mid - 1;
            return BinarySearch(arr, key, start, end); // Add return before the recursive call
        }
    }

    return -1; // Key not found
}

// int BinarySearch(int arr[], int size , int key){
//     int start = 0 ;
//     int end = size -1;
//     while (start <= end)
//     {
//         int mid = (start + end)/2;
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if (arr[mid] < key)
//         {
//             start = mid - 1;
//         }
//         else
//         {
//             end = mid + 1 ;
//         }

//     }
//     // return -1 ;

// }
int BinarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Calculate mid correctly

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1; // Update start index
        }
        else
        {
            end = mid - 1; // Update end index
        }
    }

    return -1; // Key not found
}
int main()
{
    int arr[] = {1, 3, 7, 9, 11, 12, 15, 19};

    int key;
    cout << " please enter the key form this array 1,3,7,9,11,12,15,19 " << endl;
    cin >> key;

    cout << "the element is present at the index : " << BinarySearch(arr, key, 0, 7) << endl;
    cout << "the element is present at the index : " << BinarySearch(arr, 8, key) << endl;

    vector<int> v = {1, 2, 3, 4, 8, 9, 11, 15, 16};
    if (binary_search(v.begin(), v.end(), 15))
    {
        cout << "found " << endl;
    }
    else
    {
        cout << "not found " << endl;
    }

    return 0;
}
