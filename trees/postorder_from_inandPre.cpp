#include <bits/stdc++.h>
using namespace std;

int search(int arr[],int x,int n)
{
	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]==x)
		{
			ans = i;
			break;
		}
	}
	return ans;
}

void printPostorder(int in[],int pre[],int n)
{
	int root = search(in,pre[0],n);
	if(root!=0)
		printPostorder(in,pre+1,root);
	if(root!=n-1)
		printPostorder(in+root+1,pre+root+1,n-root-1);
	cout<<in[root]<<" ";
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int in[n],pre[n];
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin>>pre[i];
			in[i]=pre[i];
		}
		sort(in,in+n);
		printPostorder(in,pre,n);
		cout<<endl;
	}
	return 0;
}