#include <iostream>
#include <vector>
using namespace std;

long long SolveMemo(int n, int k, vector<long long>& dp) {
    if (n == 1)
        return k;

    if (n == 2)
        return k * k;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (SolveMemo(n - 1, k, dp) + SolveMemo(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

long long countWays(int n, int k) {
    vector<long long> dp(n + 1, -1);
    long long ans = SolveMemo(n, k, dp);
    return ans;
}

int main() {
    int n = 4;
    int k = 3;
    long long ans = countWays(n, k);
    cout << ans << endl;
    return 0;
}
