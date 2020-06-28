#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

void toPostorder(int pre[],int n,int &i,int mn,int mx)
{
	if(i>=n)
		return;
	if(pre[i]<mx and pre[i]>mn)
	{
		int md = pre[i];
		i++;
		toPostorder(pre,n,i,mn,md);
		toPostorder(pre,n,i,md,mx);
		cout<<md<<" ";
	}
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int pre[n];
		for(int i=0;i<n;i++)
			cin>>pre[i];
		int i=0;
		toPostorder(pre,n,i,-INF,INF);
	}
	return 0;
}