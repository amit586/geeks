#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void pritnPath(Node *root,list<int> &l,int dest)
{
	if(!root)
		return ;
	if(root->data==dest)
	{
		for(auto it:l)
			cout<<it<<" ";
		cout<<dest<<endl;
		return;
	}
	l.push_back(root->data);
	pritnPath(root->left,l,dest);
	pritnPath(root->right,l,dest);
	l.pop_back();
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    int dest = 8;
	list<int> l;
	pritnPath(root,l,dest);
	return 0;
}