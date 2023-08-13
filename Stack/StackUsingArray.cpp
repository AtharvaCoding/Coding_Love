#include <iostream>
// #include <stack>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *arr;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void Push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    int GetTop()
    {
        if (top == -1)
        {
            cout <<"stack is empty"<<endl;
            return -1;
        }
        else{
            // cout << arr[top] << endl;
            return arr[top];
        }
        
    }

    int GetSize()
    {
        return top + 1;
        
    }

    bool IsEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
};
int main()
{
    Stack* st = new Stack(10);
    st->Push(10);
    st->Push(20);
    st->Push(30);
    st->Push(40);
    st->Push(50);
    // 10 20 30 40 50 

    st->pop();
    st->pop();

    // 10 20 30

    cout << "The size of stack is " << st->GetSize()<<endl; // 3

    cout << "the top element of stack is : " <<st->GetTop() << endl;

    if (st->IsEmpty())
    {
        cout << "The stack is empty" <<endl;
    }
    else{
        cout << "The stack is not empty " << endl;

    }
    



    return 0;
}