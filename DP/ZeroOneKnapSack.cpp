#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int ZeroOneKnapsackRECRR(int weight[], int value[], int capacity, int i, int size)
{
    // base case
    if (i >= size)
    {
        return 0;
    }
    if (i == size - 1)
    {
        if (weight[i] <= capacity)
        {
            return value[i];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (capacity - weight[i] >= 0)
    {
        include = ZeroOneKnapsackRECRR(weight, value, capacity - weight[i], i + 1, size) + value[i];
        // value add kar lavde // yeha fasoge
    }
    int exclude = ZeroOneKnapsackRECRR(weight, value, capacity, i + 1, size);
    int ans = max(include, exclude);
    return ans;
}

int ZeroOneKnapsackMEMO(int weight[], int value[], int capacity, int i, int size, vector<vector<int>> &dp)
{
    // base case
    if (i >= size)
    {
        return 0;
    }
    if (i == size - 1)
    {
        if (weight[i] <= capacity)
        {
            return value[i];
        }
        else
        {
            return 0;
        }
    }

    // 3
    if (dp[i][capacity] != -1)
    {
        return dp[i][capacity];
    }

    int include = 0;
    if (capacity - weight[i] >= 0)
    {
        include = ZeroOneKnapsackRECRR(weight, value, capacity - weight[i], i + 1, size) + value[i];
    }
    int exclude = ZeroOneKnapsackRECRR(weight, value, capacity, i + 1, size);
    dp[i][capacity] = max(include, exclude);
    return dp[i][capacity];
}

int ZeroOneKnapsackTabulatipn(int weight[], int value[], int capacity, int i, int size)
{
    vector<vector<int>> dp(size, vector<int>(capacity + 1, 0));
    // base case check crow
    // HINDI ME : mere last wale row me muze logic clahana tha , vo maine kar diya
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

    // 3 ulta liko code ko
    for (int cap = 0; cap <= capacity; cap++)
    {
        for (int index = size - 2; index >= 0; index--)
        {
            // copy paste 
            int include = 0;
            if (cap - weight[index] >= 0)
            {
                include = dp[index+1][cap - weight[index]]  + value[index];//(weight, value, capacity - weight[i], i + 1, size) + value[i];
            }
            int exclude = dp[index + 1][cap] ;    // (weight, value, capacity, i + 1, size);
            dp[index][cap] = max(include, exclude);
        }
    }
    return dp[0][capacity];
}

int main()
{
    // int weight[] = {4, 5, 1};
    // int value[] = {1, 2, 3};
    // int capacity = 4; // weight ke hissab se
    // int index = 0;
    // int size = 3;

    // Consider very simple example - Weights = {1, 2, 3} and Values ={6, 10, 12} and we have knapsack of capacity 5.
    int weight[] = {1, 2, 3};
    int value[] = {6, 10, 12};
    int capacity = 5; // weight ke hissab se
    int index = 0;
    int size = 3;

    int ans = ZeroOneKnapsackRECRR(weight, value, capacity, index, size);
    cout << "The Ans1 is " << ans << endl;

    // 2D dp // 2 parameters are changing

    // dp array os index and capacity //

    // ek baad dekh le ki dp array kaise banta hai aur kaise values initilize kiye
    vector<vector<int>> dp(size, vector<int>(capacity + 1, -1));
    int ans1 = ZeroOneKnapsackMEMO(weight, value, capacity, index, size, dp);
    cout << "The Ans2 is " << ans1 << endl;

    int ans3 = ZeroOneKnapsackTabulatipn(weight, value, capacity, index, size);
    cout << "the ans3 is " << ans3 << endl;

    return 0;
}