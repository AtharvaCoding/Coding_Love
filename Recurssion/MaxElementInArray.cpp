#include <iostream>
#include <string.h>
using namespace std;

// Function Recurssion
void MaxElement(int arr[], int n , int i , int& maxi){ // address bhejh de // same maxi element par update karenga vo function 
    // base case 
    if (i>=n)
    {
        return;
    }

    // 1 case 
    maxi = max(arr[i] , maxi);
    // baki recurssion
    MaxElement(arr, n , i+1 , maxi);

    
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int i = 0;
    int maxi = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     maxi = max(maxi , arr[i]);
    // }
    // cout << "the Maximun element is : "<< maxi << endl;


    MaxElement(arr , n, i , maxi);
    cout << "the Maximun element is : "<< maxi << endl;
    

    return 0;
}