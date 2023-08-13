#include <iostream>
#include <string.h>
using namespace std;
void merge(int arr[] , int s , int e){
    int mid = s +(e-s)/2;
    int size1 = mid - s +1;
    int size2 = e - mid;
    int* left = new int[size1];
    int* right = new int[size2];
    // copy 
    int k = s;
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[k];
        k++;
    } 
    k = mid + 1;
    for (int i = 0; i < size2; i++)
    {
        right[i] = arr[k];
        k++;
    }


    // merge 
    int Lindex = 0;
    int Rindex = 0;
    int MainArrayIndex = s;

    while (Lindex<size1 && Rindex<size2)
    {
        if (left[Lindex] < right[Rindex])
        {
            arr[MainArrayIndex++] = left[Lindex++];
        }
        else{
            arr[MainArrayIndex++] = right[Rindex++];

        }
        
    }
    while (Lindex<size1)
    {
        arr[MainArrayIndex++] = left[Lindex++];
    }
    
    while (Rindex<size2)
    {
        arr[MainArrayIndex++] = right[Rindex++];
    }
    
    
    
}
void MergeSort(int arr[] , int s , int e){
    if (s>=e)
    {
        return;
    }

    int mid = s +(e-s)/2;;

    MergeSort(arr , s , mid);
    MergeSort(arr , mid +1 , e);

    merge(arr , s , e);
    
}
int main()
{
    int arr[] = { 2,2,2,2,2,2,2,2,2,1,1,1,1,1,8,85,64,321446546,423,0};
    int n = 20 ;
    int s=  0;
    int e = n-1;
    MergeSort(arr , s , e);
    for (int i = 0; i < n; i++)
    {

        cout<< arr[i] << " ";
    }
    
    return 0;
}