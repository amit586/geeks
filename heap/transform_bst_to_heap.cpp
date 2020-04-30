#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data=x,left=right=NULL;
    }
};

void heapfiy(Node *root)
{
    if(!root)
        return;
    Node* mn = root;
    if(root->left && mn->data>root->left->data) mn=root->left;
    if(root->right && mn->data > root->right->data) mn=root->right;
    
    if(mn!=root) swap(root->data,mn->data),heapfiy(mn);

}

void convertToMinHeapUtil(Node *root)
{
    if(!root)
        return;
    convertToMinHeapUtil(root->left);
    convertToMinHeapUtil(root->right);
    heapfiy(root);
}

void preorderTraversal(Node *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
} 
/// Driver program to test above 
int main() 
{ 
    // BST formation 
    Node *root = new Node(4); 
    root->left = new Node(2); 
    root->right = new Node(6); 
    root->left->left = new Node(1); 
    root->left->right = new Node(3); 
    root->right->left = new Node(5); 
    root->right->right = new Node(7); 
    preorderTraversal(root); 
    convertToMinHeapUtil(root); 
    cout << "Preorder Traversal:" << endl; 
    preorderTraversal(root); 
  
    return 0; 
} 