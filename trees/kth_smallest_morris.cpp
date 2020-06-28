#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

int kthMorris(Node *root,int k)
{

	Node *curr = root;
	while(curr)
	{
		if(curr->left==NULL)
		{
			cout<<curr->data<<" ";
			k--;
			if(k==0)
				return curr->data;
			curr=curr->right;
		}
		else
		{
			Node *pre = curr->left;
			while(pre and pre->right and pre->right!=curr)
				pre=pre->right;
			
			if(pre->right==curr)
			{
				pre->right=NULL;
				k--;
				cout<<curr->data<<" ";
				if(k==0)
					return curr->data;
				curr=curr->right;
			}
			else
			{
				pre->right=curr;
				curr=curr->left;
			}
		}
	}
}

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return new Node(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

int main(int argc, char const *argv[])
{
	Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
     for (int k=1; k<=7; k++) 
       cout<<kthMorris(root,1)<<endl;
	return 0;
}