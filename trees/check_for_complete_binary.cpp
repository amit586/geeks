#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};


bool checkcomplete(Node *root)
{
	if(!root)
		return true;

	queue<Node*> q;
	q.push(root);
	bool found=false;
	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if(found && (temp->left || temp->right))
			return false;
		if(temp->left && !temp->right || !temp->left && !temp->right)
			found=true;
		if(temp->right && !temp->left)
			return false;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	return true;
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->right = new Node(6);
    root->right->left = new Node(6); 
	cout<<checkcomplete(root)<<endl;

	return 0;
}