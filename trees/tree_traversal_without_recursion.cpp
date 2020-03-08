// C++ program to print inorder traversal 
// using stack. 
#include<bits/stdc++.h> 
using namespace std; 

/* A binary tree Node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
	Node (int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 
//// using stack ///////////////
void inOrder(Node *root)
{
	stack <Node*> s;
	Node * curr = root;
	while(!s.empty() || curr!=NULL)
	{ 
		while(curr)
		{
			s.push(curr);
			curr=curr->left;
		}                   

		curr = s.top();
		s.pop();
		cout<<curr->data<<" ";
		curr = curr->right;              
	}
}

////////// morris traversal //////////

void MorrrisIn(Node *root)
{
	Node *curr = root;
	while(curr!=NULL)
	{
		if(curr->left == NULL)
		{
			cout<<curr->data<<endl;
			curr = curr->right;
		}
		else
		{
			Node * pred = curr->left;
			while(pred->right && pred->right != curr)
				pred = pred->right;
			if(pred->right==NULL)
			{
				pred->right = curr;
				curr = curr->left;	
			}
			else
			{
				pred->right=NULL;
				cout<<curr->data<<endl;
				curr = curr->right;
			}			
		}
	}
}


/* Driver program to test above functions*/
int main() 
{ 

	/* Constructed binary tree is 
			1 
			/ \ 
		  2	   3 
		 / \ 
	   4	5 
	*/
	struct Node *root = new Node(1); 
	root->left	 = new Node(2); 
	root->right	 = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	cout<<"without recursion : ";
	//inOrder(root); 
	//cout<<"morris : ";
	MorrrisIn(root);
	return 0; 
} 
