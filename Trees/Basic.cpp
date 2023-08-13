#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Node(int data)
    // {
    //     this->data = data;
    //     left = NULL;
    //     right = NULL;
    // }
    Node(int data) : data(data) , left(NULL) , right(NULL) {};
};
Node *BuildTree()
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    // base condition
    if (data == -1)
    {
        return NULL;
    }

    // A B C
    Node *root = new Node(data);

    cout << "enter the left part of " << data << " : " << endl;
    root->left = BuildTree();

    cout << "enter the right part of " << data << " : " << endl;
    root->right = BuildTree();

    return root;
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

void InOrderTraversal(Node* root){
    if (root == NULL)
    {
        return;
    }
    // L N R
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
    
}

void PreOrderTraversal(Node *root){
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);

    
}
void PostOrderTraversal(Node * root){
    if (root == NULL)
    {
        return; 
    }
    
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    root = BuildTree();


    cout << "Printing level by level " <<endl;
    LevelOrderTraversal(root);
    cout << endl;


    cout << "Inorder Traversal is : " << endl;
    InOrderTraversal(root); //LNR
    cout << endl;


    cout << "PreOrder Traversal : " << endl;
    PreOrderTraversal(root);
    cout << endl;

 
    cout << "PostOrder Traversal : " << endl;
    PostOrderTraversal(root);
    cout << endl;


    return 0;
}