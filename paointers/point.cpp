#include <iostream>
#include <string.h>
using namespace std;
int* solve(){
    int a = 5;
    int* ans = &a;
    return ans;
}
int main(){
    cout << " Solve function call " << solve() << endl;

return 0;
}