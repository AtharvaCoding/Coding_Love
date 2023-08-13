#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
bool isSafe(int arr[][3],vector<vector<bool>>& visited , int row , int col ,int i , int j){
    if (((i>=0 && i < row) && (j >= 0 && j < col)) && 
    (arr[i][j] == 1) && 
    (visited[i][j] == false))
    {
        return true;
    }
    else{

    return false;
    }
}
void solve(int arr[][3],vector<vector<bool>>& visited , int row , int col , string output , vector<string>& path , int i , int j){
    // base case []
    if (i == row-1 && j == row-1)
    {
        path.push_back(output);
        return;
    }

    
    // Down 
    if (isSafe(arr,visited,row,col,i+1,j))
    {
        visited[i+1][j] = true;
        // output += 'D';
        solve(arr, visited , row , col , output + 'D' , path , i+1 , j);
        // backtracking
        visited[i+1][j] = false;
    
    }
    //  up 
    if (isSafe(arr,visited,row,col,i-1,j))
    {
        visited[i-1][j] = true;
        // output += 'D';
        solve(arr, visited , row , col , output + 'U' , path , i-1 , j);
        // backtracking
        visited[i-1][j] = false;
    }

    // left 

    if (isSafe(arr,visited,row,col,i,j-1))
    {
        visited[i][j-1] = true;
        // output += 'D';
        solve(arr, visited , row , col , output + 'L' , path , i , j-1);
        // backtracking
        visited[i][j-1] = false;

    }
    // right 
    if (isSafe(arr,visited,row,col,i,j+1))
    {
        visited[i][j+1] = true;
        // output += 'D';
        solve(arr, visited , row , col , output + 'R' , path , i , j+1);
        // backtracking 
        visited[i][j+1] = false;
    }
}
int main()
{
    //  Test case 1 
    int arr[3][3] = { {1,0,0},{1,1,0},{1,1,1}};
    int row = 3 ; 
    int col = 3;

    // Test case 2 
    // int arr[4][4] = { {1,0,0,0},{1,1,0,0},{1,1,0,0} , {0,1,1,1}};
    // int row = 4 ; 
    // int col = 4;
    if (arr[0][0] == 0)
    {
        cout << "No path";
        return 0;
    }
    
    vector<vector<bool>> visited (row, vector<bool>(col , false));
    visited[0][0] = 1;
    string output = "";
    vector<string> path ;
    int i = 0;
    int j = 0;
    solve(arr, visited , row , col , output , path , i , j);

    cout << "printing the results " << endl;
  for(auto i: path) {
    cout << i << " ";
  }
  cout << endl;
  if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
  }

    return 0;
}