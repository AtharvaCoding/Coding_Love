#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> MergeKSortedArraysBF(int arr[][4] , int k , int n){
    priority_queue<int , vector<int> , greater<int>> MinHeap;
    for (int i = 0 ; i < k ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MinHeap.push(arr[i][j]);
        }
    }

    int numberOfelements = n*k;
    vector<int> ans;
    for (int i = 0; i < n*k; i++)
    {
        ans.push_back(MinHeap.top());
        MinHeap.pop();
    }

    return ans;
    
    
}
int main()
{
    int arr[][4] { {1,3,5,7} , {2,4,6,8} , {0,9,10,11}};
    int k = 3 ; 
    int n = 4 ; 
    cout << "Printing the oringinal elements " << endl;
    for (int i = 0 ; i < k ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout<< endl;

    vector<int> ans = MergeKSortedArraysBF(arr , k  ,n);
    cout << "Printing the sorted elements " << endl;
    for(auto i : ans){
        cout << i << " ";
    }
    cout<< endl;



    return 0;
}