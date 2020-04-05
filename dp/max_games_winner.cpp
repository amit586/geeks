#include <bits/stdc++.h>
using namespace std;

int maxgames(int n)
{
	// if(n<=1)
	// 	return 0;
	// else if(n==2)
	// 	return 1;
	// else if(n==3)
	// 	return 2;
	// else
	// 	return 1+max(maxgames(n/2),maxgames(n-n/2));
	int dp[n]={0};
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	int i=3;
	while(dp[i-1]<=n)
	{
		dp[i]=dp[i-1]+dp[i-2];
		//cout<<"i "<<i<<" dp[i] "<<dp[i]<<endl;
		i++;
	}
	return i-4;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		cout<<maxgames(n)<<endl;
	}
	return 0;
}