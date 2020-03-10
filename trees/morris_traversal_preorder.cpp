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

void MorrisTraversal(Node *root)
{
	
	Node *current=root,*pre=NULL;
	while(current)
	{
		if(!current->left)
		{
			cout<<current->data<<" ";
			current=current->right;
		}
		else
		{
			Node *pred =current->left;
			while(pred && pred->right && pred->right!=current )
				pred=pred->right;
			if(pred->right==NULL)
			{
				cout<<current->data<<" ";
				pred->right=current;
				current=current->left;
			}
			else
			{
				pred->right=NULL;
				current=current->right;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
  
    MorrisTraversal(root); 
	return 0;
}