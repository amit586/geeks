#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void remove(Node *root,Node *parent,int low,int high)
{
	if(!root)
		return;
	if(root->data<low)
	{
		Node *temp = root;
		parent->left = root->right;
		delete root;
		remove(root->right,parent,low,high);
	}

	if(root->data>high)
	{
		Node *temp = root;
		parent->right = root->left;
		delete root;
		remove(root->left,parent,low,high);
	}

	remove(root->left,root,low,high);
	remove(root->right,root,low,high);
}

Node *insert(Node *root,int key)
{
	if(!root)
		return new Node(key);
	if(root->data==key)
		return root;
	if(root->data>key)
		root->left = insert(root->left,key);
	else
		root->right = insert(root->right,key);
	return root;
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
	Node* root = NULL; 
    root = insert(root, 6); 
    root = insert(root, -13); 
    root = insert(root, 14); 
    root = insert(root, -8); 
    root = insert(root, 15); 
    root = insert(root, 13); 
    root = insert(root, 7);
    inorder(root);
    Node *parent = NULL;
    remove(root,parent,-10,15);
    cout<<endl;
    inorder(root);

	return 0;
}