#include <bits/stdc++.h>
using namespace std;

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

int sizeAndHeight(Node *root , int &size)
{
	if(!root)
		return 0;
	int l = sizeAndHeight(root->left,size);
	int r = sizeAndHeight(root->right,size);
	size++;
	return 1+max(l,r);
}

double density(Node *root)
{	
	int size = 0;
	int height = sizeAndHeight(root,size);
	return ((double)(size)/height);
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
  
    printf("Density of given binary tree is %f", 
           density(root)); 
	return 0;
}