#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Node
{
public:
	int data;
	Node * left,*right;
	Node(int x)
	{
		data = x;
		left=right=NULL;
	}
	
};

void preorder(Node *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void postorder(Node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}


vector <Node *> allTree(int arr[],int start, int end)
{
	vector<Node *> trees;
	if(start>end)
	{
		trees.pb(NULL);
		return trees;
	}

	for(int i = start ; i<=end;i++)
	{
		vector <Node *> lTree = allTree(arr,start,i-1);
		vector<Node *> rTree = allTree(arr,i+1,end);

		for(int k=0;k<lTree.size();k++)
		{
			for(int j=0;j<rTree.size();j++)
			{
				Node * root = new Node(arr[i]);
				root->left = lTree[k];
				root->right = rTree[j];
				trees.pb(root);
			}
		}
	}
	return trees;
}

int main(int argc, char const *argv[])
{
	int inord[] = {4,5,7,9,10,11,12,15};
	int end = sizeof(inord)/sizeof(inord[0])-1;
	std::vector<Node *> Trees = allTree(inord,0,end);
	for (int i = 0; i < Trees.size(); ++i)
	{	cout<<"preorder: ";
		preorder(Trees[i]);
		cout<<"  inorder: ";
		inorder(Trees[i]);
		cout<<"  postorder: ";
		postorder(Trees[i]);
		cout<<endl;
	}

	cout<<"Total = "<<Trees.size()<<endl;

	return 0;
}