#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*middle,*right;
	Node(int x):data(x),left(NULL),middle(NULL),right(NULL){};
};

class LNode
{
public:
	int data;
	LNode *prev,*next;
	LNode(int x):data(x),prev(NULL),next(NULL){};
};

void makeDLL(Node *root,LNode **tail,LNode**head)
{
	if(!root)
		return;

	if(*head==NULL)
	{
		*head = new LNode(root->data);
		*tail = *head;
	}
	else
	{
		(*tail)->next = new LNode(root->data);
		(*tail)->next->prev = (*tail);
		(*tail)=(*tail)->next;
	}
	makeDLL(root->left,tail,head);
	makeDLL(root->middle,tail,head);
	makeDLL(root->right,tail,head);
}

void PrintDll(LNode*head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}


int main(int argc, char const *argv[])
{
	Node* root = new Node(30); 
  
    root->left = new Node(5); 
    root->middle = new Node(11); 
    root->right = new Node(63); 
  
    root->left->left = new Node(1); 
    root->left->middle = new Node(4); 
    root->left->right = new Node(8); 
  
    root->middle->left = new Node(6); 
    root->middle->middle = new Node(7); 
    root->middle->right = new Node(15); 
  
    root->right->left = new Node(31); 
    root->right->middle = new Node(55); 
    root->right->right = new Node(65); 

    LNode *head = NULL,*tail=NULL;
    makeDLL(root,&tail,&head);
    PrintDll(head);
	return 0;
}