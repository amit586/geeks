#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};

void findPostOrder(int pre[],int n,int min,int max,int &preIndex)
{
	if(preIndex==n)
		return;
	if(pre[preIndex]<min || pre[preIndex]>max)
		return;
	int val = pre[preIndex];
	++preIndex;
	findPostOrder(pre,n,min,val,preIndex);
	findPostOrder(pre,n,val,max,preIndex);
	cout<<val<<" ";

}

int main(int argc, char const *argv[])
{
	int pre[] = { 40, 30, 35, 80, 100 }; 
	int n  = sizeof(pre)/sizeof(pre[0]);
	int preIndex =0;
	findPostOrder(pre, n,INT_MIN,INT_MAX,preIndex);
	return 0;
}