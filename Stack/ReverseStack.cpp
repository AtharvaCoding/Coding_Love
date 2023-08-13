#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &st , int &target){
    // if stack is empty 
    if (st.empty())
    {
        st.push(target);
        return;
    }

    int top_ele = st.top();
    st.pop();
    solve(st , target);
    st.push(top_ele);
    
}
void reverseStack(stack<int> &st){
    // base case 
    if (st.empty())
    {
        return;
    }
    

    int top_ele = st.top();
    st.pop();

    reverseStack(st);

    solve(st , top_ele);

}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStack(st);

    cout << "printing stack" << endl;

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}