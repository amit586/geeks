#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void duplicate(Node *root,vector<int> &hash,bool &ans)
{
	if(!root)
		return ;
	hash[root->data]++;
	if(hash[root->data]>1)
	{
		ans=true;
		return;
	}
	duplicate(root->left,hash,ans);
	duplicate(root->right,hash,ans);
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(2); 
    root->left->left = new Node(3); 
	bool ans=false;
	std::vector<int> hash(10000);
	duplicate(root,hash,ans);
	cout<<ans<<endl;
	return 0;
}