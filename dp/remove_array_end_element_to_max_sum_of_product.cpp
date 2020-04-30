#include <bits/stdc++.h>
#define MAX 300
using namespace std;

int dp[MAX][MAX];

int maxVal(vector<int> &v,int start,int end,int del)
{
	if(start==end)
	{
		dp[start][end]= v[start]*(del+1);
		return dp[start][end];
	}
	else if(dp[start][end]!=-1)
		return dp[start][end];
	else
	{
		dp[start][end]=max(v[start]*(del+1)+maxVal(v,start+1,end,del+1),v[end]*(del+1)+maxVal(v,start,end-1,del+1));
		return dp[start][end];
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
		vector<int> v(n);
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<maxVal(v,0,n-1,0)<<endl;
	}
	return 0;
}