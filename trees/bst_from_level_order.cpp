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

Node *buildTree(vector<int> &L)
{
	if(L.size()==0)
		return NULL;
	Node *root = new Node(L[0]);
	if(L.size()==1)
		return root;
	vector<int> l,r;
	for(int i=1;i<L.size();i++)
		L[i]<L[0]?l.push_back(L[i]):r.push_back(L[i]);
	root->left = buildTree(l);
	root->right = buildTree(r);
	return root;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> L(n);
	for(int i=0;i<n;i++)
		cin>>L[i];
	Node *root = buildTree(L);
	inorder(root);

	return 0;
}