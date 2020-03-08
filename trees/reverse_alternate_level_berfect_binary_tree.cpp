// C++ program to reverse alternate levels of a binary tree 
#include<bits/stdc++.h> 
#define MAX 100 
using namespace std; 
  
// A Binary Tree node 
class Node 
{ 
public:
    char data; 
    Node *left, *right; 
    Node(char x)
    {
    	data = x;
    	left=right=NULL;
    }
};

// The main function to reverse alternate nodes of a binary tree 
void reverseAlternate(Node *root) 
{ 
 	if(root==NULL)
        return ;
    queue <Node *> q1;
    queue <Node *> q2;
    vector <Node * > v;
    q2.push(root);
    while((!q1.empty()) || (!q2.empty()))
    {
        while(!q2.empty())
        {
            Node *temp = q2.front();
            q2.pop();
            if(temp->left)
                q1.push(temp->left);
            if(temp->right)
                q1.push(temp->right);
        }
        
        while(!q1.empty())
        {
            Node *temp = q1.front();
            v.push_back(temp);
            q1.pop();
            if(temp->left)
                q2.push(temp->left);
            if(temp->right)
                q2.push(temp->right);
        }

        int l = v.size();
        for(int i=0;i<l/2;i++)
        {
            int temp = v[i]->data;
            v[i]->data = v[l-1-i]->data;
            v[l-1-i]->data = temp;
            // cout<<v[i]->data<<" ";
        }
        v.clear();
    }
} 
  
// A utility function to print indorder traversal of a 
// binary tree 
void printInorder(Node *root) 
{ 
    if (root == NULL) return; 
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    Node *root = new Node('a'); 
    root->left = new Node('b'); 
    root->right = new Node('c'); 
    root->left->left = new Node('d'); 
    root->left->right = new Node('e'); 
    root->right->left = new Node('f'); 
    root->right->right = new Node('g'); 
    root->left->left->left = new Node('h'); 
    root->left->left->right = new Node('i'); 
    root->left->right->left = new Node('j'); 
    root->left->right->right = new Node('k'); 
    root->right->left->left = new Node('l'); 
    root->right->left->right = new Node('m'); 
    // root->right->right->left = new Node('n'); 
    // root->right->right->right = new Node('o'); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    reverseAlternate(root); 
  
    cout << "\n\nInorder Traversal of modified tree\n"; 
    printInorder(root); 
  
    return 0; 
}