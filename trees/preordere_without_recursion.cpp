#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left , *right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}	
};

void iterativePreorder(Node *root)
{
	if(!root)
		return;
	stack <Node *> s;
	s.push(root);
	Node *temp = NULL;
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		while(temp )
		{	
			cout<<temp->data<<" ";
			if(temp->right)
				s.push(temp->right);
			temp=temp->left;
		}
	}
}

int main(int argc, char const *argv[])
{
  Node *root = new Node(10); 
  root->left        = new Node(8); 
  root->right       = new Node(2); 
  root->left->left  = new Node(3); 
  root->left->right = new Node(5); 
  root->right->left = new Node(2); 
  iterativePreorder(root); 
	return 0;
}