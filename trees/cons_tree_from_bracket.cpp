#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};


Node *buildTree(string &str,int s,int e)
{
	if(e<=s)
		return NULL;
	Node *root = new Node(stoi(str[s]));
	if(e-s<=2 || str[s+1]==')')
		return root;
	int s1,s2,e1,e2;
	s1 = s+2;
	e1 = s+2+1;
	queue<char> q;
	q.push('(')
	while(!q.empty())
}

void inorder(Node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string str;
		getline(cin,str);
		Node *root = buildTree(str,0,str.size()-1);
		preorder(root);
	}
	return 0;
}