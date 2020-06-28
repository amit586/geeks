// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node *left;
	struct node *right;
	
	node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

bool isTripletPresent(node *root);

node* insert(node* root, int key)
{
    if (root == NULL)
       return (new node(key));
    if (root->key > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node* root = NULL;
		while(n--){
			int a;
			cin>>a;
			root = insert(root, a);
		}
		if (isTripletPresent(root))
			printf("1\n");
		else
			printf("0\n");
	}
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct node
{
    int key;
    struct node *left;
    struct node *right;
};
*/

void fill(node *root,vector<int> &in)
{
	if(!root)
		return;
	fill(root->left,in);
	in.push_back(root->key);
	fill(root->right,in);
}

bool search(node *root,int k1,int k2)
{
	if(!root)
		return false;
	if(root->key==(-k1 -k2) and !(root->key==k1 or root->key==k2))
		return true;
	if(root->key>(-k1-k2))
		return search(root->left,k1,k2);
	else 
		return search(root->right,k1,k2);
}

bool isTripletPresent(node *root)
{
	vector<int> in;
	fill(root,in);
	for(int i=0;i<in.size();i++)
	{
		for(int j=i+1;j<in.size();j++)
			if(search(root,in[i],in[j]))
				return true;
	}
	return false;
}