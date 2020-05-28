#include <bits/stdc++.h>
using namespace std;

class  Node
{
public:
	int data;
	 Node *left,*right;
	 Node(int x):data(x),left(NULL),right(NULL){};
};

void merge( Node *&root1, Node *&root2)
{
	if(!root1 && !root2)
		return ;
	if(root1 && root2)
	{
		root1->data+=root2->data;
		merge(root1->left,root2->left);
		merge(root1->right,root2->right);
		return ;
	}

	if(!root1 && root2)
	{
		root1=root2;
		return;
	}
}

void inorder( Node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(int argc, char const *argv[])
{
	 /* Let us construct the first Binary Tree 
            1 
          /   \ 
         2     3 
        / \     \ 
       4   5     6 
    */
  
	 Node *root1 = new Node(1); 
    root1->left = new Node(2); 
    root1->right = new Node(3); 
    root1->left->left = new Node(4); 
    root1->left->right = new Node(5); 
    root1->right->right = new Node(6); 
  
    /* Let us construct the second Binary Tree 
           4 
         /   \ 
        1     7 
       /     /  \ 
      3     2    6   */
     Node *root2 = new Node(4); 
    root2->left = new Node(1); 
    root2->right = new Node(7); 
    root2->left->left = new Node(3); 
    root2->right->left = new Node(2); 
    root2->right->right = new Node(6); 
    merge(root1,root2);
    inorder(root1);
	
	return 0;
}