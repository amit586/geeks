#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node * left,*right;
		Node(int x)
		{
			data = x;
			left = right = NULL;
		}
};

int Depth(Node *root)
{
	if(!root)
	{
		return 0;
	}
	return max(1+Depth(root->left), 1 + Depth(root->right));
}


void printNLevel(Node *root , int n)
{
	if(n<=0)
		return;
	if(n<=1 && root)
	{
		cout<<root->data<<" ";
		return;
	}
	if(root)
	{
		printNLevel(root->left,n-1);
		printNLevel(root->right,n-1);
	}
}

void printAllLevel(Node *root,int levels)
{
	for(int i=1;i<=levels;i++)
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
  	cout<<"levels : "<<Depth(root)<<endl;
  	printAllLevel(root,Depth(root));
  	
	return 0;
}
