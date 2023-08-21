#include <iostream>
#include <unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* left ;
    Node* right ;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
pair<bool , int> solve(Node* root){
    // base case check crow 
    // root nodes + null nodes 
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool , int> p = make_pair(true , root->data);
        return p ;
    }
    if (root == NULL)
    {
        pair<bool , int> p = make_pair(true , INT_MIN);
        return p ;
    }


    pair<bool , int> leftCall = solve(root->left);
    pair<bool , int> RightCall = solve(root->right);

    // check that the child trees are heaps or not ?
    // chcek that the childs are smaller than the parent 

    if (leftCall.first == true && RightCall.first == true && root->data > leftCall.second && root->data > leftCall.first)
    {
        pair<bool , int> p = make_pair(true , root->data);
        return p;
    }
    else{
        pair<bool , int> p = make_pair(false , root->data);
        return p;
    }
    
    
    
    
}
int main()
{   
    // given a complete binary tree show weather it is a heap or not ? 
    // 
    return 0;
}