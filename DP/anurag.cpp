#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int ZeroOneKnapsackTabulation(int weight[], int value[], int capacity, int size)
{
    vector<vector<int>> dp(size, vector<int>(capacity + 1, 0));

    // Base case for the last row
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[size - 1] <= w)
        {
            dp[size - 1][w] = value[size - 1];
        }
        else
        {
            dp[size - 1][w] = 0;
        }
    }

    // Calculate the dp values for the rest of the table
    for (int index = size - 2; index >= 0; index--)
    {
        for (int cap = 0; cap <= capacity; cap++)
        {
            int include = 0;
            if (cap - weight[index] >= 0)
            {
                include = dp[index + 1][cap - weight[index]] + value[index];
            }
            int exclude = dp[index + 1][cap];
            dp[index][cap] = max(include, exclude);
        }
    }

    return dp[0][capacity];
}

int main()
{
    int weight[] = {1, 2, 3};
    int value[] = {6, 10, 12};
    int capacity = 5;
    int size = 3;

    int ans = ZeroOneKnapsackTabulation(weight, value, capacity, size);
    cout << "The Ans3 is " << ans << endl;

    return 0;
}
