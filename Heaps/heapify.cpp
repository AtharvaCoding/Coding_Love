#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
void heapify(int num[], int n, int i)
{
    int index = i;
    int Lchild = i * 2;
    int Rchild = i * 2 + 1;

    int largest = i;
    if (Lchild < n && num[Lchild] > num[largest])
    {
        largest = Lchild;
    }
    if (Rchild < n && num[Rchild] > num[largest])
    {
        largest = Rchild;
    }

    if (index != largest)
    {
        // toh iska matlab jo bhi value hai index pe vo sahi jagah par nahi hai
        swap(num[index], num[largest]);
        index = largest;
        heapify(num, n, index);
    }
}
// rough paper , pointers , sorting , heaps 
// basically heapify matlab ye hai ki ek element hai jo function me jayenga aur usko uski sahi jagah pe dalna hai
// Heapify Practice 
void HeapifyPractice(int arr[] , int n , int i){
    int index = i ;
    int LChild = i*2;
    int RChild = i*2 + 1 ;
    int largest = i;

    if (LChild < n && arr[LChild] > arr[largest])
    {
        largest  = LChild;
    }
    if (RChild < n && arr[RChild] > arr[largest])
    {
        largest = RChild;
    }

    // largerst is the lasgest between the node , L child , R child 
    if (largest != index)
    {
        // iska matlab node apni sahi jagh pe nahi hai 
        swap(arr[largest] , arr[index]);
        heapify(arr , n , largest);
    }
    
    
    
}
void deleteNode(int num[], int n){
    // root node ko ukse last wale node ke equal car do aur last wali node ko delete crow 
    num[1] = num[n-1];
    n--;
    // last wali node ko ukse sahi position pe daal do
    heapify(num , n-1 , 1);

}
int main()
{
    int num[] = {-1, 12, 50, 60, 30, 40, 52};
    int n = 7;
    int i = 1;

    // heapify(num , n , i);
    HeapifyPractice(num , n , i);
    cout <<endl <<"Printing the heap" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    deleteNode(num , n);
    cout <<endl <<"Printing the heap after deleting " << endl;
    for (int i = 0; i < n - 1 ; i++)
    {
        cout << num[i] << " ";
    }

    
    return 0;
}