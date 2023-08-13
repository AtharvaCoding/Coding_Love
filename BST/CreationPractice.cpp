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
Node *BuildTree(Node *root, int data)
{
    // base case // 1 element aaya toh sorted hai na vo bhai
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // ek case
    if (root->data > data)
    {
        root->left = BuildTree(root->left, data);
    }
    else
    {
        root->right = BuildTree(root->right, data);
    }
    return root;
}

// NLR
void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
// NLR
void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
// NLR
void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void LevelOrderTraversal(Node *&root)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        cout << temp->data << " ";

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
void GetData(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = BuildTree(root, data);
        cout << "Enter another node" << endl;
        cin >> data;
    }
}
Node* FindMinimum(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}
Node *FindNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        return root;
    }

    if (root->data > target)
    {
        // left me search karna hai
        return FindNodeInBST(root->left, target);
    }
    else
    {
        // right me search karo
        return FindNodeInBST(root->right, target);
    }
}

// Node* DeleteANodeFromBST(Node *root, int target)
// {
//     // base case
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     // 1 pohocho us node tak
//     Node* temp = FindNodeInBST(root , target);

//     // 2 usko delete crow 
//     // 4 caseas 
//     // 1 
//     if (temp->left == NULL && temp->right == NULL)
//     {
//         delete(temp);
//         return NULL;
//     }
//     else if (temp->left == NULL && temp->right != NULL)
//     {
//         Node* child = temp->right;
//         delete(temp);
//         return child;
//     }
//     else if (temp->left != NULL && temp->right == NULL)
//     {
//         Node* child = temp->left;
//         delete(temp);
//         return child;
//     }
//     else{
//         // sab se imp condition 
//         // Node* tempKaTemp = Inordersuccessor(temp);
//         // temp->data = tempKaTemp->data;
//         // delete(tempKaTemp);                                  // dangling pointer 
//         // return temp;                                       

//         int InorderPredissior = Findmaximum(temp->left);
//         temp->data = InorderPredissior ; 
//         temp->left = DeleteANodeFromBST(temp->left ,InorderPredissior );
//         return root;
//     }
 
    
    
// }
int Findmaximum(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node* DeleteNodeFromBSTnew(Node* root, int target ){
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // Node* temp = root;
        // 4 conditions     
        if (root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL){
            Node* child = root->left ; 
            delete (root) ; 
            return child;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node* child = root->right ; 
            delete (root) ; 
            return child;
        }
        else {
            int InorderPredeccor = Findmaximum(root->left);
            root->data = InorderPredeccor;
            root->left = DeleteNodeFromBSTnew(root->left , InorderPredeccor);
            return root;
        }
        
        
    }
    if (root->data < target)
    {
        // search in left 
        root->right = DeleteNodeFromBSTnew(root->right , target);
    }    
    else if (root->data > target){
        // search in right
        root->left = DeleteNodeFromBSTnew(root->left , target);
    }
    return root;
    
    
}

// Node* Inordersuccessor(Node *inputNode)
// {
//     // base case 
//     if (inputNode == NULL)
//     {
//         return NULL;    
//     }
//     return FindMinimum(inputNode->right);

// }


// Node* InorderPredecessor(Node *inputNode)
// {
//     // base case 
//     if (inputNode == NULL)
//     {
//         return NULL;    
//     }
//     return Findmaximum(inputNode->left);

// }
int main()
{
    Node *root = NULL;
    cout << "Enter the data :" << endl;
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

    GetData(root);
    cout << endl
         << endl;
    LevelOrderTraversal(root);

    cout << endl
         << "Printing the Preorder " << endl;
    PreOrder(root);
    cout << endl
         << "Printing the Postorder " << endl;
    PostOrder(root);
    cout << endl
         << "Printing the Inorder " << endl;
    InOrder(root);
    cout << endl
         << "the Minimum value of node in given binary tree is " << FindMinimum(root) << endl;
    cout << endl
         << "the Maximun value of node in given binary tree is " << Findmaximum(root) << endl;
    // cout << endl
    //      << "The Inorder successor of 5 is " << Inordersuccessor(root->left) << endl;
    root = DeleteNodeFromBSTnew(root , 10);
    LevelOrderTraversal(root);
    return 0;
}