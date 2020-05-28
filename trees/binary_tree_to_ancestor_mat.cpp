#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};



void constructMatrix(int anc[][MAX],Node *root,int N)
{
	if(!root)
		return ;

	if(root->left)
	{
		anc[root->data][root->left->data]=1;
		constructMatrix(anc,root->left,N);
	}

	if(root->right)
	{
		anc[root->data][root->right->data]=1;
		constructMatrix(anc,root->right,N);
	}

	if(root->left||root->right)
	{
		for(int i=0;i<N;i++)
		{
			if(root->left && anc[root->left->data][i]==1)
				anc[root->data][i]=1;
			if(root->right && anc[root->right->data][i]==1)
				anc[root->data][i]=1;
		}
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

int main(int argc, char const *argv[])
{
	int tc;
	tc=1;
	while(tc--)
	{
		
		// string inp;
		// getline(cin,inp);
		int N=6;
		Node *root=new Node(5);
		root->left = new Node(1);
		root->right = new Node(2);
		root->left->left = new Node(0);
		root->left->right = new Node(4);
		root->right->left = new Node(3);
		int anc[N][MAX];
		constructMatrix(anc,root,N);

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<anc[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}