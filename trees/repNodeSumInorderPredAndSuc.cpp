#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x)
	{
		data = x;
		left = right=NULL;
	}
};

void inOrderSum(Node *root , std::vector<int> v,int *i)
{
	if(root==NULL)
		return ;
	inOrderSum(root->left,v,i);
	root->data = v[*i-1]+v[*i+1];
	++*i;
	inOrderSum(root->right,v,i);
}

void inOrder(Node *root, std::vector<int> &v)
{
	if(root==NULL )
		return ;
	inOrder(root->left,v);
	v.push_back(root->data);
	inOrder(root->right,v);
}

void iO(Node *root)
{
	if(root==NULL )
		return ;
	iO(root->left);
	cout<<root->data<<" ";
	iO(root->right);
}

int main(int argc, char const *argv[])
{
	/*
			1
		  /   \ 
		 2     3
	   /  \   /  \ 
	  4   5  6    7
	*/
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	std::vector<int> v;
	v.push_back(0);
	inOrder(root,v);
	v.push_back(0);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	int i=1;
	inOrderSum(root,v,&i);
	iO(root);

	return 0;
}