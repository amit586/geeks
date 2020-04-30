// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};


Node *cloneTree(Node *);
int printInorder(Node* a,Node *b)
{
    if ((a==NULL and b==NULL) or (a->random==NULL and b->random==NULL))
        return 1;




    if(a->random->data == b->random->data and printInorder(a->left,b->left) and printInorder(a->right,b->right))
        return 1;
    return false;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }

     Node *t = cloneTree(root);
      if(t==root)
        cout<<0<<endl;
     else
     cout<<printInorder(root,t);
     cout<<endl;
  }
  return 0;
}



Node* cloneTree(Node* tree);
// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */
Node* cloneTree(Node* tree)
{
  if(tree==NULL)
    return NULL;

  Node *ans = new Node(tree->data);
  stack<Node*> s1;
  stack<Node*> s2;
  s1.push(tree);
  s2.push(ans);
  unordered_map<int,Node*> hash;

  while(!s1.empty())
  {
    Node *temp1 = s1.top();
    Node *temp2 = s2.top();

    s1.pop(),s2.pop();

    if(temp1->left)
    {
      s1.push(temp1->left);
      temp2->left = new Node(temp1->left->data);
      s2.push(temp2->left);
    }
    
    if(temp1->right)
    {
      s1.push(temp1->right);
      temp2->right = new Node(temp1->right->data);
      s2.push(temp2->right);
    }

    hash[temp2->data]=temp2;    
  } 

  s1.push(tree);
  s2.push(ans);
  while(!s1.empty())
  {
    Node *temp1 = s1.top();
    Node *temp2 = s2.top();
    
    s1.pop(),s2.pop();

    if(temp1->random)
      temp2->random = hash[temp1->random->data];
    
    if(temp1->left)
          s1.push(temp1->left),s2.push(temp2->left);
    if(temp1->right)
          s1.push(temp1->right),s2.push(temp2->right);

  }
  return ans;

}
