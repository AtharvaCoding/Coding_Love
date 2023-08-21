#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int> a1(a.begin() , a.end());
        priority_queue<int> b1(b.begin() , b.end());
        
        for(int i = 0 ; i < m ; i++){
            a1.push(b1.top());
            b1.pop();
        }
        
        vector<int> ans;
        for(int i = 0 ; i < (n+m) ; i++){
            ans.push_back(a1.top());
            a1.pop();
        }
        return ans;
    }
};

int main(){


return 0;
}