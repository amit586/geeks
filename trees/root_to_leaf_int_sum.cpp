#include <bits/stdc++.h>
using namespace std;

class  Node
{
public:
	 int data;
	 Node *left,*right;
	 Node(int x):data(x),left(NULL),right(NULL){};
};

void total( Node *root,int &sum,string number)
{
	if(!root)
		return ;
	if(root->left==NULL && root->right==NULL)
	{
		number+=(char)root->data+'0';
		sum+=stoi(number);
		return;
	}
	number+=(char)root->data+'0';
	total(root->left,sum,number);
	total(root->right,sum,number);
}

int main(int argc, char const *argv[])
{
	Node *root = new Node(6);  
    root->left = new Node(3);  
    root->right = new Node(5);  
    root->left->left = new Node(2);  
    root->left->right = new Node(5);  
    root->right->right = new Node(4);  
    root->left->right->left = new Node(7);  
    root->left->right->right = new Node(4); 
    int sum=0;
    total(root,sum,"");
    cout<<sum<<endl;
	return 0;
}