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

void Print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node *Add(Node *&head1, Node *&head2)
{

    // reverse
    Node *temp1 = reverse(head1);
    Node *temp2 = reverse(head2);

    // addd
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int sum = carry + temp1->data + temp2->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node *NewNode = new Node(digit);

        // insert that node into ans

        if (ansHead == NULL)
        {
            // 1st node to insert
            ansHead = NewNode;
            ansTail = NewNode;
        }
        else
        {
            // 1 se jada nodes ho gyai hai
            ansTail->next = NewNode;
            ansTail = NewNode;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        int sum = carry + temp1->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node *NewNode = new Node(digit);

        // 1 se jada nodes ho gyai hai
        ansTail->next = NewNode;
        ansTail = NewNode;

        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        int sum = carry + temp2->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node *NewNode = new Node(digit);

        ansTail->next = NewNode;
        ansTail = NewNode;

        temp2 = temp2->next;
    }

    while (carry!=0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = carry / 10;
        Node *NewNode = new Node(digit);
        ansTail->next = NewNode;
        ansTail = NewNode;
    }

    return reverse(ansHead);
}
int main()
{
    Node *head1 = new Node(4);
    Node *second1 = new Node(2);
    Node *third1 = new Node(4);
    head1->next = second1;
    second1->next = third1;

    Node *head2 = new Node(7);
    Node *second2 = new Node(9);
    Node *third2 = new Node(1);
    head2->next = second2;
    second2->next = third2;

    // Print(head1);
    Node *head3 = Add(head1, head2);
    Print(head3);

    return 0;
}