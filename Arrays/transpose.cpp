#include <iostream>
using namespace std;

void PrintArr(int arr[][3] , int rows , int cols ){
     for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}
void Transpose(int arr[][3], int rows , int cols , int Trans[3][3]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // swap(arr[i][j] , arr[j][i]);
            Trans[i][j] = arr[j][i];
        }
        // cout << endl;
    }
}
int main()
{
    int arr[3][3];
    int rows = 3 ;
    int cols =3 ;
    cout << "input 9 integers"<< endl ;

    for (int i = 0; i <rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
        
    }

    cout << "the 2D array : "<< endl;
    PrintArr(arr, rows, cols );

    cout << "the transpose of the given 2D array is "<< endl ;

    // Transpose(arr , rows , cols ); the logic is wrong , we are swapping the elements 2 times in the array 
    int Trans [3][3];
    Transpose(arr , rows , cols , Trans);
    PrintArr(Trans, rows, cols );
    
   
    
    
    return 0;
}