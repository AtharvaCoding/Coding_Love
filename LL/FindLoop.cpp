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

bool FindLLCycle(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

Node *FindTheCycleNode(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            break;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        cout << "LL cycle not present" << endl;
        return NULL;
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;

    // return 0;
}

Node* RemoveCycle(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            break;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        cout << "LL cycle is not present" << endl;
        return NULL;
    }

    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;

    return slow;
}
void PrintLL(Node *head)
{
    int i = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fourth;

    // PrintLL(first);

    if (FindLLCycle(first))
    {
        cout << "LL cycle is present " << endl;
    }
    else
    {
        cout << "LL cycle is not present " << endl;
    }

    cout << "The cycle Node of LL is " << FindTheCycleNode(first)->data << endl;

    RemoveCycle(first);
    PrintLL(first);
    cout <<endl;
    if (FindLLCycle(first))
    {
        cout << "LL cycle is present " << endl;
    }
    else
    {
        cout << "LL cycle is not present " << endl;
    }

    return 0;
}