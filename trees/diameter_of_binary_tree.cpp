#include <bits/stdc++.h>
#define f(x) get<0>(x)
#define s(x) get<1>(x)

using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

tuple<int,int> diameter(Node *root)
{
	if(!root)
		return make_tuple(0,0);
	tuple<int,int> l = diameter(root->left);
	tuple<int,int> r = diameter(root->right);
	return make_tuple(max(f(l),f(r))+1,max(f(l)+f(r)+1,max(s(l),s(r))));
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(10); 
    root->left = new Node(5); 
    root->right = new Node(100); 
    root->right->left = new Node(50); 
    root->right->right = new Node(150); 
    root->right->right->right = new Node(40);
    root->right->left->left = new Node(50);
    root->right->left->left->left = new Node(10);
    root->right->left->left->left->left = new Node(5);
	
	tuple<int,int> ans = diameter(root);
	cout<<s(ans)<<endl;
	return 0;
}