#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
void PrintTheBoard(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout<<endl<<endl<<endl;
}
bool isSafe(vector<vector<char>> &board, int row, int col, int n){
    int  i = row;
    int j = col ;
    // row 
    while (j >=0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;    
    }

     i = row;
    j = col ;
    // upper left diag 
    while (i >=0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
        i--;    
    }

 i = row;
    j = col ;
    // lower left diag 
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
        i++;   
    }

    return true;
    
}
void solve(vector<vector<char>> &board,  int col, int n)
{
    // base case
    if (col >= n)
    {
        PrintTheBoard(board, n);
        return;
    }

    // place queen col wise
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {

            // place
            board[i][col] = 'Q';
            // call
            solve(board,  col + 1, n);
            // unplace / backtracking
            board[i][col] = '-';
        }
    }
}
int main()
{
    int n = 8;
    int col = 0;

    vector<vector<char>> board(n, vector<char>(n, '-'));
    // PrintTheBoard(board , n);

    solve(board,col, n);
    return 0;
}