#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void dSum(Node *root)
{
	queue<Node *> q;
	q.push(root);
	int level= 0;
	list<int> ds;
	while(!q.empty())
	{
		int sz = q.size();
		int sum=0;
		while(sz)
		{
			Node *temp = q.front();
			q.pop(),sz--;
			while(temp)
			{
				sum+=temp->data;
				if(temp->left)
					q.push(temp->left);
				temp = temp->right;
			}
		}
		ds.push_back(sum);
		level++;
	}

	for(auto it:ds)
		cout<<it<<endl;

}

int main(int argc, char const *argv[])
{
	Node *root = new Node(1); 
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
  	dSum(root);
	return 0;
}
