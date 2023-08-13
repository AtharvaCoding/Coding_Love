#include <iostream>
#include <queue>
using namespace std;
void Interleave(queue<int> &Q){
    if (Q.empty())
    {
        return; 
    }
    int n = Q.size();
    int k = n/2;
    queue<int> Q2;  //cutu

    while (k--)
    {
        int elemnt = Q.front();
        Q.pop();

        Q2.push(elemnt);
    }
    // join 

    while (!Q2.empty())
    {
        Q.push(Q2.front());
        Q2.pop();
        Q.push(Q.front());
        Q.pop();
    }

    if (n&1)
    {
        int element = Q.front();
        Q.pop(); 
         
        Q.push(element);
    }
    

    


}
int main()
{
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.push(60);
    Q.push(70);
    Q.push(80);
    // Q.push(90);
    

    Interleave(Q);

    cout << "Printing the queue " << endl;

    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    return 0;
}