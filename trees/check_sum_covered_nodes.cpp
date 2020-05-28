#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),right(NULL),left(NULL){};
};

int sumleft(Node *root)
{
	if(!root)
		return 0;
	if(root->left)
		return root->data +sumleft(root->left);
	else if(root->right)
		return root->data +sumleft(root->right);
	return root->data;
}

int sumRight(Node *root)
{
	if(!root)
		return 0;
	if(root->right)
		return root->data +sumRight(root->right);
	else if(root->left)
		return root->data +sumRight(root->left);
	return root->data;
}

int sum(Node *root)
{
	if(!root)
		return 0;
	return root->data + sum(root->left)+sum(root->right);
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(9);
	root->left = new Node(4);
	root->left->left = new Node(3);
	root->left->right = new Node(6);
	root->left->right->left = new Node(5);
	root->left->right->right = new Node(7);
	root->right = new Node(17);
	root->right->right = new Node(22);
	root->right->right->left = new Node(20);

	//int boundry = root->data + sumleft(root->left)+sumleft(root->right);
	int sumall = sum(root);
	int l = sumleft(root->left);
	//cout<<endl<<l<<endl;
	int r = sumRight(root->right);
	//cout<<endl<<r<<endl;
	cout<<l+r+root->data<<endl;
	cout<<sumall<<endl;
	return 0;
}