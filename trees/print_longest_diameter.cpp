#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};	
};

int printM(Node *root,int h,int hm)
{
	if(!root)
		return h;
	int l = printM(root->left,h+1,hm);
	int r = printM(root->right,h+1,hm);
	if(max(l,r)==hm)
	{
		cout<<root->data<<" ";
	}
	return max(l,r);
}

int getMx(Node *root,Node **mx,int &ans,int &hl,int &hr)
{
	if(!root)
		return 0;
	int l = getMx(root->left,mx,ans,hl,hr);
	int r = getMx(root->right,mx,ans,hl,hr);
	if(l+r+1>ans)
	{
		ans = l+r+1;
		hl = l,hr=r;
		*mx = root;
	}
	return 1+max(l,r);
}

void printDia(Node *root)
{
	Node *mx=NULL;
	int ans=0,hl=0,hr=0;
	getMx(root,&mx,ans,hl,hr);
	cout<<"hl: "<<hl<<" hr: "<<hr<<endl;
	printM(mx->left,0,hl);
	cout<<endl<<mx->data<<endl;
	printM(mx->right,0,hr);
}

int main(int argc, char const *argv[])
{
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6); 
    root->left->right->right = new Node(7); 
    root->left->left->right = new Node(8); 
    root->left->left->right->left = new Node(9);
    printDia(root);
	return 0;
}