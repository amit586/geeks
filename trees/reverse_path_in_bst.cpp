#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void reverse(Node *root,int key,queue<int> &q)
{
	if(!root)
		return ;
	if(root->data==key)
	{
		q.push(root->data);
		root->data = q.front();
		q.pop();
		return;
	}
	else if(key<root->data)
	{
		q.push(root->data);
		reverse(root->left,key,q);
		root->data = q.front();
		q.pop();
	}
	else
	{
		q.push(root->data);
		reverse(root->right,key,q);
		root->data= q.front();
		q.pop();
	}
}

void inorder(Node *root)
{
	if(!root)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(int argc, char const *argv[])
{
	int k = 80; 
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
  
    cout << "Before Reverse :" << endl; 
    // print inoder traversal of the BST 
    inorder(root); 
  
    cout << "\n"; 
  	queue<int> q;
    // reverse path till k 
    reverse(root, k, q); 
      
    cout << "After Reverse :" << endl; 
  
    // print inorder of reverse path tree 
    inorder(root); 
	return 0;
}