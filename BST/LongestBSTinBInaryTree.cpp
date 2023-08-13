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
class NodeData
{
public:
    int size;
    int maxval;
    int minval;
    bool validBST;
    NodeData()
    {
    }
    NodeData(int size, int maxval, int minval, bool validBST)
    {
        this->size = size;
        this->maxval = maxval;
        this->minval = minval;
        this->validBST = validBST;
    }
};

NodeData LongestBST(Node *root, int &ans)
{
    if (root == NULL)
    {
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData LeftKaAns = LongestBST(root->left, ans);
    NodeData RightKaAns = LongestBST(root->right, ans);

    NodeData CurrNodeKaAns;

    CurrNodeKaAns.size = LeftKaAns.size + RightKaAns.size + 1;
    CurrNodeKaAns.minval = min(LeftKaAns.minval, root->data);
    CurrNodeKaAns.maxval = max(RightKaAns.maxval, root->data);
    if (LeftKaAns.validBST && RightKaAns.validBST && (root->data > LeftKaAns.maxval) && (root->data < RightKaAns.minval))
    {
        CurrNodeKaAns.validBST = true;
    }
    else
    {
        CurrNodeKaAns.validBST = false;
    }
    if (CurrNodeKaAns.validBST)
    {
        ans = max(ans, CurrNodeKaAns.size);
    }

    return CurrNodeKaAns;
}

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

int main()
{
    Node *root = NULL;
    root = BuildTree();
    // 50
    // 30
    // 5
    // -1
    // -1
    // 20
    // -1
    // -1
    // 60
    // 45
    // -1
    // -1
    // 70
    // 65
    // -1
    // -1
    // 80
    // -1;lfjds
    // -1

    cout << "printing the level order traversal of hte given tree " << endl;
    LevelOrderTraversal(root);

    // NodeData temp = ;
    int ans = 0;
    LongestBST(root, ans);
    cout << endl
         << "The Size of longest BST is : " << ans << endl;

    return 0;
}