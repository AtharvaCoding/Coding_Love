#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int TargetSumFromArray(vector<int> &arr, int target, int output)
{

    // base case
    if (target == output)
    {
        return 0;
    }
    if (target < output)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = TargetSumFromArray(arr, target, output + arr[i]);
        if(ans!=INT_MAX)
            mini = min(mini, ans + 1);
    }

    return mini;
}

int TargetSumFromArray(vector<int> arr, int target)
{
    // base case
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    // Ek case
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = TargetSumFromArray(arr, target - arr[i]);
        if(ans!=INT_MAX)
         mini = min(mini, ans + 1);
    }
    return mini; 

}
int main()
{
    // vector<int> arr {1, 2};
    // int target = 3;
    // int output = 0;
    
    vector<int> arr {1, 2,3};
    int target = 5;
    int output = 0;
    cout<< TargetSumFromArray(arr, target , output)<<endl;
    cout << TargetSumFromArray(arr, target)<<endl;
    return 0;
}