#include <bits/stdc++.h>
using namespace std;

class  Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

int count(Node *root,int n1,bool size)
{
	int sz = 0;
	Node *curr = root;
	while(curr)
	{
		if(curr->left==NULL)
		{
			
			if(size)
				sz++,cout<<curr->data<<" ";
			else
			{
				n1--;
				cout<<n1<<" "<<curr->data<<endl;
				if(n1==0)
					sz=curr->data;
			}
			curr = curr->right;
		}
		else
		{
			Node *pre = curr->left;
			while(pre and pre->right and pre->right!=curr)
				pre = pre->right;
			if(pre->right==NULL)
			{
				pre->right = curr;
				curr = curr->left;
			}
			else
			{
				pre->right = NULL;
				if(size)
					sz++,cout<<curr->data<<" ";
				else
				{
					n1--;
					cout<<n1<<" "<<curr->data<<endl;
					if(n1==0)
						sz=curr->data;
				}
				curr = curr->right;
			}
		}
	}
	return sz;
}
int median(Node *root)
{
//int count(Node *root,int n1, int n2,bool find1,bool find2,bool size)
	///cout<<root->data<<endl;
	int sz = count(root,100,true);
	cout<<"size: "<<sz<<endl;
	return count(root,(sz+1)/2,false);				
}

void inorder(Node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node *insert(Node *root,int key)
{
	if(!root)
		return new Node(key);
	if(root->data==key)
		return root;
	if(root->data<key)
		root->right =insert(root->right,key);
	else
		root->left = insert(root->left,key);
	return root; 
}

int main(int argc, char const *argv[])
{
	Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
    insert(root, 90);
    insert(root,100); 
    
    insert(root,110);
    // insert(root,120);
    //inorder(root);
    //cout<<endl;
    //inorder(root);
    cout<<median(root)<<endl;
	return 0;
}