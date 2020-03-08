#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		long long dp[n+1];
		dp[0]=0;
		dp[1]=1;
		dp[2]=1;
		dp[3]=2;
		dp[4]=2;
		for(int i=5;i<=n;i++)
		{
			dp[i]=dp[dp[i-1]]+dp[i-dp[i-1]];
		}
		for(int i=1;i<=n;i++)
			cout<<dp[i]<<" ";
		cout<<endl;
	}
	return 0;
}