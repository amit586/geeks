#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};


void BSTToMinHeap(Node* root,Node *&prev,Node * &head)
{
	if(!root)
		return;
	BSTToMinHeap(root->left,prev,head);
	if(prev==NULL)
		prev=root,head=root;
	else
	{
		prev->right=root;
		root->left = prev;
		prev=root;
	}
	BSTToMinHeap(root->right,prev,head);

}

void convert(Node *head)
{
	queue<Node*> q;
	q.push(head);
	head=head->right;

	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		temp->left=temp->right=NULL;

		if(head)
		{
			temp->left = head;
			q.push(temp->left);
			head=head->right;
		}
		if(head)
		{		
			temp->right = head;
			q.push(temp->right);
			head=head->right;
		}
	}
}

void printHeap(Node *head)
{
	while(head)
		cout<<head->data<<" ",head =head->right;
}

void inorder(Node *root)
{
	if(!root)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(8); 
    root->left = new Node(4); 
    root->right = new Node(12); 
    root->right->left = new Node(10); 
    root->right->right = new Node(14); 
    root->left->left = new Node(2); 
    root->left->right = new Node(6); 

  	Node *head = NULL,*prev = NULL;
    BSTToMinHeap(root,prev,head);
    convert(head);
    inorder(head);
    return 0;
}