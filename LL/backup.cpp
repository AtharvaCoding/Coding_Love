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


Node* Reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
    
}
bool FindPalindrome(Node * &head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // slow is mid ;

    // step 2 : reverse LL from next of mid

    Node* reverse = Reverse(slow->next);

    slow->next = reverse;

    // step 3 : compare
    Node* temp1 = head;
    Node* temp2 = reverse;
    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
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
    Node *sixth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    if (FindPalindrome(first))
    {
        cout << "the LL is Palindromic" << endl;
    }
    else{
        cout << "Linked List is not palindromic" <<endl;
    }

    return 0;
}