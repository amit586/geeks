#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long dp[n+4];
		dp[0]=0;
		dp[1]=1;
		dp[2]=4;
		dp[3]=5;
		dp[4]=16;
		for(int i=2;i<=n/2+1;i++)
		{
			dp[2*i]=4*dp[i];
			dp[2*i+1]=4*dp[i]+1;
		}
		for(int i=0;i<n;i++)
			cout<<dp[i]<<" ";
		cout<<endl;
	}
	return 0;
}
