#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void lower_bound(Node *root,int &ans,int key)
{
	if(!root)
		return ;
	if(root->data==key)
	{
		ans = key;
		return ;
	}
	else if(root->data<key)
	{
		ans = root->data;
		lower_bound(root->right,ans,key);
	}
	else
		lower_bound(root->left,ans,key);

}

Node *insert(Node *root,int key)
{
	if(!root)
		return new Node(key);

	if(root->data==key)
		return root;
	if(root->data<key)
		root->right=insert(root->right,key);
	else
		root->left = insert(root->left,key);
	return root;
}

int main(int argc, char const *argv[])
{
	int N = 50; 
    Node* root =insert(root, 5); 
    insert(root, 2); 
    insert(root, 1); 
    insert(root, 3); 
    insert(root, 12); 
    insert(root, 9); 
    insert(root, 21); 
    insert(root, 19); 
    insert(root, 25); 
  
    int ans=-1;
    lower_bound(root,ans,4);
    cout<<ans<<endl;
	return 0;
}