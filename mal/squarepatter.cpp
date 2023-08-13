#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
void SquarePatterPrint(int n){
    int count = 1 ,z = 1;
    int line = 1;
    vector<vector<string>> v ;
    vector<string> l;
    for (int i = 0; i < n; i++)
    {
        l.clear();
        for (int j = 0; j < line; j++)
        {
            cout << count;
            // string x = to_string(count);
            l.push_back(x);
            count ++;
            if (line >z+1)
            {
                z++;
                l.push_back("*");
                cout<<"*";
            }
            

        }
        v.push_back(l);
        z=0;
        cout<<endl;
        line++;
    }


    
}
int main(){

return 0;
}