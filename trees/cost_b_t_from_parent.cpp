#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node*left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void create(int parent[],int i,Node *created[],Node **root)
{
	if(created[i]!=NULL)
		return ;
	Node *temp = new Node(i);
	created[i]=temp;
	if(parent[i]==-1)
	{
		*root=temp;
		return ;
	}

	if(created[parent[i]]==NULL)
		create(parent,parent[i],created,root);

	if(created[parent[i]]->left==NULL)
		created[parent[i]]->left=created[i];
	else
		created[parent[i]]->right = created[i];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int parent[n];
		for(int i=0;i<n;i++)
			cin>>parent[i];

		Node *root=NULL;
		Node *created[n];
		for(int i=0;i<n;i++)
			created[i]=NULL;
		for(int i=0;i<n;i++)
			create(parent,i,created,&root);
		inorder(root);
	}
	return 0;
}