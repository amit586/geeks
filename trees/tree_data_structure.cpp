#include <iostream>
using namespace std;

class Node
{
public:
	Node *left,*right;
	int key;
	Node(int key)
	{
		this->key=key;
		left=NULL;
		right = NULL;
	}
	~Node();
	
};


int	main(int argc, char const *argv[])
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	cout<<root->key<<" "<<root->left->key<<" "<<root->right->key<<endl;
	return 0;
}