#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

void inorder(Node *root,vector<int> &v,int &i)
{
	if(!root)
		return;
	inorder(root->left,v,i);
	if(i==0)
		v[i]=root->data;
	else
		v[i]=root->data+v[i-1];
	i++;
	inorder(root->right,v,i);
}

void convert(Node *root,int &i,vector<int> &pref)
{
	if(!root or i>=pref.size())
		return;
	convert(root->left,i,pref);
	root->data = pref[pref.size()-1]-pref[i++];
	convert(root->right,i,pref);

}

void in(Node *root)
{
	if(!root)
		return ;
	in(root->left);
	cout<<root->data<<" ";
	in(root->right);
}


int main(int argc, char const *argv[])
{
	Node *root = new Node(11); 
    root->left = new Node(2); 
    root->right = new Node(29); 
    root->left->left = new Node(1); 
    root->left->right = new Node(7); 
    root->right->left = new Node(15); 
    root->right->right = new Node(40); 
    root->right->right->left = new Node(35);
    in(root);
    cout<<endl;
    int i=0;
    vector<int> v(8);
    inorder(root,v,i);
    // for(int i=0;i<8;i++)
    // 	cout<<v[i]<<" ";
    // cout<<endl;
    i=0;
    convert(root,i,v);
    in(root);


	return 0;
}