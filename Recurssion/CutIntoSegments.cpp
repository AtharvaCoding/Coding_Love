#include <iostream>
#include <string.h>
using namespace std;
int solve(int n, int x, int y, int z)
{
    //  base case
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    int ans1 = solve(n - x, x, y, z) + 1;
    int ans2 = solve(n - y, x, y, z) + 1;
    int ans3 = solve(n - z, x, y, z) + 1;

    int ans = max(ans1, max(ans2, ans3));
    return ans;
}
int main()
{
    // int n = 7 ;
    // int x = 5;
    // int y = 2;
    // int z = 2; // 2

    int n = 8;
    int x = 3;
    int y = 3;
    int z = 3; // INT_MIN

    // int n = 7;
    // int x = 1;
    // int y = 1;
    // int z = 2; // 7

    if (solve(n, x, y, z) < 0)
    {
        cout << "0";
    }
    else
    {

        cout << solve(n, x, y, z) << endl;
    }

    return 0;
}