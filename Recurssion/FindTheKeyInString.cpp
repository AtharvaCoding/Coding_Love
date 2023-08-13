#include <iostream>
#include <string.h>
using namespace std;
bool FindTheKey(string s ,int i , int n, char key){   
    // base case 
    if(i >= n){
        return false;
    }
    // 1 case 
    if (s[i] == key)
    {
        return true;
    }
    // baki recurssion
    return FindTheKey(s, i+1 ,n , key);
    
}
int main()
{
    string s = "Atharva";
    char key = 'a';
    int i = 0;
    int n = 7;
    if (FindTheKey(s,i,n,key))
    {
        cout<<"The key : "<< key << " found!"<<endl;
    }
    else
    {
        cout<<"The key : "<< key << " not found!"<<endl;
    }
    return 0;
}