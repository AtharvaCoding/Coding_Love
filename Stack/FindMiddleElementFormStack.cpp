#include <iostream>
#include <stack>
using namespace std;
int FindMiddleElement(stack<int> &st , int totalsize , int size){
    // base case 

    if(totalsize/2 + 1 == size){
        return st.top();
    }


    int temp = st.top();
    st.pop();
    return FindMiddleElement(st , totalsize , size -1);
    st.push(temp);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);


    int ans = FindMiddleElement(st , 7 , 7);
    cout << "the middle element is " << ans;
    return 0;
}