#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

class info
{
public:
	int mx,mn,sz,ans;
	bool bst;	
	info(bool b,int a,int s,int x,int n):bst(b),ans(a),sz(s),mx(x),mn(n){};
};



info largest(Node *root)
{
	if(!root)
	{
		info i(true,0,0,-1000000,1000000);
		return i;
	}

	if(root->left == NULL and root->right==NULL)
	{
		info i(true,1,1,root->data,root->data);
		return i;
	}
	info l = largest(root->left);
	info r = largest(root->right);
	if(l.bst and r.bst and l.mx<root->data and r.mn>root->data)
	{
		info i(true,l.ans+r.ans+1,l.ans+r.ans+1,max(root->data,max(l.mx,r.mx)),min(root->data,min(l.mn,r.mn)));
		return i;
	}
	else
	{
		info i(false,max(l.ans,r.ans),-1,-1,-1);
		return i;
	}
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(60); 
    root->left = new Node(65); 
    root->right = new Node(70); 
    root->left->left = new Node(50); 
	info l = largest(root);
	cout<<l.ans<<endl;
	return 0;
}

