#include <iostream>
#include <stack>
using namespace std;
void InsertSorted(stack<int> &st , int target){
    // base case 
    if (st.empty()) 
    {
        st.push(target);
        return;
    }
    if (st.top() >= target)
    {
        st.push(target);
        return;
    }

    //  vahi 4 setp 
    int element = st.top();
    st.pop();
    InsertSorted(st ,target);
    st.push(element);
    
    
}
void SortAStack(stack<int> &st){
    // base case 
    if (st.empty())
    {
        return;
    }
    

    int top_ka_element = st.top();
    st.pop();
    SortAStack(st);
    InsertSorted(st , top_ka_element);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(2);
    st.push(8);
    st.push(6);
    st.push(4);
    // int target = 5;
    // InsertSorted(st , target);
    SortAStack(st);
    cout << "Prinnting the stack " << endl;

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}