// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
Node *buildTree(int in[], int post[], int n) {
    if(n<=0)
        return  NULL;
    Node *root = new Node(post[n-1]);
    if(n==1)
        return root;
    int ri = 0;;
    while(post[n-1]!=in[ri])
        ri++;
    if(ri!=0)
        root->left = buildTree(in,post,ri);
    if(ri!=n-1)
        root->right = buildTree(in+ri+1,post+ri,n-ri-1);
    return root;
}
