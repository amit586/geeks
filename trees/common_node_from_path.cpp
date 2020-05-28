#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

bool printCommon(Node *root,int n1,int n2,bool &flag)
{
	if(!root)
		return false;
	if(root->data==n1 || root->data==n2)
		return true;
	bool l,r;
	l = printCommon(root->left,n1,n2,flag);
	r = printCommon(root->right,n1,n2,flag);
	if(l and r)
		flag=true;
	if(flag and (l or r))
		cout<<root->data<<" ";
	return l or r;

}

int main(int argc, char const *argv[])
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->left->left->left = new Node(8); 
    root->right->left->left = new Node(9); 
    root->right->left->right = new Node(10);
    bool flag=false;
	printCommon(root,9,7,flag);
	return 0;
}