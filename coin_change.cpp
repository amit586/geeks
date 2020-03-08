#include <bits/stdc++.h>
#define MAX 301
using namespace std;
unsigned long long dp[MAX][MAX];

unsigned long long c(int n,int m,int arr[])
{
	if(dp[n][m]!=0)
		return dp[n][m];
	if(n==m)
	{
		dp[n][m]=1;
		return 1;
	}
	if(n<m || n<0)
	{
		dp[n][m]=0;
		return 0;
	}
	else
	{
		dp[n][m]=c(n,m-1,arr)+c(n-arr[m],m,arr);
		return dp[n][m];
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int m;
		cin>>m;
		int arr[m];
		memset(dp,0,sizeof(dp));
		for (int i = 0; i < m; ++i)
			cin>>arr[i];
		int n;
		cin>>n;
		cout<<c(n,m-1,arr)<<endl;
	}
	return 0;
}