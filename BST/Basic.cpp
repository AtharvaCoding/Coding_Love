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
        root->left = MakeBST(root->left , data);
    }
    else{
        root->right = MakeBST(root->right , data);
    }
    
    return root ;


    
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


void TakeInput(Node * &root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = MakeBST(root, data);
        cin >> data;
    }
}

int main()
{
    Node *root = NULL;
    cout << "enter the data for the tree" << endl;
    TakeInput(root);

    LevelOrderTraversal(root);

    return 0;
}