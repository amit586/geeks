#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int maxPath(int cost[][MAX],int n)
{
	int dp[n][MAX];
	dp[0][0]=cost[0][0];

	 for(int i=0;i<n;i++)
	 	dp[n-1][i]=cost[n-1][i];

	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+cost[i][j];
	}
	return dp[0][0];
}

void solve()
{
	int n;
	cin>>n;
	int cost[n][MAX];
	memset(cost,0,sizeof(cost));
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			cin>>cost[i][j];
	cout<<maxPath(cost,n)<<endl;
}
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
		solve();
	return 0;
}