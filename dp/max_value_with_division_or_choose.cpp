#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
	int dp[n+1]={0};
	dp[1]=1;
	for(int i=0;i<=n;i++)
		dp[i] = max(i,dp[i/2]+dp[i/3]+dp[i/4]+dp[i/5]);
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		cout<<f(n)<<endl;
	}
	return 0;
}