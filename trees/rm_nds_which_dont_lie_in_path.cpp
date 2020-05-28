#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

int solve(Node *root,int k,int sum)
{
	if(!root)
		return sum;
	int l = solve(root->left,k,sum+root->data);
	int r = solve(root->right,k,sum+root->data);
	//cout<<root->data<<" "<<l<<" "<<r<<endl;
	if(l<k && root->left)
		delete root->left,root->left=NULL;
	if(r<k && root->right)
		delete root->right,root->right=NULL;
	return max(l,r);
}

void inorder(Node *root)
{
	if(!root)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(int argc, char const *argv[])
{
	
	int k = 45; 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->left->left->left = new Node(8); 
    root->left->left->right = new Node(9); 
    root->left->right->left = new Node(12); 
    root->right->right->left = new Node(10); 
    root->right->right->left->right = new Node(11); 
    root->left->left->right->left = new Node(13); 
    root->left->left->right->right = new Node(14); 
    root->left->left->right->right->left = new Node(15); 
    inorder(root);
    cout<<endl;
    solve(root,k,0);
    inorder(root);
	return 0;
}