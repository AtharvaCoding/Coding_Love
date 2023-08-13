#include <iostream>
#include <string.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

void PrintDoublyLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int FindLengthOfDoublyLL(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}
void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL && tail == NULL)
    {
        Node *NewNode = new Node(data);
        head = NewNode;
        tail = NewNode;
        return;
    }
    Node *NewNode = new Node(data);
    tail->next = NewNode;
    NewNode->prev = tail;
    tail = NewNode;
}

void InsertAtHead(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        Node *NewNode = new Node(data);
        head = NewNode;
        tail = NewNode;
        return;
    }

    Node *NewNode = new Node(data);

    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode;
}

void InsetAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // If LL is empty
    if (head == NULL)
    {
        Node *NewNode = new Node(data);
        head = NewNode;
        tail = NewNode;
        return;
    }

    if (position == 1)
    {
        InsertAtHead(head, tail, data);
        return;
    }
    if (position > FindLengthOfDoublyLL(head))
    {
        InsertAtTail(head, tail, data);
        return;
    }
    // middle
    // 1 find currNode and PrevNode
    Node *PrevNode = head;
    int i = 1;
    while (i < position - 1)
    {
        PrevNode = PrevNode->next;
        i++;
    }

    // _____________
    // with curr node 
    // Node *CurrNode = PrevNode->next;

    // // 2 new Node
    // Node *NewNode = new Node(data);
    // // 3 4 5 6
    // PrevNode->next = NewNode;
    // NewNode->prev = PrevNode;
    // NewNode->next = CurrNode;
    // CurrNode->prev = NewNode;




    // _________w/o curr node 
    Node *NewNode = new Node(data);
    NewNode->next = PrevNode->next;
    PrevNode->next->prev = NewNode;
    PrevNode->next = NewNode;
    NewNode->prev = PrevNode;
    

}
int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    PrintDoublyLL(first);

    // Insert At head
    InsertAtHead(head, tail, 1);
    cout << endl;
    PrintDoublyLL(head);

    // Insert AT tail
    // head = NULL; tail = NULL;
    InsertAtTail(head, tail, 40);
    cout << endl;
    PrintDoublyLL(head);

    // INsert At position 
    InsetAtPosition(head , tail , 600 , 4);   // middle 
    // InsetAtPosition(head , tail , 25 , 1);   // 1st 
    // InsetAtPosition(head , tail , 25 , 6);    // last 
    cout <<endl;
    PrintDoublyLL(head);


    return 0;
}