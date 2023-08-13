
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    void solve(vector<string>& ans , string output , int index , vector<string> &mapping, string &digits){
        //  base case 
        if(index >= digits.length()){
            // output.push_back(alpha[0][0]);
            ans.push_back(output);
            return;
        }

        //  ek case 
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for(int i = 0 ; i < value.length() ; i++){
            // char ch = value[i];
            output.push_back(value[i]);
            solve(ans , output , index+1 , mapping , digits);
            output.pop_back();
        }   
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans ;
        if(digits.length()==0)  
            return ans;
        string output = "";
        vector<string> mapping(10) ;
        int i = 0 ;
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        //  {"abc", "def", "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        //                         0     1       2      3        4      5       6         7    // +2
        
        solve(ans , output , i , mapping , digits);

        return ans;
    }
};