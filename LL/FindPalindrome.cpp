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
int FindLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
}
bool FindPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // slow is mid ;
    Node *curr = slow->next;
    Node *prev = NULL;
    Node *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    // prev is new head;
    slow->next = prev;
    // compare the prev and head;

    Node *temp1 = head;
    Node *temp2 = prev;

    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(30);
    Node *fifth = new Node(20);
    Node *sixth = new Node(10);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(20);
    // Node *fifth = new Node(10);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    if (FindPalindrome(first))
    {
        cout << "the LL is Palindromic" << endl;
    }
    else
    {
        cout << "The LL is not Palindromic" << endl;
    }

    return 0;
}