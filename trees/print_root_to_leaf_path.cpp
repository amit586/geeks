#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

void printPath(Node *root,list<int> &l)
{
	if(!root)
		return ;
	if(!root->left && !root->right)
	{
		for(auto it:l)
			cout<<it<<" ";
		cout<<root->data<<endl;
	}
	l.push_back(root->data);
	printPath(root->left,l);
	printPath(root->right,l);
	l.pop_back();
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(5); 
    root->left = new Node(1); 
    root->right = new Node(6); 
    root->left->left = new Node(3); 
    root->right->left = new Node(7); 
    root->right->right = new Node(4); 
  
	list<int> l;
	printPath(root,l);
	return 0;
}