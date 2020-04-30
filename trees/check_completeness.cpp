#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

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


bool checkComp(Node *root)
{
	queue<pair<Node*,int>> q;
	q.push({root,0});
	int firstNull=INF;
	bool flag=true;
	while(!q.empty())
	{
		Node *temp=q.front().first;
		int i=q.front().second,l=-1,r=-1,lv=INF,rv=INF;
		
		if(!temp->left && firstNull==INF)
			firstNull=2*i+1;
		if(!temp->right && firstNull==INF)
			firstNull=2*i+2;

		if(temp->left)
			l=2*i+1,lv=temp->left->data,q.push({temp->left,l});
		if(temp->right)
			r=2*i+2,rv=temp->left->data,q.push({temp->right,r});
		
		if(l>firstNull||r >firstNull || lv<temp->data || rv<temp->data)	
			return false;
		q.pop();
	}
	return true;
}


int main(int argc, char const *argv[])
{
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(6);
	root->left->right=new Node(7);
	root->right->left=new Node(4);
	root->right->right=new Node(9);
	cout<<checkComp(root)<<endl;
	
	return 0;
}