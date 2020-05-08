// { Driver Code Starts
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

Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
	int ri = inStrt;
	while(in[ri]!=pre[0])
		ri++;
	Node *root = new Node(pre[0]);

	if(inStrt==inEnd)
		return root;
	if(ri!=inStrt)
		root->left = buildTree(in,pre+1,inStrt,ri-1);
	if(ri!=inEnd)
		root->right = buildTree(in,pre + ri-inStrt+1,ri+1,inEnd);
	return root;
}