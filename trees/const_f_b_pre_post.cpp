#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
	
};

Node *buildTree(int pre[],int post[],int n)
{
	if(n==0)
		return NULL;
	Node *root = new Node(pre[0]);
	if(n==1)
		return root;
	int part=0;
	while(post[part]!=pre[1])
		part++;
	int lenL = part+1;
	int lenR = n-lenL-1;

	root->left = buildTree(pre+1,post,lenL);
	root->right = buildTree(pre+lenL+1,post+lenL,lenR);
	return root	;
}

void inorder(Node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int pre[n],post[n];
		for(int i=0;i<n;i++)
			cin>>pre[i];
		for(int i=0;i<n;i++)
			cin>>post[i];

		Node *root= buildTree(pre,post,n);
		inorder(root);
	}
	return 0;
}