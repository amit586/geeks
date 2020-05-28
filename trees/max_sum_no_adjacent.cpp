#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;

class Node 
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

pii maxSum(Node *root)
{
	if(!root)
		return {0,0};
	if(!root->left && !root->right)
		return {root->data,0};
	pii l = maxSum(root->left);
	pii r = maxSum(root->right);
	return {root->data + l.s+r.s,max(l.s+r.s,max(l.f+r.f,max(l.s+r.f,l.f+r.s)))};
}

int main() 
{ 
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->right->left = new Node(4); 
    root->right->right = new Node(5); 
    root->left->left = new Node(1); 
  	pii ans =maxSum(root) ;
    cout <<max(ans.f,ans.s) << endl; 
    return 0; 
} 