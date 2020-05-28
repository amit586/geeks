#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

int getSize(Node *root,int n,bool &ans)
{
	if(!root)
		return 0;
	int sl = getSize(root->left,n,ans);
	int sr = getSize(root->right,n,ans);
	int sz = sl+sr+1;
	if(n-sz==sz)
		ans=true;
	return sz;
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(5); 
    root->left = new Node(1); 
    root->right = new Node(6); 
    root->left->left = new Node(3);
    root->left->right = new Node(8) ;
    root->right->left = new Node(7); 
    root->right->right = new Node(4); 
    bool ans=false;
    getSize(root,7,ans);
    cout<<ans<<endl;
	return 0;
}