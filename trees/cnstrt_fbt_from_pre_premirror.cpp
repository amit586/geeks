// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

Node* constructBinaryTree(int pre[], int preMirror[], int size);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}// } Driver Code Ends


/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed

Node *buildTree(int pre[],int post[],int n)
{
	if(n==0)
		return NULL;
	Node *root = new Node(pre[0]);
	if(n==1)
		return root;
	int part = 0;
	while(post[part]!=pre[1])
		part++;
	int lenL = part+1;
	int lenR = n - lenL-1;
	root->left = buildTree(pre+1,post,lenL);
	root->right = buildTree(pre+lenL+1,post+lenL,lenR);
	return root;
}


Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
	reverse(preMirror,preMirror+size);
	return buildTree(pre,preMirror,size);
}