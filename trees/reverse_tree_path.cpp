#include <bits/stdc++.h>
using namespace std;

class Node { 
    public:
    int data; 
    Node *left, *right; 
    Node(int x)
    {
    	data = x;
    	left=right=NULL;
    }
}; 

bool findx(Node *root,int x,map <int,Node*> &m)
{
	if(!root)
		return false;
	else if(root->data==x)
	{
		m[root->data]=root;
		return true;
	}
	else
	{
		bool l = findx(root->left,x,m);
		bool r = findx(root->right,x,m);
		if(l || r)
		{
			m[root->data]=root;
			return true;
		}
		else
			return false;
	}
}

void reverseTreePath(Node *root , int data)
{
	map <int,Node*> m;
	findx(root,data,m);
	auto rit = m.rbegin();
	for(auto it=m.begin();it!=m.end();++it)
	{
		rit->second->data = it->first;
		rit++;
	}
}

void inorder(Node* root) 
{ 
    if (root) { 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    }
} 


int	main(int argc, char const *argv[])
{
	Node* root = new Node(7); 
    root->left = new Node(6); 
    root->right = new Node(5); 
    root->left->left = new Node(4); 
    root->left->right = new Node(3); 
    root->right->left = new Node(2); 
    root->right->right = new Node(1); 
  
    /*     7 
         /    \ 
        6       5 
       / \     / \ 
      4  3     2  1          

     */
  
    int data = 3; 
  
    // Reverse Tree Path 
    reverseTreePath(root, data); 
  
    // Traverse inorder 
    inorder(root); 
	return 0;
}