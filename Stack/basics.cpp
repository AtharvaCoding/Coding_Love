#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.pop();
    st.pop();

    cout << "the top most element is " << st.top() << endl;

    if (st.empty())
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The stack is not empty " << endl;
    }
    return 0;
}