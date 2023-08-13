#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
void SubSequence(string str, string output, int i)
{
    // base case

    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // exclude
    SubSequence(str, output, i + 1);

    // include
    output.push_back(str[i]);
    SubSequence(str, output, i + 1);
    
}
int main()
{
    
    string str = "bbbab";
    string output = "";

    int i = 0;
    SubSequence(str, output, i);

    return 0;
}