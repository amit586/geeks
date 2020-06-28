#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

// void morris(Node *root)
// {
// 	Node *curr=root;
// 	while(curr)
// 	{
// 		if(curr->left==NULL){
// 			cout<<curr->data<<" ";
// 			curr = curr->right;
// 		}else{
// 			Node *pre = curr->left;
// 			while(pre and pre->right and pre->right!=curr)
// 				pre = pre->right;
// 			if(pre->right==curr)
// 			{
// 				cout<<curr->data<<" ";
// 				pre->right=NULL;
// 				curr=curr->right;
// 			}
// 			else
// 				pre->right = curr,curr=curr->left;
// 		}
// 	}
// }

int reverseMorris(Node *root,int k)
{
	Node *curr = root;
	while(curr)
	{
		if(root->right==NULL)
		{
			root=root->left;
			k--;
			if(k==0)
				return root->data;
		}
		else
		{
			Node *pre = curr->right;
			while(pre->left and pre->left!=curr)
				pre=pre->left;
			if(pre->left==curr)
			{
				pre->left = NULL;
				k--;
				if(k==0)
					return curr->data;
				curr=curr->left;
			}
			else
			{
				pre->left = curr;
				k--;
				if(k==0)
					return curr->data;
				curr=curr->right;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	Node* root = new Node(4); 
    root->left = new Node(2); 
    root->right = new Node(7); 
    root->left->left = new Node(1); 
    root->left->right = new Node(3); 
    root->right->left = new Node(6); 
    root->right->right = new Node(10); 
    cout<<reverseMorris(root,2)<<endl;
  
	
	return 0;
}