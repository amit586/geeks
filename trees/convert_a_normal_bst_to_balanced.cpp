#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void makeLL(Node *root,Node *&prev,Node *&head,int &n)
{
	if(!root)
		return;
	makeLL(root->left,prev,head,n);
	if(!prev)
		prev=root,head=root;
	else
	{
		prev->right =root;
		root->left = prev;
		prev = root;
	}
	n++;
	makeLL(root->right,prev,head,n);
}

Node *makeBalancedBst(Node *&ptr,int n)
{
	if(n<=0)
		return NULL;
	if(!ptr)
		return NULL;
	
	Node *l = makeBalancedBst(ptr,n/2);
	//Node *temp = new Node(ptr->data);
	Node *root = ptr;
	root->left = l;
	ptr=ptr->right;
	root->right = makeBalancedBst(ptr,n-n/2-1);
	return root;


}

Node* convert(Node *root)
{
	Node *head=NULL,*prev=NULL;
	int n=0;
	makeLL(root,prev,head,n);
	return makeBalancedBst(head,n);
}

void preorder(Node *root)
{
	if(!root)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(10); 
    root->left = new Node(8); 
    root->left->left = new Node(7); 
    root->left->left->left = new Node(6); 
    root->left->left->left->left = new Node(5); 
    root = convert(root);
    preorder(root);
	
	return 0;
}