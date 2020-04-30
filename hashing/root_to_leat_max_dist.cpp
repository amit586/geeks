#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
	
};

int largestUinquePath(Node *root)
{
	if(!root)
		return -1;
	unordered_map<Node*,int> dist;
	queue<Node*> q;
	dist[root]=1;
	q.push(root);
	int mx=0;
	while(!q.empty())
	{
		Node *temp = q.front();
		
		if(temp->left)
			q.push(temp->left),dist[temp->left]=dist[temp]+1,mx=max(mx,dist[temp->left]);

		if(temp->right)
			q.push(temp->right),dist[temp->right]=dist[temp]+1,mx=max(mx,dist[temp->right]);

		q.pop();
	}
	return mx;

}

int main(int argc, char const *argv[])
{
// Create binary tree shown in above figure 
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); 
  
    cout << largestUinquePath(root) << endl; 
  

	return 0;
}