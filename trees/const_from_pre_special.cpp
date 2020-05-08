#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void preorder(Node *root)
{
	if(root==NULL)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node *buildTree(int pre[],char special[],int n,int &i)
{
	if(i>=n)
		return NULL;
	Node *root = new Node(pre[i++]);
	if(special[i-1]=='L')
		return root;
	root->left=buildTree(pre,special,n,i);
	root->right=buildTree(pre,special,n,i);
	return root;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int pre[n];
		char special[n];
		for(int i=0;i<n;i++)	cin>>pre[i];
		for(int i=0;i<n;i++)	cin>>special[i];
		int i=0;
		Node * root = buildTree(pre,special,n,i);
		preorder(root);
	}
	return 0;
}