#include <iostream>
#include <vector>
using namespace std;
int FristOccourenc(vector<int> arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6, 7};
    int key;
    cout << "Please enter the key : " << endl;
    cin >> key;

    cout << "the 1st occourence of the given key in the arr is : " << FristOccourenc(arr, key);

    return 0;
}