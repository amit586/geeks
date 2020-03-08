#include <bits/stdc++.h>
#define MAX 500
using namespace std;

int snake(int arr[][MAX],int n,int m)
{
	int dp[n][m];
	memset(dp,0,sizeof(dp));
	int mx = INT_MIN;
	for(int i=n-1;i>=0;i--)
	{
		for(int j = m-1;j>=0;j--)
		{
			dp[i][j]=1;
			if(j+1<m && abs(arr[i][j+1]-arr[i][j])==1)
				dp[i][j] = max(dp[i][j],dp[i][j+1]+1);
			if(i+1<n && abs(arr[i][j]-arr[i+1][j])==1)
				dp[i][j] = max(dp[i][j],1+dp[i+1][j]);
			mx = max(dp[i][j],mx);
		}
	}
	return mx;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		int arr[n][MAX];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		}

		cout<<snake(arr,n,m)<<endl; 
	}
	return 0;
}