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
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *ReverseALL(Node *prev, Node *curr)
{
    // base case
    if (curr == NULL)
    {
        return prev;
    }
    // 1 case
    Node *Next = curr->next;
    curr->next = prev;
    // baki recurssion
    return ReverseALL(curr, Next);
}

Node *REverse(Node *prev, Node *curr)
{
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
int FindLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
Node *ReverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    int len = FindLength(head);
    if (k > len)
    {

        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
    {
        Node* recurssionAns = ReverseKNodes(forward , 3);
        head->next = recurssionAns;
    }

    return prev;
}
int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourt = new Node(40);
    Node *fifth = new Node(50);
    Node *sisth = new Node(60);

    first->next = second;
    second->next = third;
    third->next = fourt;
    fourt->next = fifth;
    fifth->next = sisth;
    // sisth->next = NULL;

    Node *head = first;

    // PrintLL(head);

    // Node* prev = NULL ;
    // Node* curr = head;
    // // head = ReverseALL(prev , curr);
    // // cout << endl;
    // // PrintLL(head);

    // head = REverse(prev , curr);
    // cout << endl;
    // PrintLL(head);

    cout << endl;
    PrintLL(head);
    cout << endl;
    // cout <<     FindLength(head);
    head = ReverseKNodes(head, 2);
    cout << endl;
    PrintLL(head);

    return 0;
}