#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void findPair(Node *root,int val,unordered_set<int> &s,list<pair<int,int>> &l)
{
	if(!root)
		return;

	if(s.find(val-root->data)!=s.end())
		l.push_back(make_pair(root->data,val-root->data));
	s.insert(root->data);
	findPair(root->left,val,s,l);
	findPair(root->right,val,s,l);
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
    root->left->right->right->right = new Node(4); 
    root->right->right = new Node(11); 
    root->right->right->left = new Node(3); 
    list<pair<int,int>> l;
    unordered_set<int> s;
	findPair(root,root->data,s,l);
	for(auto it:l)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}