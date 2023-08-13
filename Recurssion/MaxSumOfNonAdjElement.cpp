// #include <iostream>
// #include <string.h>
// #include <vector>
// using namespace std;
// void MaxSum(vector<int> &arr, int i, int sum, int &maxi)
// {
//     // base case
//     if (i >= arr.size())
//     {
//         // return INT_MIN;
//         maxi = max(sum, maxi);
//         return;
//     }

//     // include  
//     return MaxSum(arr, i + 2, sum + arr[i], maxi);
//     // exclude
//     return MaxSum(arr, i + 1, sum, maxi);
// }

// int main()
// {
//     vector<int> arr = {2, 1, 4, 9};
//     int i = 0;
//     int sum = 0;
//     int maxi = INT_MIN;

//     MaxSum(arr, i, sum, maxi);
//     cout << maxi << endl;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void MaxSum(vector<int> &arr, int i, int sum, int &maxi) {
    // base case
    if (i >= arr.size()) {
        // update the maximum sum
        maxi = max(sum, maxi);
        return;
    }

    // include the current element
    MaxSum(arr, i + 2, sum + arr[i], maxi);
    
    // exclude the current element
    MaxSum(arr, i + 1, sum, maxi);
}

int main() {
    vector<int> arr = {2, 1, 4, 9};
    int i = 0;
    int sum = 0;
    int maxi = INT_MIN;

    MaxSum(arr, i, sum, maxi);
    cout << maxi << endl;

    return 0;
}
