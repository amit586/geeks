// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

int *extractLevel(int inorder[],int s,int e,int levelOrder[],int n)
{
    int *ans=new int[e-s+1],j=0;
    unordered_set<int> m;
    for(int i=s;i<=e;i++)
        m.insert(inorder[i]);

    for(int i=0;i<n;i++)
        if(m.find(levelOrder[i])!=m.end())
            ans[j++]=levelOrder[i];
   return ans;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    if(n==0)
        return NULL;
    Node *root = new Node(levelOrder[0]);
    if(n==1)
        return root;
    int part = 0;
    while(inorder[part]!=levelOrder[0])
        part++;
    int *lt = extractLevel(inorder,iStart,part-1,levelOrder,n);
    int *rt = extractLevel(inorder,part+1,iEnd,levelOrder,n);

    root->left = buildTree(inorder,lt,iStart,part-1,part-iStart);
    root->right = buildTree(inorder,rt,part+1,iEnd,iEnd-part);
    return root;
}