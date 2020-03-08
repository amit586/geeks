#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next,*left,*right;
	Node(int x)
	{
		data  = x;
		next=left=right=NULL;
	}	
};

void inorder(Node * root, vector <Node *> & v)
{
	if(root==NULL)
		return;
	inorder(root->left,v);
	v.push_back(root);
	inorder(root->right,v);
}
void print(Node * root)
{
	if(root==NULL)
		return;
	print(root->left);
	if(root->next==NULL)
		cout<<root->data<<" x"<<endl;
	if(root && root->next)
		cout<<root->data<<" "<<root->next->data<<endl;
	print(root->right);
}

void populate(Node *root, vector <Node*> &v,int *i)
{
	if(root==NULL)
		return;
	populate(root->left,v,i);
	root->next = v[*i+1];
	++*i;
	populate(root->right,v,i);
}

void populateNext(Node *root)
{
	vector<Node *> v;
	inorder(root,v);
	v.push_back(NULL);
	v.push_back(NULL);
	int i=0;
	populate(root,v,&i);

	print(root);
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
		
	populateNext(root);

	return 0;
}