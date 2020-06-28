#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

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

void sumk(Node *root,int &sum,int &k)
{
	if(!root)
		return ;
	sumk(root->left,sum,k);
	if(k>0)
	{
		sum+=root->data;
		k--;
	}
	else
		return ;
	sumk(root->right,sum,k);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,temp,k;
		cin>>n;
		Node *root = NULL;
		while(n--)
		{
			cin>>temp;
			root = insert(root,temp);
		}
		cin>>k;
		int ans = 0;
		sumk(root,ans,k);
		cout<<ans<<endl;
	}
	return 0;
}