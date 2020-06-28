#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

vector<Node*> c(int start,int end)
{
	vector<Node*> trees;
	if(start>end)
	{
		trees.push_back(NULL);
		return trees;
	}	

	for(int i=start;i<=end;i++)
	{
		vector<Node*> L = c(start,i-1);
		vector<Node*> R = c(i+1,end);

		for(int j=0;j<L.size();j++)
		{
			for(int k=0;k<R.size();k++)
			{
				Node *root = new Node(i);
				root->left = L[j];
				root->right = R[k];
				trees.push_back(root);
			}
		}
	}
	return trees;
}

void inorder(Node *root)
{
	if(!root)
		return ;
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<Node*> trees = c(1,n);
	for(int i=0;i<trees.size();i++)
		inorder(trees[i]),cout<<endl;
	cout<<trees.size()<<endl;
	return 0;
}