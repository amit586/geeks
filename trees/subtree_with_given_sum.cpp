#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

int solve(Node *root,bool &ans,int sum)
{
	if(ans)
		return 0;
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;
	int l = solve(root->left,ans,sum);
	int r = solve(root->right,ans,sum);
	if(l+r+root->data==sum)
	{
		ans=true;
	}
	return l+r+root->data;
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(8); 
    root->left    = new Node(5); 
    root->right   = new Node(4); 
    root->left->left = new Node(9); 
    root->left->right = new Node(7); 
    root->left->right->left = new Node(1); 
    root->left->right->right = new Node(12); 
    root->left->right->right->right = new Node(2); 
    root->right->right = new Node(11); 
    root->right->right->left = new Node(3); 
    int sum = 22; 
    bool ans=false;
    solve(root,ans,sum);
    cout<<(ans?"YES":"NO")<<endl;
	return 0;
}