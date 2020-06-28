#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void makeMap(Node *root,set<int> &s)
{
	if(!root)
		return;
	s.insert(root->data);
	makeMap(root->left,s);
	makeMap(root->right,s);
}

void modify(Node *root,set<int> &s,set<int>::iterator &itr)
{
	if(!root)
		return;
	modify(root->left,s,itr);
	root->data = *itr;
	itr++;
	modify(root->right,s,itr);
}

void convert(Node *root)
{
	set<int> s;
	makeMap(root,s);
	auto itr = s.begin();
	modify(root,s,itr);
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
	Node* root = new Node(5); 
    root->left = new Node(7); 
    root->right = new Node(9); 
    root->right->left = new Node(10); 
    root->left->left = new Node(1); 
    root->left->right = new Node(6); 
    root->right->right = new Node(11); 
    inorder(root);
    convert(root);
    cout<<endl;
    inorder(root);

	return 0;
}