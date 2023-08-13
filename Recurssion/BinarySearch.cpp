#include <iostream>
#include <string.h>
using namespace std;
int BinarySearch(int arr[] , int n , int s , int e, int key){
    // base case 
    if (s >= e)
    {
        return -1;
    }

    //  ek case 
    int mid = s  + ( e-s)/2 ; 
    if(arr[mid] == key){        //dhyaan de arr[mid] != mid 
        return mid ;
    }

    else if ( mid > key){
        e = mid -1 ;
    }
    else {
        s = mid + 1;
    }
    mid = s  + ( e-s)/2 ;
    //  baki recurssion 
    return BinarySearch(arr , n , s ,e ,key);

    
}
int main(){
int arr[] = {1,2,5,6,7,8,10,12,16,18,19,21};
int n = 12;
int s = 0;
int e = n-1;
int key = 19;

cout << " The key " << key << " is at position " << BinarySearch(arr , n , s , e , key) << endl;
return 0;
}   