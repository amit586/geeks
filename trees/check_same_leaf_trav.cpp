// C++ code to check if leaf traversals 
// of two Binary Trees are same or not. 
#include<bits/stdc++.h> 
using namespace std; 

// Binary Tree Node 
struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 

// Returns new Node with data as 
// input to below function. 
Node* newNode(int d) 
{ 
	Node* temp = new Node; 
	temp->data = d; 
	temp->left = NULL; 
	temp->right = NULL; 
	
	return temp; 
} 

// checks if a given node is leaf or not. 
bool isLeaf(Node* root) 
{ 
	if(root == NULL) 
		return false; 
	if(!root->left && !root->right) 
		return true; 
	return false; 
} 

// iterative function. 
// returns true if leaf traversals 
// are same, else false. 
bool isSame(Node* root1, Node* root2) 
{ 
	stack<Node*> s1,s2;
	s1.push(root1),s2.push(root2);
	while(!s1.empty()||!s2.empty())
	{
		Node *temp1 = s1.top(),*temp2 = s2.top();
		s1.pop(),s2.pop();

		while(temp1 && (temp1->left||temp1->right))
		{
			if(temp1->right)
				s1.push(temp1->right);
			if(temp1->left)
				s1.push(temp1->left);
			temp1 = s1.top(),s1.pop();
		}

		while(temp2 && (temp2->left||temp2->right))
		{
			if(temp2->right)
				s2.push(temp2->right);
			if(temp2->left)
				s2.push(temp2->left);
			temp2 = s2.top(),s2.pop();
		}
		if(temp1&& !temp2 || !temp1&&temp2)
			return false;

		if(temp1->data!=temp2->data)
			return false;
		if((s1.empty()&& !s2.empty())|| (!s1.empty() && s2.empty()))
			return false;
	}

	return true; 
} 

// Driver Code 
int main() 
{ 
	Node* root1 = newNode(1); 
	root1->left = newNode(2); 
	root1->right = newNode(3); 
	root1->left->left = newNode(4); 
	root1->right->left = newNode(6); 
	root1->right->right = newNode(7); 
	
	Node* root2 = newNode(0); 
	root2->left = newNode(1); 
	root2->right = newNode(5); 
	root2->left->right = newNode(4); 
	root2->right->left = newNode(6); 
	root2->right->right = newNode(7); 
	
	if(isSame(root1, root2)) 
		cout << "Same"; 
	else
		cout << "Not Same"; 
	return 0; 
} 

// This code is contributed 
// by AASTHA VARMA 
