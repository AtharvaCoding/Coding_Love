#include <iostream>
#include <string.h>
using namespace std;
void printPermutation(string& s , int i){
    // base case 
    if (i>= s.length())
    {
        cout << s << " ";
    }

    for (int j = i; j < s.length(); j++)
    {
        // swap
        swap(s[i] , s[j]);
        // recurssion 
        printPermutation(s , i+1);

        // backtrack // to recreate the original input 
        swap(s[i], s[j]);
    }
    
    
}
int main(){
    string s = "abc";
    int i = 0 ;
    printPermutation(s , i);

return 0;
}   