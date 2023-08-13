#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);

    Q.pop();
    cout << "The Front element is: " << Q.front() << endl;

    if(Q.empty()){
        cout << "The queue is empty " << endl;
    }
    else{
        cout << "The queue is not empty " << endl;
    }

    // Q
    return 0;
}