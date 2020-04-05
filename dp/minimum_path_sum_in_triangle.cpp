#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int minPath(int tri[][MAX],int n)
{
	int dp[n][MAX];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++)
		dp[n-1][i]=tri[n-1][i];

	for(int i=n-2;i>=0;i--)
		for(int j=0;j<=i;j++)
			dp[i][j]= tri[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
	return dp[0][0];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int tri[n][MAX];
		memset(tri,0,sizeof(tri));
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				cin>>tri[i][j];

		cout<<minPath(tri,n)<<endl;
	}
	return 0;
}