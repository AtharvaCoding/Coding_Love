#include <iostream>
#include <string.h>
using namespace std;
void PrintDigits(int& n){
    // base case
    if(n ==0)
        return;


    // baki recurssion
    int newnum = n /10;
    PrintDigits(newnum);
    // ek case 
    int digit = n%10;
    cout<<digit<<" ";
    
    
}

int main(){
    int n  = 342 ;

    PrintDigits(n);
return 0;
}   