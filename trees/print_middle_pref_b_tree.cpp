#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void printMiddle(Node *a,Node *b)
{
	if(!a || !b)
		return ;
	if(!b->left && !b->right)
		cout<<a->data<<" ";
	if(b->left && b->left->left)
		printMiddle(a->left,b->left->left);
	if(b->right && b->right->right)
		printMiddle(a->right,b->right->right);
}

int main(int argc, char const *argv[])
{
	 Node* n1 = new Node(1); 
    Node* n2 = new Node(2); 
    Node* n3 = new Node(3); 
    Node* n4 = new Node(4); 
    Node* n5 = new Node(5); 
    Node* n6 = new Node(6); 
    Node* n7 = new Node(7); 
  
    n2->left = n4; 
    n2->right = n5; 
    n3->left = n6; 
    n3->right = n7; 
    n1->left = n2; 
    n1->right = n3; 
    printMiddle(n1,n1);
	return 0;
}