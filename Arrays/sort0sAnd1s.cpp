#include <iostream>
using namespace std;
void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

   
}
void sorting(int arr[], int size)
{
    int end = size - 1;
    int start = 0;
    int i = 0 ;

    while(i!=end)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[start]);
            i++;
            start++;
        }
        else
        {
            swap(arr[i], arr[end]);
            
            end--;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 0, 1, 1, 1, 0, 1, 0};
    int size = 9;
    cout << "before sorting the array" << endl;
    printarr(arr, size);
    cout << endl;

    sorting(arr, size);

    cout << "after sorting the array" << endl;
    // printarr(arr, size);
    for(auto val : arr){
        cout <<val << " ";
    }
    //  syntx for ( automatic value : data strucute)
}