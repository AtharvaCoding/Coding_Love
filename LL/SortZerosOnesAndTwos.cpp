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
Node* RemoveMinusOneFromLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL)
    {
        /* code */
        if (curr->data == -1)
        {
            Node* temp = curr;
            curr = curr->next;
            if(prev!=NULL){prev->next = curr;}
            temp->next = NULL;
            delete temp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
    
    
}
Node *Sort(Node *&head)
{
    // dummy heads ;
    // 0
    Node *ZeroHead = new Node(-1);
    Node *ZeroTail = ZeroHead;

    // 1
    Node *OneHead = new Node(-1);
    Node *OneTail = OneHead;

    // 2
    Node *TwoHead = new Node(-1);
    Node *TwoTail = TwoHead;

    // Compare
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            ZeroTail->next = temp;
            ZeroTail = temp;
        }

        else if (curr->data == 1)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            OneTail->next = temp;
            OneTail = temp;
        }

        else if (curr->data == 2)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            TwoTail->next = temp;
            TwoTail = temp;
        }

        curr = curr->next;
    }



    // Join karo 

    ZeroTail->next = OneHead;
    OneTail->next = TwoHead;

    head = RemoveMinusOneFromLL(ZeroHead->next);
    return head;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(0);
    Node *fourth = new Node(0);
    Node *fifth = new Node(0);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Sort(first);
    Print(first);

    return 0;
}



// backup

// #include <iostream>
// #include <string.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node() {
//         this->data = -1;
//         this->next = NULL;
//     }
//     Node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void Print(Node* head) {
//     Node* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }

// Node* RemoveMinusOneFromLL(Node* head) {
//     Node* curr = head;
//     Node* prev = NULL;
//     while (curr != NULL) {
//         if (curr->data == -1) {
//             Node* temp = curr;
//             curr = curr->next;
//             if (prev != NULL) {
//                 prev->next = curr;
//             }
//             temp->next = NULL;
//             delete temp;
//         }
//         else {
//             prev = curr;
//             curr = curr->next;
//         }
//     }
//     return head;
// }

// Node* Sort(Node*& head) {
//     // dummy heads ;
//     // 0
//     Node* ZeroHead = new Node(-1);
//     Node* ZeroTail = ZeroHead;

//     // 1
//     Node* OneHead = new Node(-1);
//     Node* OneTail = OneHead;

//     // 2
//     Node* TwoHead = new Node(-1);
//     Node* TwoTail = TwoHead;

//     // Compare
//     Node* curr = head;

//     while (curr != NULL) {
//         if (curr->data == 0) {
//             Node* temp = curr;
//             curr = curr->next;
//             temp->next = NULL;

//             ZeroTail->next = temp;
//             ZeroTail = temp;
//         }
//         else if (curr->data == 1) {
//             Node* temp = curr;
//             curr = curr->next;
//             temp->next = NULL;

//             OneTail->next = temp;
//             OneTail = temp;
//         }
//         else if (curr->data == 2) {
//             Node* temp = curr;
//             curr = curr->next;
//             temp->next = NULL;

//             TwoTail->next = temp;
//             TwoTail = temp;
//         }
//         else {
//             curr = curr->next;
//         }
//     }

//     // Join karo 
//     ZeroTail->next = OneHead;
//     OneTail->next = TwoHead;

//     head = RemoveMinusOneFromLL(ZeroHead->next);
//     return head;
// }

// int main() {
//     Node* first = new Node(2);
//     Node* second = new Node(2);
//     Node* third = new Node(2);
//     Node* fourth = new Node(2);
//     Node* fifth = new Node(0);

//     first->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;

//     Sort(first);
//     Print(first);

//     return 0;
// }
