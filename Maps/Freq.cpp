#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    // string str = "AtharvaIsAGoodBoiHaiThaAurRahenga";
    string str = "AAAAAAAAAA";
    unordered_map <char , int> freq;
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i]] ++;
    }

    for(auto i : freq){
        cout << i.first << "-" << i.second << endl;
    }
    
    return 0;
}   