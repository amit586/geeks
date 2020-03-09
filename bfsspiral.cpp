// C program for recursive level order traversal in spiral form 
#include<bits/stdc++.h>
using namespace std;
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* Function protoypes */
void printGivenLevel(struct node* root, int level, int ltr); 
int height(struct node* node); 
struct node* newNode(int data); 
  
/* Function to print spiral traversal of a tree*/
void printSpiral(struct node* root) 
{
 	int h = height(root);
 	for(int i=1;i<=h;i++)
 	{
 		printGivenLevel(root,i,i%2);	
	}
	cout<<endl;
}
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level,int itr) 
{ 
    if (root == NULL) 
        return; 
        
    else if(level==1 && root)
    {
    	cout<<root->data<<" ";		
	}
	else
	{
		if(itr==1)
		{
			printGivenLevel(root->right,level-1,itr);
			printGivenLevel(root->left,level-1,itr);
		}
		else
		{
			printGivenLevel(root->left,level-1,itr);
			printGivenLevel(root->right,level-1,itr);
		}
	}
} 
  
/* Compute the "height" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int height(struct node* node) 
{ 
    if (node == NULL) 
        return 0; 
    else { 
       return 1+max(height(node->left),height (node->right)); 
    } 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
    malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    printf("Spiral Order traversal of binary tree is \n"); 
    printSpiral(root); 
  
    return 0; 
} 
