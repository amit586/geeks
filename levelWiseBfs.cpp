#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node * left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};

int height(Node *root)
{
	if(root)
		return 1+max(height(root->left),height(root->right));
	else
		return 0;
}

void printNLevel(Node *root,int level)
{
	if(root==NULL)
		return 	;
	else if(level==1 && root)
	{
		cout<<root->data<<" ";	
	}
	else
	{
		printNLevel(root->left,level-1);
		printNLevel(root->right,level-1);
	}
}

void levelOrder(Node *root)
{
	int h = height(root);
	for(int i=1;i<=h;i++)
	{
		printNLevel(root,i);
		cout<<endl;
	}
}

int main()
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->right = new Node(6); 
  
    levelOrder(root); 
    return 0; 
}
