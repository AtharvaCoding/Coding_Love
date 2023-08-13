#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void ReverseQueue(queue<int> &Q)
{

    stack<int> S;

    while (!Q.empty())
    {
        int element = Q.front();
        Q.pop();

        S.push(element);
    }

    while (!S.empty())
    {
        int element = S.top();
        S.pop();

        Q.push(element);
    }
}

void ReverseAQUeueUsingRecurssion(queue<int> &Q)
{
    // base case
    if (Q.empty())
    {
        // cout << "The queue is empty" << endl;
        return;
    }

    if (Q.size() == 1)
    {
        return;
    }

    // queue has more than 1 elements
    int element = Q.front();
    Q.pop();

    ReverseAQUeueUsingRecurssion(Q);

    Q.push(element);
}
void ReverseFirstKElementsOfQueue(queue<int> &Q, int k)
{
    if (Q.empty())
    {
        cout << "The Queue is empty " << endl;
        return;
    }

    int remaining_element = Q.size() - k;
    stack<int> S;
    while (k--)
    {
        int element = Q.front();
        Q.pop();

        S.push(element);
    }

    while (!S.empty())
    {
        // Q.push()
        int element = S.top();
        S.pop();

        Q.push(element);
    }
    while (remaining_element--)
    {
        int element = Q.front();
        Q.pop();

        Q.push(element);
    }
}
int main()
{
    queue<int> Q;
    // Q.push(10);
    // Q.push(20);
    // Q.push(30);
    // Q.push(40);
    // Q.push(50);
    // /// 10 20 30 40 50
    // ReverseAQUeueUsingRecurssion(Q);
    // /// 50 40 30 20 10

    // cout << "Printing the queue " << endl;

    // while (!Q.empty())
    // {
    //     cout << Q.front() << " ";
    //     Q.pop();
    // }

    Q.push(3);
    Q.push(6);
    Q.push(9);
    Q.push(12);
    Q.push(15);
    ReverseFirstKElementsOfQueue(Q, 0);

    cout << endl;
    cout << "Printing the queue " << endl;

    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;

    return 0;
}