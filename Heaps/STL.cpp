#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;  // max heap 
    pq.push(9);
    pq.push(7);
    pq.push(5);
    pq.push(10);
    pq.push(4);
    pq.push(1);
    pq.push(11);
    cout << "The Top element is Max Element of the Max Heap" << endl;
    cout << "Printing the Top Element : " << pq.top() << endl;
    pq.pop();
    cout << "Printing the Top Element : " << pq.top() << endl;
    pq.pop();
    cout << "Printing the Top Element : " << pq.top() << endl;
    pq.pop();
    cout << "Printing the Top Element : " << pq.top() << endl;
    pq.pop();

    cout << "Size : " << pq.size() << endl;

    if (pq.empty()) 
    {
        cout << "Priority queue is empty " << endl;
    }
    else{
        cout << "Priority queue is not empty " << endl;
    }
    


    cout << endl << endl << endl << endl ;
    cout <<"MIN HEAP" << endl;
    priority_queue<int , vector<int> , greater<int>> pq1;
    pq1.push(9);
    pq1.push(7);
    pq1.push(5);
    pq1.push(10);
    pq1.push(4);
    pq1.push(1);
    pq1.push(11);
    cout << "The Top element is Min Element of the Min Heap" << endl;
    cout << "Printing the Top Element : " << pq1.top() << endl;
    pq1.pop();
    cout << "Printing the Top Element : " << pq1.top() << endl;
    pq1.pop();
    cout << "Printing the Top Element : " << pq1.top() << endl;
    pq1.pop();
    cout << "Printing the Top Element : " << pq1.top() << endl;
    pq1.pop();

    cout << "Size : " << pq1.size() << endl;

    if (pq1.empty()) 
    {
        cout << "Priority queue is empty " << endl;
    }
    else{
        cout << "Priority queue is not empty " << endl;
    }
    



    return 0;
}