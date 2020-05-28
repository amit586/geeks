#include <bits/stdc++.h>
#define INF 100000
#define f first
#define s second
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
	~Node();
	
};

int Level(Node *root,int val,int l,Node *parent,Node* &VParent)
{
	if(!root)
		return INF;
	if(root->data==val)
	{
		VParent=parent;
		return l;
	}
	return min(Level(root->left,val,l+1,root,VParent),Level(root->right,val,l+1,root,VParent));
}

void printCousin(Node *root,int child)
{

	Node *VParent = NULL;
	queue<pair<Node *,Node*>> q;
	q.push(make_pair(root,(Node*)NULL));
	int l = Level(root,child,0,NULL,VParent);
	cout<<"level "<<l<<endl;
	
	while(!q.empty())
	{
		int sz = q.size();
		while(sz)
		{
			sz--;
			Node *temp=q.front().f;
			Node *tempP = q.front().s;
			q.pop();
			if(l==0 && tempP!=VParent)
				cout<<temp->data<<" ";
			if(temp->left)
				q.push({temp->left,temp});
			if(temp->right)
				q.push({temp->right,temp});
		}
		l--;
	}

}
int main(int argc, char const *argv[])
{
	Node* n1 = new Node(1); 
    Node* n2 = new Node(2); 
    Node* n3 = new Node(3); 
    Node* n4 = new Node(4); 
    Node* n5 = new Node(5); 
    Node* n6 = new Node(6); 
    Node* n7 = new Node(7); 
  
    n2->left = n4; 
    n2->right = n5; 
    n3->left = n6; 
    n3->right = n7; 
    n1->left = n2; 
    n1->right = n3; 

	printCousin(n1,7);
	return 0;
}