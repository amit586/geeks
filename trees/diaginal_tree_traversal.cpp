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

void populateMap(Node *root,int l ,map <int , vector<int>> &m)
{
	if(!root)
		return;
	m[l].push_back(root->data);
	populateMap(root->left,l+1,m);
	populateMap(root->right,l,m);
	
}

void diagonalPrintLineByLine(Node *root)
{
	map <int ,vector<int>> m;
	populateMap(root , 0, m);
	for (int i = 0; i < m.size(); ++i)
	{
		for(auto itr :m[i])
			cout<<itr<<" ";
		cout<<endl;
	}

}
void diagonalPrint(Node *root)
{
	if(!root)
		return;
	queue <Node *> q;
	Node *temp = root;
	
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{

		temp = q.front();
		q.pop();
		if(temp)
		{
			while(temp)
			{
				cout<<temp->data<<" ";
				if(temp->left)
					q.push(temp->left);
				temp=temp->right;
			}
		}
		else
		{
			if(q.empty())
				return;
			cout<<endl;
			q.push(NULL);
		}
	}
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(9); 
    root->left->right = new Node(6); 
    root->right->left = new Node(4); 
    root->right->right = new Node(5); 
    root->right->left->right = new Node(7); 
    root->right->left->left = new Node(12); 
    root->left->right->left = new Node(11); 
    root->left->left->right = new Node(10);
    diagonalPrint(root);
	return 0;
}