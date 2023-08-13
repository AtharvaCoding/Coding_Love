#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *MakeBST(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = MakeBST(root->left, data);
    }
    else
    {
        root->right = MakeBST(root->right, data);
    }

    return root;
}
void TakeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = MakeBST(root, data);
        cin >> data;
    }
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        // 1/
        Node *temp = q.front();
        // 2
        q.pop();
        // 3
        cout << temp->data << " ";
        // 4
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
void ConvertIntoDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }

    ConvertIntoDLL(root->right, head);

    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    ConvertIntoDLL(root->left, head);
}

void PrintDLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}
Node* ConvertDLLintoBST(Node* &head , int size){
    if (size<=0 || head == NULL)
    {
        return NULL;
    }

    Node* LeftSubTree = ConvertDLLintoBST(head , size -(size / 2) -1  );

    Node* root = head;
    head ->left = LeftSubTree;
    head = head->right;

    root->right = ConvertDLLintoBST(head , size/2);
    return root;
    
}
void inorderTraversal(Node* root1){
    if (root1 == NULL)
    {
        return;
    }

    inorderTraversal(root1->left);
    cout << root1->data << " ";
    inorderTraversal(root1->right);
    
}
int main()
{
    Node *root = NULL;
    cout << "enter the data for the tree" << endl;
    // 10
    // 20
    // 5
    // 11
    // 17
    // 2
    // 4
    // 8
    // 6
    // 25
    // 15
    // -1

    TakeInput(root);
    cout << "Printing the Level Order Traversal" << endl;
    // cout << root << endl;
    LevelOrderTraversal(root);
    cout << endl << endl ; 
    Node *head = NULL;
    ConvertIntoDLL(root, head);
    cout << "Printing the LL" << endl;
    PrintDLL(head);
    Node* root1 = NULL;

    cout <<endl<< "Printing the Level Order Traversal of root1 " << endl;
    root1 = ConvertDLLintoBST(head , 11);
    LevelOrderTraversal(root1);
    cout <<endl<< "Printing the Inorder traversal of the root 1 " << endl;
    inorderTraversal(root1);
    return 0;
}