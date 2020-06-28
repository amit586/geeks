#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void storeIn(Node *root,int &i,std::vector<int> &in)
{
	if(!root)
		return ;
	storeIn(root->left,i,in);
	in.push_back(root->data);
	storeIn(root->right,i,in);

}

bool check(Node *root1,Node *root2)
{
	vector<int> in1,in2;
	int i1=0,i2=0;
	storeIn(root1,i1,in1);
	storeIn(root2,i2,in2);
	if(in1.size()!=in2.size())
		return false;
	for (int i = 0; i < in1.size(); ++i)
	{
		if(in1[i]!=in2[i])
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	/* code */
	Node* root1 = new Node(15); 
    root1->left = new Node(10); 
    root1->right = new Node(20); 
    root1->left->left = new Node(5); 
    root1->left->right = new Node(12); 
    root1->right->right = new Node(25); 
      
    // Second BST 
    Node* root2 = new Node(15); 
    root2->left = new Node(12); 
    root2->right = new Node(20); 
    root2->left->left = new Node(5); 
    root2->left->left->right = new Node(10); 
    root2->right->right = new Node(25); 
    cout<<check(root1,root2)<<endl;
	return 0;
}