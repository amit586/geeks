#include<bits/stdc++.h>
using namespace std;

class Node
{
	public :
		int data;
		Node *left , *right;
		Node(int x)
		{
			data = x;
			left = right = NULL;
		}
};

void findNInorder(Node *root,int n,int *count,Node ** nth)
{
	if(!root)
		return ;
	
	{
		findNInorder(root->left,n,count,nth);
		++*count;
		if(*count==n &&  root)
		{
		  //  cout<<root->data<<endl;
		    *nth = root;
		    return;
		}
		findNInorder(root->right,n,count,nth);
	}
}

int main()
{
	Node *root= new Node(1);
	root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->right = new Node(50);
    int n = 2;
    int count = 0;
    Node *nth=NULL;
    findNInorder(root,n,&count,&nth);
    cout<<nth->data<<endl;
    
}
