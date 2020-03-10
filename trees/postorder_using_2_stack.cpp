#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};

void postOrderIterative(Node *root)
{
	if(!root)
		return;
	stack <Node *>s;
	stack <int> ans;
	Node *temp=root;
	s.push(root);
	while(!s.empty())
	{
		temp = s.top();
		ans.push(temp->data);
		s.pop();
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);	
	}
	while(!ans.empty())
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}
}

int main(int argc, char const *argv[])
{
	Node* root = NULL; 
    root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
  
    postOrderIterative(root);
	return 0;
}