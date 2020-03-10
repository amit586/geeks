#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x)
	{
		data = x;
		left=right=NULL;
	}
};

void findLeaf(Node *root,vector <int> &v)
{
	if(!root)
		return;
	else if(root->left==NULL && root->right==NULL)
	{
		v.push_back(root->data);
		return;
	}
	else
	{
		findLeaf(root->left,v);
		findLeaf(root->right,v);
	}
}

void printBoundary(Node *root)
{
	if(!root)
		return;
	vector <int> v;
	Node *temp= root;
	while(temp && temp->left)
	{
		v.push_back(temp->data);
		temp = temp->left;
	}
	findLeaf(root,v);
	vector <int> rv;
	if(root->right)
		temp = root->right;
	while(temp && temp->right)
	{
		rv.push_back(temp->data);
		temp=temp->right;
	}
	for(auto it = rv.rbegin();it!=rv.rend();++it)
	{
		v.push_back(*it);
	}
	for(auto n:v)
		cout<<n<<" ";
	cout<<endl;


}

int main(int argc, char const *argv[])
{
	Node* root = new Node(20); 
    root->left = new Node(8); 
    root->left->left = new Node(4); 
    root->left->right = new Node(12); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    root->right = new Node(22); 
    root->right->right = new Node(25); 
  
    printBoundary(root); 
	
	return 0;
}