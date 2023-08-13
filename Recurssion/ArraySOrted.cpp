#include <iostream>
#include <string.h>
using namespace std;
bool IsSorted(int arr[] , int n , int i){
    // base case 
    if (i >= n)
    {
        return 1;
    }

    // ek case 
    if(arr[i+1] < arr[i]){
        return false;   
    }
    
    // baki recurssion
    return IsSorted( arr , n , i+1);

    
}
int main()
{
    // int arr[] = {1};
    int arr[] = {1,2,3,4,5,2};
    int n = 1;
    if(IsSorted(arr , n ,0)){
        cout<<"The Array is sorted!"<<endl;
    }
    else{
        cout<<"The Array is not sorted! "<<endl;
    }
    return 0;
}