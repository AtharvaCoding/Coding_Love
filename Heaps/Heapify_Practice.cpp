#include <iostream>
#include <unordered_map>
using namespace std;
void heapify(int arr[], int n , int i){
    int index = i ; 
    int LChild = i*2 ; 
    int RChild = i*2 + 1;

    int largest = i;

    // largest ko compare crow , uske L child aur R child ke sath 
    if (LChild < n && arr[largest] < arr[LChild])
    {
        largest = LChild;
    }
    if (RChild < n && arr[largest] < arr[RChild])
    {
        largest = RChild;
    }

    if (largest != index)
    {
        // iska matlab jo node hai vo uske sahi jagah par nahi hai 
        swap(arr[largest] , arr[index]);
        index = largest ; 
        heapify(arr , n , index);
    }
    
    
}
void BuildHeap(int arr[] , int n){
    for (int i = n/2 ; i > 0 ; i--)
    {
        heapify(arr , n , i);
    }
    
}
void HeapSort(int nums[], int n){

    while (n != 1)
    {
        swap(nums[1] , nums[n-1]);
        n--;

        heapify(nums , n ,1);
    }
    
}

int main()
{
    // int arr[] = {-1,12,13,15,11,10,14};
    // int n = 7;
    // int i = 1;
    // cout <<endl << "Before Heapify " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    
    // heapify(arr , n , i);
    // cout <<endl << "After Heapify " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    cout << endl << "Building the heap " << endl;
    int nums[] = {-1,12,13,15,11,10,14};
    int nums_size = 7;
    cout <<endl << "Before Building the heap " << endl;
    for (int i = 0; i < nums_size; i++)
    {
        cout << nums[i] << " ";
    }
    BuildHeap(nums , nums_size);
    cout <<endl << "After Building the heap " << endl;
    for (int i = 0; i < nums_size; i++)
    {
        cout << nums[i] << " ";
    }

    cout <<endl <<  "Lets Try Sorting the arr using HEAP SORT" << endl;
    // nums_size -= 1;
    HeapSort(nums , nums_size);
    cout <<endl << "After Sorting the heap " << endl;
    for (int i = 0; i < nums_size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}