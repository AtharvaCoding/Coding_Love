#include <iostream>
#include <string.h>
#include <limits.h>
#include <vector>
using namespace std;
int main(){
// int n  =  INT_MAX;
// // cin >> n ; 
// int arr[INT_MAX];             static 

// arr[0] = 1;

// cout << arr[0] << endl;



// dymnamic 


// int n ; 
//  cin >> n;

//  int* arr = new int[n];

//  arr[0] = 1 ;
//  cout << arr[0]<<endl;
 


// dynamic 2 d array 


int row = 5 ; 
int col = 3 ;

int** arr = new int*[row];
for (int i = 0; i < row; i++)
{
    arr[i] = new int[col];
}

for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
        cout << arr[i][j] << " ";
    }
    cout << endl;
    
}

// dealocation 

for (int i = 0; i < 5; i++)
{
    delete [] arr[i];
}
delete[]arr;


//  vector 

// vector<int> vrr (5 , 10);
// cout << "vrr";
// for (int i = 0; i < vrr.size(); i++)
// {
//     cout << vrr[i] << " ";
// }

// cout << endl;
// // 2d 
// vector<vector<int>> vrr1 (5 , vector<int> (5  , 0));
// for (int i = 0; i < 5; i++)
// {
//     for (int j = 0; j < 5; j++)
//     {
//         cout << vrr1[i][j]<< " ";
//     }
//     cout << endl;
    
// }







return 0;
}   