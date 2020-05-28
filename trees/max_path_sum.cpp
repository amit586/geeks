#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

int sum(Node *root,int &mx)
{
	if(!root)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return root->data;
	int l = sum(root->left,mx);
	int r = sum(root->right,mx);
	mx = max(mx,root->data+l+r);
	return root->data + max(l,r);
}

int main(int argc, char const *argv[])
{
	
    Node *root = new Node(-9); 
    root->left = new Node(-9); 
    root->right = new Node(6); 
    // root->left->left = new Node(-8); 
    // root->left->right = new Node(1); 
    // root->left->left->left = new Node(2); 
    // root->left->left->right = new Node(6); 
    // root->right->left = new Node(3); 
    // root->right->right = new Node(9); 
    // root->right->right->right= new Node(0); 
    // root->right->right->right->left= new Node(4); 
    // root->right->right->right->right= new Node(-1); 
    // root->right->right->right->right->left= new Node(10); 
    int mx=0;
    sum(root,mx);
    cout << "Max pathSum of the given binary tree is "sum(root,mx)<< mx<<endl;
    return 0; 
}