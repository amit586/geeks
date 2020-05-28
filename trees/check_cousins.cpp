// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node{
  ll data;
  Node *left,*right;
};
*/
bool isCousins(Node *root, int x, int y)
{
   queue<Node*> q;
   q.push(root);
   int level=0;
   while(!q.empty())
   {
       int l = q.size();
       int lx,px,ly,py;
       lx=ly=-1;
       px=py=-1;
       while(l)
       {
           Node *temp = q.front();
           if(temp->left)
           {
               q.push(temp->left);
               if(temp->left->data==x)
                    lx=level,px=temp->data;
               if(temp->left->data==y)
                    ly=level,py=temp->data;
           }
           
           if(temp->right)
           {
               q.push(temp->right);
               if(temp->right->data==x)
                    lx=level,px=temp->data;
                if(temp->right->data==y)
                    ly = level,py=temp->data;
           }
           
           q.pop();
           l--;
       }
       if(lx==ly && px!=py)
            return true;
       level++;
   }
   return false;
}