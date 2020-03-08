#include<bits/stdc++.h>
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

void reverseLevelOrder(Node *root)
{
	if(root)
	{
		stack <Node *> s;
		queue <Node *> q;
		q.push(root);
		while(!q.empty())
		{
			Node *temp = q.front();
			// cout<<temp->data<<" ";
			s.push(temp);
			q.pop();
			
			if(temp->right)
				q.push(temp->right);
			
			if(temp->left)
				q.push(temp->left);
			
		}

		while(!s.empty())
		{
			cout<<s.top()->data<<" ";
			s.pop();
		}
	}
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
    root->left->left = new Node(4);  
    root->left->right = new Node(5);  
  
    cout << "Level Order traversal of binary tree is \n";  
    reverseLevelOrder(root);  
  
    return 0; 
	return 0;
}