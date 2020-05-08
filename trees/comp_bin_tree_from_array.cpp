#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second

struct myhash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


using namespace std;

class Node{
public:
	int data;
	Node *left,*right;
	Node(int x):data(x),left(NULL),right(NULL){};
};

void inorder(Node *root)
{
	if(!root)
		return ;
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

Node *buildTree(vector<int> &v,int n,int i)
{
	if(i>=n)
		return NULL;
	Node *root = new Node(v[i]);
	root->left=buildTree(v,n,2*i+1);
	root->right=buildTree(v,n,2*i+2);
	return root;
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		Node * root = buildTree(v,n,0);
		//cout<<"build"<<endl;
		inorder(root);
		cout<<endl;
		
	}
	return 0;
}
