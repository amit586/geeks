// C++ Program to find inorder successor. 
#include<bits/stdc++.h> 
using namespace std; 

// structure of a Binary Node. 
struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 

// Function to create a new Node. 
Node* newNode(int val) 
{ 
	Node* temp = new Node; 
	temp->data = val; 
	temp->left = NULL; 
	temp->right = NULL; 
	
	return temp; 
} 

// function that prints the inorder successor 
// of a target node. next will point the last 
// tracked node, which will be the answer. 
void inorderSuccessor(Node *root, Node *target )
{
	static Node * next = NULL;
	if(!root)
		return ;
	inorderSuccessor(root->right,target);
	if(root == target)
		if(next)
			cout<<root->data<<" "<<next->data<<endl;
	next = root;
	inorderSuccessor(root->left,target);
}
// Driver Code 

void inorderSuccessor2(Node *root ,Node *target ,Node **next)
{
	if(root)
	{
		inorderSuccessor2(root->right,target,next);
		if(root==target)
		{
			if(*next)
				cout<<root->data<<" "<<(*next)->data<<endl;
			else
				cout<<root->data<<" "<<-1<<endl;
			return;
		}
		*next = root;
		inorderSuccessor2(root->left,target,next);
	}
}

int main() 
{ 
	
	// Let's construct the binary tree 
	// as shown in above diagram. 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 
	
	// Case 1 
	Node* next = NULL; 
	inorderSuccessor2(root,root->right,&next); 

	// case 2 
	next = NULL; 
	inorderSuccessor2(root, root->left->left,&next); 

	// case 3 
	next = NULL; 
	inorderSuccessor2(root, root->right->right,&next); 
	
	return 0; 
} 

// This code is contributed by AASTHA VARMA 
