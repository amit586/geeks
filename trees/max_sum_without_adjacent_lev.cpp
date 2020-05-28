#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

int maxLevel(Node *root)
{
	
	// stored level sum of different level on vector ls[]
	vector<int> ls(100,0);

	// l = level of traversal
	int l=0;


	// level order traversal
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		int sz=q.size();
		int sum=0; // stores sum of all the elements of a level
		while(sz--)
		{
			Node *temp=q.front();
			sum+=temp->data;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			q.pop();
		}
		ls[l]=sum;
		l++;
	}


	// using dp to find correct answer

	vector<int> inc(l,0),exc(l,0);
	inc[0]=ls[0];
	inc[1]=ls[1];
	exc[1]=max(0,inc[0]);
	for(int i=2;i<l;i++)
	{
		inc[i]=ls[i]+max(exc[i-1],inc[i-2]);
		exc[i] = max(exc[i-1],inc[i-1]);
	}
	return max(inc[l-1],exc[l-1]);
}

int main(int argc, char const *argv[])
{
	
	Node* root = new Node(1);  
	root->left = new Node(2);  
	root->right = new Node(3);  
	root->right->left = new Node(4);  
	root->right->left->right = new Node(5);  
	root->right->left->right->left = new Node(6);  
  
    cout<<maxLevel(root)<<endl;
	return 0;
}