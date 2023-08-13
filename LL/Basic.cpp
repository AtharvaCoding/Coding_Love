#include <iostream>
#include <string.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = -1;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void Print(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; /// con't do temp ++
    }
    
}
void InsertAtHead(Node* &head , int data){  /// by refrence // update to the same LL
    // 1 nayaa node banao 
    Node* NewNode = new Node(data);
    // 2 node ke next ko point karao head pe 
    NewNode->next = head;
    // 3 head ko update karo
    head = NewNode;
}

void InsertAtTail(Node* &tail , int data){
    Node* NewNode = new Node(data);
    
    tail->next = NewNode;

    tail = NewNode;
}

int main()
{
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;


    Node* head = new Node(10);
    InsertAtHead(head , 20);
    InsertAtHead(head , 30);
    InsertAtHead(head , 40);
    InsertAtHead(head , 50);
    InsertAtHead(head , 60);


    Print(head);
    // 60,50,40,30,20,10   

    // I want to insert at tail 
    cout << endl<<"______________________________________________" <<endl;
    Node* temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    InsertAtTail(temp , 5);
    InsertAtTail(temp , 4);
    InsertAtTail(temp , 3);
    InsertAtTail(temp , 2);
    InsertAtTail(temp , 1);


    Print(head);

    return 0;
} 