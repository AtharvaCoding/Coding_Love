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
Node* BSTUsingInorder(int Inorder[] , int s , int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = s + (e-s)/2;
    Node* temp = new Node(Inorder[mid]);
    temp->left = BSTUsingInorder(Inorder , s , mid-1);
    temp->right = BSTUsingInorder(Inorder , mid + 1 , e);

    return temp;
    
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
void InorderTraversal(Node* root){
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
    
}

int main()
{
    int Inorder[] = {10,20,30,40,50,60,70,80};
    int s = 0 ;
    int e = 7;
    Node* root = BSTUsingInorder(Inorder , s, e);
    cout << endl << "Printing the tree " << endl;
    LevelOrderTraversal(root);
    cout << endl << "the Inorder Traversal of tree is : " << endl ;
    InorderTraversal(root);
    return 0;
}