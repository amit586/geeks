#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void preorder(Node *root)
{
	if(!root)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node *buildTree(vector<int> &arr,int low,int high)
{
	int mid = (low+high)/2;
	Node *root = new Node(arr[mid]);
	if(low==high)
		return root;
	root->left = buildTree(arr,low,mid-1);
	root->right = buildTree(arr,mid+1,high);
	return root; 
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)	
			cin>>a[i];

		Node *root = buildTree(a,0,n-1);
		preorder(root);
		cout<<endl;
	}
	return 0;
}