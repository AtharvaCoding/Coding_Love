#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // string str = "aabc";
    string str = "aac";

    int arr[26] = {0};

    queue<char> q;
    string ans = "";

    for (int i = 0; i < str.length(); i++)

    {
        char ch = str[i];
        arr[ch - 'a']++;

        q.push(ch);


        while (!q.empty())
        {
            if (arr[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                // cout << ch << " ";
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    cout << ans;

    return 0;
}