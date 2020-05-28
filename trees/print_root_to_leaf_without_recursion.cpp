#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

void printThisPath(Node *curr,unordered_map<Node*,Node*> &parent)
{
	while(parent.find(curr)!=parent.end())
	{
		cout<<curr->data<<" ";
		curr = parent[curr];
	}
	cout<<curr->data<<" "<<endl;
}

void printPath(Node *root)
{
	stack<Node *> s;
	s.push(root);
	unordered_map<Node *,Node*> parent;
	while(!s.empty())
	{
		Node *temp = s.top();
		s.pop();
		if(!temp->left && !temp->right)
			printThisPath(temp,parent);
		if(temp->right)
			s.push(temp->right),parent[temp->right]=temp;
		if(temp->left)
			s.push(temp->left),parent[temp->left]=temp;
	}

}

int main(int argc, char const *argv[])
{

	Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
  	printPath(root);
	return 0;
}