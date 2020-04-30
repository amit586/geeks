// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printAllDups(Node* root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
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
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}// } Driver Code Ends
//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
 string findDup(Node *root,unordered_map<string,int> &hash,vector<int> &ans)
 {
    if(!root)
      return "";
    string st;
    st+="(";
    st+=findDup(root->left,hash,ans);
    st+=root->data;
    st+=findDup(root->right,hash,ans);
    st+=")";

    if(hash[st]==1)
      ans.push_back(root->data);
    hash[st]++;
    return st;
 }


void printAllDups(Node* root)
{
    vector<int> ans;
    unordered_map<string,int> hash;
    findDup(root,hash,ans);
    sort(ans.begin(),ans.end());
    if(ans.size()>0)
      for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    else
      cout<<-1;
}