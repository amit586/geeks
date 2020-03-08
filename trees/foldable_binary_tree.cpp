#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int n)
	{
		int data=n;
		left=NULL;
		right=NULL;
	}
};

Node* buildTree(string str)
{
	if(str.length()==0 || str[0]=='N')
		return NULL;
	vector<string> tr;
	istringstream iss(str);
	for(string str; iss>>str;)
		tr.push_back(str);
	cout<<stoi(tr[0]);
	Node *root=new Node(stoi(tr[0]));
	queue <Node *> q;
	q.push(root);
	int i=1;
	while(!q.empty() && i<tr.size())
	{
		Node *temp = q.front();
		q.pop();
		if(tr[i]!="N")
		{
			cout<<stoi(tr[i]);
			temp->left = new Node(stoi(tr[i]));
			q.push(temp->left);
		}
		i++;
		if(i>=tr.size())
			break;
		if(tr[i]!="N")
		{
			cout<<stoi(tr[i]);
			temp->right = new Node(stoi(tr[i]));
			q.push(temp->right);
		}
		i++;

	}
	return root;

}

void traverse(Node *root)
{
	if(root==NULL)
		return ;
	traverse(root->left);
	cout<<root->data<<endl;
	traverse(root->right);
}

int main(int argc, char const *argv[])
{
	int tc;
	tc=1;	
	//scanf("%d",&tc);
	while(tc--)
	{
		string treeString;
		getline(cin,treeString);
		Node *root = buildTree(treeString);
		traverse(root);

	}

	return 0;
}