// { Driver Code Starts
//Initial Template for C++
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

void zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        zigZagTraversal(root);
        cout<<endl;
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

// } Driver Code Ends

//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function 
// Function takes a single argument as input
// the root of the binary tree
// print a new line after each test case
void zigZagTraversal(Node* root)
{
	if(!root)
        return;
    stack<Node*> thisL,nextL;
    thisL.push(root);
    bool odd=true;
    while(!thisL.empty() || !nextL.empty())
    {
        if(odd)
        {
            while(!thisL.empty())
            {  
                Node *temp=thisL.top();
                cout<<temp->data<<" ";
                thisL.pop();
                if(temp->left)
                    nextL.push(temp->left);
                if(temp->right)
                    nextL.push(temp->right);
            }
            odd=false;
        }
        else
        {
            while(!nextL.empty())
            {
                Node *temp = nextL.top();
                cout<<temp->data<<" ";
                nextL.pop();
                if(temp->right)
                    thisL.push(temp->right);
                if(temp->left)
                    thisL.push(temp->left);
            }
            odd=true;
        }
    }
}