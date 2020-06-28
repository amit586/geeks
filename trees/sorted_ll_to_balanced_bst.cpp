#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

void inorder(Node *root)
{
	if(!root)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node *root)
{
	if(!root)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node *buildTree(list<int> &l,list<int>::iterator &it,int n)
{
	if(n<=0)
		return NULL;
	Node * root = new Node(0);
	root->left = buildTree(l,it,n/2);
	root->data = (*it);
	it++;
	root->right = buildTree(l,it,n-n/2-1);
	return root;
}


int main(int argc, char const *argv[])
{
	int n,temp;
	cin>>n;
	list<int> l;
	for(int i=0;i<n;i++)
		cin>>temp,l.push_back(temp);
	list<int>::iterator it = l.begin();
	Node *root = buildTree(l,it,n);
	inorder(root);
	cout<<endl;
	preorder(root);
	return 0;
}