#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void toDLL(Node *root,Node *&prev,Node *&head,Node *&tail)
{
	if(!root)
		return;
	toDLL(root->left,prev,head,tail);
	if(prev==NULL)
	{
		prev = root;
		head=root;
		tail=root;
	}
	else
	{
		prev->right = root;
		root->left = prev;
		tail = root;
		prev = prev->right;
	}
	toDLL(root->right,prev,head,tail);
}

int countPairs(Node *root1,Node *root2,int sum)
{
	Node *head1,*head2,*tail1,*tail2,*prev=NULL;
	toDLL(root1,prev,head1,tail1);
	prev=NULL;
	toDLL(root2,prev,head2,tail2);

	Node *rt = head1,*lt=tail2;
	int count=0;
	while(rt and lt)
	{
		if(rt->data+lt->data==sum)
		{
			cout<<" ("<<rt->data<<" "<<lt->data<<") ";
			count++;
			rt =rt->right;
			lt = lt->left;
		}
		else if(rt->data+lt->data<sum)
			rt=rt->right;
		else
			lt=lt->left;
	}
	return count;
}

Node *insert(Node *root,int key)
{
	if(!root)
		return new Node(key);
	if(root->data==key)
		return root;
	if(root->data<key)
		root->right = insert(root->right,key);
	else
		root->left = insert(root->left,key);
	return root;
}

int main(int argc, char const *argv[])
{
	Node* root1 = NULL; 
    root1 = insert(root1, 8); 
    root1 = insert(root1, 10); 
    root1 = insert(root1, 3); 
    root1 = insert(root1, 6); 
    root1 = insert(root1, 1); 
    root1 = insert(root1, 5); 
    root1 = insert(root1, 7); 
    root1 = insert(root1, 14); 
    root1 = insert(root1, 13); 
  
    // second BST 
    Node* root2 = NULL; 
    root2 = insert(root2, 5); 
    root2 = insert(root2, 18); 
    root2 = insert(root2, 2); 
    root2 = insert(root2, 1); 
    root2 = insert(root2, 3); 
    root2 = insert(root2, 4); 
  
    int sum = 10; 
   	countPairs(root1, root2, sum); 
	return 0;
}