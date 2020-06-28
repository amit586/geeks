#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};


void isPresent(Node *root,int &i,int seq[],int n,bool &ans)
{
	if(!root)
		return ;
	isPresent(root->left,i,seq,n,ans);
	if(seq[i]==root->data)
		i++;
	if(i==n)
		ans=true;
	isPresent(root->right,i,seq,n,ans);

}

Node *insert(Node *root,int key)
{
	if(!root)
		return new Node(key);
	if(key<root->data)
		root->left=insert(root->left,key);
	else
		root->right = insert(root->right,key);
}

int main(int argc, char const *argv[])
{
	struct Node* root = NULL; 
    root = insert(root, 8); 
    root = insert(root, 10); 
    root = insert(root, 3); 
    root = insert(root, 6); 
    root = insert(root, 1); 
    root = insert(root, 4); 
    root = insert(root, 7); 
    root = insert(root, 14); 
    root = insert(root, 13); 
  
    int seq[] = {4, 8,6, 14}; 
    int n = sizeof(seq)/sizeof(seq[0]); 
  	bool ans=false;
  	int i=0;
  	isPresent(root,i,seq,n,ans);
    ans? cout << "Yes" : 
                            cout << "No"; 
	return 0;
}