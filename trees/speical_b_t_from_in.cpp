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
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node *buildTree(int in[],int s,int e)
{
	if(s>e)
		return NULL;
	int rt = 0;
	for(int i=s;i<=e;i++)
		if(in[rt]<in[i])
			rt = i;
	Node *root = new Node(in[rt]);
	if(rt!=s)
		root->left = buildTree(in,s,rt-1);
	if(rt!=e)
		root->right = buildTree(in,rt+1,e);
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
		int arr[n];
		for(int i=0;i<n;i++)	cin>>arr[i];
		Node *root = buildTree(arr,0,n-1);
		inorder(root);
		cout<<endl;
	}
	return 0;
}