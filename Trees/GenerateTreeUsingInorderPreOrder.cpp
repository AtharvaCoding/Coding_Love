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
        left = NULL;
        right = NULL;
    }
};
int GetPosition(int Inorder[] , int n , int elememt){
    for (int i = 0; i < n; i++)
    {
        if (Inorder[i] == elememt)
        {
            return i;
        }
        
    }
    return -1;
    
}
Node *GenerateTreeUsingInorderPreOrder(int Inorder[] , int Preorder[] , int size , int &PreIndex, int InOrderStart , int InOrderEnd)
{
    // base case 
    if (PreIndex >= size ||  InOrderStart > InOrderEnd)
    {
        return NULL;
    }

    int element = Preorder[PreIndex++];
    Node* root = new Node(element);
    int pos = GetPosition(Inorder , size , element);

    root->left = GenerateTreeUsingInorderPreOrder(Inorder , Preorder , size , PreIndex , InOrderStart ,pos - 1) ; 
    root->right = GenerateTreeUsingInorderPreOrder(Inorder , Preorder , size , PreIndex , pos+1 ,InOrderEnd) ; 


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
int main()
{
    // int Inorder[] = {20, 10, 40, 30, 50};
    // int Preorder[] = {10, 20, 30, 40, 50};
    // int size = 5;

    // int Inorder[] = {7,11,2,4,5,13,8,5,4,1};
    // int Preorder[] = {5,4,11,7,2,8,13,4,5,1};
    // int size = 10;

    int Inorder[] = {40,20,50,10,60,30,70};
    int Preorder[] = {10,20,40,50,30,60,70};
    int size = 7;

    int PreIndex = 0;
    int InOrderStart = 0;
    int InOrderEnd = size - 1;

    Node* root = GenerateTreeUsingInorderPreOrder(Inorder ,Preorder , size , PreIndex , InOrderStart , InOrderEnd);
    LevelOrderTraversal(root);

    return 0;
}