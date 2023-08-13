#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int fac = factorial(n - 1) * n;
    return fac;
}
int main()
{
    // int n = 5 ;
    int n = 30;
    cout << "The factorial of the " << n << " is : " << factorial(n);
    return 0;
}