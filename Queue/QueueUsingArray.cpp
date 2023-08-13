#include <iostream>
// #include <queue>
// #include <bits/stdc++.h>

using namespace std;
class Queue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int size)
    {
        this->size = size;
        front = 0;
        rear = 0;
        arr = new int[size];
    }

    void Push(int data)
    {
        if (rear == size)
        {
            cout << "Can't add data in queue , it is full" << endl;
        }
        arr[rear] = data;
        rear++;
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "Can't pop element from queue , it is empty " << endl;
        }
        arr[front] = -1;
        front++;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
    }

    int GetFront()
    {
        if (front == rear)
        {
            cout << "The queue is empty " << endl;
            return -1;
        }

        return arr[front];
    }

    bool IsEmpty()
    {
        if (front == rear)
        {

            return true;
        }
        return false;
    }
    int Getsize()
    {
        return rear - front;
    }
};
int main()
{
    Queue q(10);
    q.Push(10);
    q.Push(20);
    q.Push(30);
    q.Push(40);

    q.pop();
    // q.pop();
    // q.pop();
    // q.pop();

    cout << "The size of queue is :" << q.Getsize() << endl;

    if (q.IsEmpty())
    {
        cout << "the queue is empty " << endl;
    }
    else
    {
        cout << "The queue is not empty " << endl;
    }


    cout << "Printng the queue " << endl;

    while (!q.IsEmpty())
    {
        cout << q.GetFront() << " ";
        q.pop();
    }
    
    return 0;
}