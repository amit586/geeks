#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void makeLL(Node *root,Node *&ptr,Node *&head,Node *&tail,int &n)
{
	if(!root)
		return;
	makeLL(root->left,ptr,head,tail,n);
	if(!ptr)
		ptr = root,head=root,tail=root;
	else
	{
		ptr->right = root;
		root->left = ptr;
		tail=root;
		ptr = root;
	}
	n++;
	makeLL(root->right,ptr,head,tail,n);
}

Node *makeBST(Node *&ptr,int n)
{
	if(n<=0)
		return NULL;
	Node *l = makeBST(ptr,n/2);
	Node *root = ptr;
	root->left = l;
	ptr=ptr->right;
	root->right = makeBST(ptr,n-n/2-1);
	return root;
}

void inorder(Node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


Node *merge(Node *root1,Node *root2)
{

	Node *head1,*tail1,*head2,*tail2,*ptr;
	head1=tail1=ptr=NULL;
	int n = 0;
	
	makeLL(root1,ptr,head1,tail1,n);
	
	ptr=NULL;
	
	makeLL(root2,ptr,head2,tail2,n);
	
	Node *merged = NULL,*headM=NULL;

	while(head1 and head2)
	{
		if(!merged)
		{
			if(head1->data<head2->data)
				headM=merged=head1,head1=head1->right;
			else
				headM=merged=head2,head2=head2->right;
		}
		else if(head1->data<head2->data)
		{
			merged->right=head1;
			head1->left = merged;
			merged=merged->right;
			head1=head1->right;
		}
		else
		{
			merged->right = head2;
			head2->left = merged;
			merged=merged->right;
			head2=head2->right;
		}
	}
	if(head1)
	{
		merged->right=head1;
		head1->left=merged;
		merged = tail1;
	}

	if(head2)
	{
		merged->right=head2;
		head2->left=merged;
	}


	return makeBST(headM,n);
}

int main(int argc, char const *argv[])
{
	
    /* Create following tree as first balanced BST  
        100  
        / \  
        50 300  
    / \  
    20 70  
    */
    Node *root1 = new Node(100);  
    root1->left     = new Node(50);  
    root1->right = new Node(300);  
    root1->left->left = new Node(20);  
    root1->left->right = new Node(70);  
  
    /* Create following tree as second balanced BST  
            80  
        / \  
        40 120  
    */
    Node *root2 = new Node(80);  
    root2->left     = new Node(40);  
    root2->right = new Node(120);  
    Node *root = merge(root1,root2);
    inorder(root);
	return 0;
}