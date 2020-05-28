#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	vector<Node*> child;
	Node(int x)
	{
		data=x;
	}
};

Node *buildTree(int pre[],int n,int &i,int d,int k)
{
	if(i>=n || d<=0)
		return NULL;
	Node *root = new Node(pre[i]);
	for(int j=0;j<k;j++)
		if(i<n && h>0)	
		{
			i++;
			root->child.push_back(buildTree(pre,n,i,d-1,k));
		}
		else
			root->child.push_back(NULL);
	return root;
}

void preorder(Node *root,int k)
{
	if(root)
	{
		cout<<root->data<<" ";
		for(int i=0;i<root->child.size();i++)
			preorder(root->child[i],k);
	}
}


void postorder(Node *root,int k)
{
	if(root)
	{
		for(int i=0;i<root->child.size();i++)
			postorder(root->child[i],k);
		cout<<root->data<<" ";
	}
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		int pre[n];
		for(int i=0;i<n;i++)
			cin>>pre[i];
		int i=0;
		int depth = ceil(log2(n*(k-1)+1)/log2(k));
		Node *root = buildTree(pre,n,i,depth,k);
		preorder(root,k);
		postorder(root,k);
	}
	return 0;
}