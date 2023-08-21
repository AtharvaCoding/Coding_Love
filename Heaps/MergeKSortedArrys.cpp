#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Info{
public:
    int data;
    int row ; 
    int col ;

    Info(int data  , int row , int col){
        this->data = data;
        this->col = col ;
        this->row = row;
    }
};
class compare{
public:
    bool operator()(Info* a , Info* b){
        return a->data > b->data;
    }
};
vector<int> MergeKSortedArrys(int arr[][4] , int k , int n){
    priority_queue<Info* , vector<Info*> , compare > minheap;

    // hr array ka 1st element inset crow 
    for (int i = 0; i < k; i++)
    {
        Info* element = new Info(arr[0][i] , i , 0);
        minheap.push(element);
    }

    vector<int> ans;

    while (!minheap.empty())
    {
        Info* topelement = minheap.top();
        int topdata = topelement->data;
        int toprow = topelement->row;
        int topcol = topelement->col;
        ans.push_back(topdata);
        minheap.pop();

        // aage wale elements ko push crow min heap me 
        if (topcol+1 < n)
        {
            Info* NewInfo = new Info(arr[toprow][topcol+1] , toprow, topcol+1);
            minheap.push(NewInfo);
        }
        
    }

    return ans;

    
}
int main()
{
    int arr[][4] { {1,3,5,7} ,
                   {2,4,6,8} ,
                   {0,9,10,11}
                 };
    int k = 3;
    int n = 4;

    vector<int> ans = MergeKSortedArrys(arr , k , n);
    cout << "Printing the ans" << endl;
    for(int i = 0 ; i < k ; i++){
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}