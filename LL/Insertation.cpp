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
void PrintLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertAtHead(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        Node *NewNode = new Node(data);
        head = NewNode;
        tail = NewNode;
    }

    // 1 new node
    Node *NewNode = new Node(data);
    // 2
    NewNode->next = head;
    // 3
    head = NewNode;
}
void INsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *NewNode = new Node();
        head = NewNode;
        tail = NewNode;
    }
    // 1
    Node *NewNode = new Node(data);
    // 2
    tail->next = NewNode;
    // 3
    tail = NewNode;
}
int FindLength(Node *&head)
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
void INsertAtPosition(Node *&head, Node *&tail, int data, int position)
{

    if (head == NULL)
    {
        Node *NewNode = new Node();
        head = NewNode;
        tail = NewNode;
    }

    // 1 find the position
    if (position == 0)
    {
        InsertAtHead(head, tail, data);
        return;
    }
    int length = FindLength(head);
    if (position == length)
    {
        INsertAtTail(head, tail, data);
    }

    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    } // i = 3
    Node *curr = prev->next;

    // 2 Create the node

    Node *NewNode = new Node(data);

    // 3  NN->next = curr

    NewNode->next = curr;

    // 4 prev->next  = NewNode

    prev->next = NewNode;
}

void DeleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "cant delete the node , LL is Empty" << endl;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    if (position == FindLength(head))
    {
        int i  = 1;
        Node *prev = head;
        while (i < position)
        {
            prev = prev->next;
            i++;
        } // i = 3
        Node *curr = prev->next;

        prev->next = NULL;
        tail = prev ; 
        Node* temp  = curr ;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // PrintLL(head);

    InsertAtHead(head, tail, 90);
    InsertAtHead(head, tail, 70);
    InsertAtHead(head, tail, 50);
    InsertAtHead(head, tail, 40);
    INsertAtTail(head, tail, 30);
    INsertAtTail(head, tail, 20);
    INsertAtTail(head, tail, 10);

    PrintLL(head);

    INsertAtPosition(head, tail, 5, 8);
    cout << endl
         << "After inserting the 5 at 3rd position" << endl;

    PrintLL(head);
    cout << endl
         << FindLength(head) << endl;

    DeleteAtPosition(head, tail, 10);
    cout << endl;
    PrintLL(head);

    return 0;
}