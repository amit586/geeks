#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x)
	{
		data = x;
		left=right=NULL;
	}
};

void specific_level_order_traversal(Node *root)
{
	queue <Node *> q;
	if(!root)
		return;
	vector <int> v;
	v.push_back(root->data);
	
	q.push(root->left);
	q.push(root->right);
	while(!q.empty())
	{
		Node *temp1 , *temp2 ;
		temp1 = q.front();
		q.pop();
		temp2 = q.front();
		q.pop();

		// cout<<temp1->data<<" "<<temp2->data<<' ';
		v.push_back(temp1->data);
		v.push_back(temp2->data);

		if(temp1->left)
			q.push(temp1->left);
		if(temp2->right)
			q.push(temp2->right);
		if(temp1->right)
			q.push(temp1->right);
		if(temp2->left)
			q.push(temp2->left);

	}
	// for(auto in: v)
	// 	cout<<in<<" ";
	// cout<<endl;

	int n = log2(v.size()+1);
	while(n>0)
	{
		for(int i=pow(2,n-1)-1;i<pow(2,n)-1;i++)
			cout<<v[i]<<" ";
		n--;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node *root =  new Node(1);
	root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
  
    root->left->left->left = new Node(8); 
    root->left->left->right = new Node(9); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(11); 
    root->right->left->left = new Node(12); 
    root->right->left->right = new Node(13); 
    root->right->right->left = new Node(14); 
    root->right->right->right = new Node(15); 
  
    root->left->left->left->left = new Node(16); 
    root->left->left->left->right = new Node(17); 
    root->left->left->right->left = new Node(18); 
    root->left->left->right->right = new Node(19); 
    root->left->right->left->left = new Node(20); 
    root->left->right->left->right = new Node(21); 
    root->left->right->right->left = new Node(22); 
    root->left->right->right->right = new Node(23); 
    root->right->left->left->left = new Node(24); 
    root->right->left->left->right = new Node(25); 
    root->right->left->right->left = new Node(26); 
    root->right->left->right->right = new Node(27); 
    root->right->right->left->left = new Node(28); 
    root->right->right->left->right = new Node(29); 
    root->right->right->right->left = new Node(30); 
    root->right->right->right->right = new Node(31);
    cout << "Specific Level Order traversal of binary "
        "tree is \n"; 
    specific_level_order_traversal(root); 

    cout<<endl<<"16 31 17 30 18 29 19 28 20 27 21 26 22 25 23 24 8 15 9 14 10 13 11 12 4 7 5 6 2 3 1"<<endl;
	return 0;
}