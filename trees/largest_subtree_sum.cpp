#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

int largestSubtreeSum(Node *root,int &mx)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;
	int l=largestSubtreeSum(root->left,mx);
	int r=largestSubtreeSum(root->right,mx);
	mx = max(root->data+l+r,mx);
	return root->data+l+r;
}

int main() 
{ 
    /* 
               1 
             /   \ 
            /     \ 
          -2       3 
          / \     /  \ 
         /   \   /    \ 
        4     5 -6     2 
    */
  
    Node* root = new Node(1); 
    root->left = new Node(-2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(-6); 
    root->right->right = new Node(2); 
    int ans=INT_MIN;
  	largestSubtreeSum(root,ans);
    cout <<ans<<endl; 
    return 0; 
} 