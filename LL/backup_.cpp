#include <iostream>
#include <string.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        this->data = -1;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void Print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl; // Add a newline at the end to separate output results.
}

Node* reverse(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL; // Set forward to NULL initially.

    while (curr != NULL) {
        forward = curr->next; // Fix the assignment to 'forward'.
        curr->next = prev;
        prev = curr;
        curr = forward; // Fix the variable name in the loop update.
    }
    return prev;
}

Node* Add(Node*& head1, Node*& head2) {

    // reverse
    Node* temp1 = reverse(head1);
    Node* temp2 = reverse(head2);

    // addd
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL) { // Change '&&' to '||' to handle different lengths.

        int sum = carry;
        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        Node* NewNode = new Node(digit);

        // insert that node into ans
        if (ansHead == NULL) {
            ansHead = NewNode;
            ansTail = NewNode;
        }
        else {
            ansTail->next = NewNode;
            ansTail = NewNode;
        }
    }

    // Handle any remaining carry
    while (carry > 0) {
        int digit = carry % 10;
        carry = carry / 10;
        Node* NewNode = new Node(digit);
        ansTail->next = NewNode;
        ansTail = NewNode;
    }

    return reverse(ansHead); // Reverse the final result before returning.
}

int main() {
    Node* head1 = new Node(7);
    Node* second1 = new Node(9); // Change '2' to '9'.
    Node* third1 = new Node(1);  // Change '4' to '9'.
    head1->next = second1;
    second1->next = third1;

    Node* head2 = new Node(4);
    Node* second2 = new Node(2);
    Node* third2 = new Node(4);
    head2->next = second2;
    second2->next = third2;

    Node* head3 = Add(head1, head2);
    Print(head3);

    return 0;
}
