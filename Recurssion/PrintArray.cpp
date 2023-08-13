#include <iostream>
#include <string.h>
using namespace std;
void PrintArr(int arr[], int n , int i){
    // Base Case 
    if (i >=n){
        return;
    }
    cout << arr[i] << " ";

    PrintArr(arr,n,i+1);

}
int main(){
    int arr[] = {10,20,30,40,50};
    int n = 5;
    int i = 0;
    PrintArr(arr , n , i);
    return 0;
}