#include <iostream>
#include <queue>
#include <deque>
using namespace std;
void FindnegativeInteger(int arr[], int k, int size)
{
    // process 1st k element
    queue<int> q;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    // remaning element ko process kiya
    for (int i = k; i < size; i++)
    {
        // answer ko print kiya

        if (q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << arr[q.front()] << " ";
        }

        // out of window ko nikalo

        while ((!q.empty()) && (i - q.front() >= k))
        {
            q.pop();
        }

        // new element ko insert karo

        if (arr[i] < 0)
        {
            q.push(i);
        }
    }
    // ans print karo for last window 
    if (q.empty())
    {
        cout << 0 << " ";
    }
    else
    {
        cout << arr[q.front()] << " ";
    }
}
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    int size = 8;

    FindnegativeInteger(arr, k, size);

    return 0;
}