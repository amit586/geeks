#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

int dist(Node *root,int key)
{
	if(!root)
		return INF;
	if(root->data==key)
		return 0;
	if(root->data<key)
		return 1+dist(root->right,key);
	else
		return 1+dist(root->left,key);
}

Node *insert(Node *root,int key)
{
	if(!root)
		return new Node(key);
	if(root->data==key)
		return root;
	if(key<root->data)
		root->left = insert(root->left,key);
	else
		root->right = insert(root->right,key);
	return root;
}

int samepth(Node *root,int key1,int key2)
{
	if(key2<root->data and key1<root->data)
		return samepth(root->left,key1,key2);
	if(key1>root->data and key2>root->data)
		return samepth(root->right,key1,key2);
	return dist(root,key1)+dist(root,key2);
}

int main(int argc, char const *argv[])
{
	Node* root = NULL; 
    root = insert(root, 20); 
    insert(root, 10); 
    insert(root, 5); 
    insert(root, 15); 
    insert(root, 30); 
    insert(root, 25); 
    insert(root, 35); 
    int a = 5, b = 35; 
    cout << samepth(root,a,b)<<endl; 	
	return 0;
}