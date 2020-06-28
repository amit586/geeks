#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

Node *construct(vector<int> &pre,int &ind,int key,int mn,int mx,int n)
{
	if(ind>=n)
		return NULL;
	if(key<mx and key>mn)
	{
		Node *root = new Node(key);
		ind++;
		root->left = construct(pre,ind,pre[ind],mn,root->data,n);
		root->right = construct(pre,ind,pre[ind],root->data,mx,n);
		return root;
	}
	return NULL;
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
	int n;
	cin>>n;
	vector<int> pre(n);
	for(int i=0;i<n;i++)	cin>>pre[i];
	int i=0;
	Node *root = construct(pre,i,pre[0],INT_MIN,INT_MAX,n);
	preorder(root);	
	return 0;
}