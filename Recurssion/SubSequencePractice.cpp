#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
void solve(string s , int index , string output ,vector<string> &ans ){
    // base case 
    if (index >= s.length())
    {
        ans.push_back(output);
        return;
    }

    // exclude 
    solve(s , index +1 , output , ans);
    // include 
    output.push_back(s[index]);
    solve(s, index +1 , output , ans);
}
int main(){
    string s = "abc";
    // Print all the subsequence of the same 
    vector<string> ans ;
    string ouptut ="";
    int index = 0;
    solve(s , index , ouptut , ans);

    int i = 0 ;
    for(auto i : ans){
        cout << i << endl;
    }


return 0;
}   